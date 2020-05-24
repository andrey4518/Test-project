#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include <boost/program_options.hpp>
#include "AppSettings.h"
#include "SignalGenerator.h"
#include "SignalFilter.h"

namespace po = boost::program_options;

using namespace std;

int main(int argc, char** argv) {

    //parsing options
    po::options_description desc("General options");
    string settingsFilename;
    desc.add_options()
        ("help,h","Show help")
        ("settings,s",po::value<string>(&settingsFilename),"Settings file name");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    if(vm.count("help") || !vm.size()) {
        cout << desc << "\n";
        return 1;
    }

    //loading settings from file
    AppSettings settings;
    settings.load(settingsFilename);

    //generate starting data
    SignalGenerator generator(&settings);

    cout<<"generates start"<<endl;
    auto startTime = chrono::high_resolution_clock::now();
    if(settings.mode == "bin")
        generator.generate_to_file_binary();
    else if(settings.mode == "csv")
        generator.generate_to_file_csv();
    else
        cout<<"unknown mode"<<endl;
    auto endTime = chrono::high_resolution_clock::now();
    cout<<"generates done"<<endl;
    cout<<"generation time "<<chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count()<<"\n";
    
    //filter generated data
    SignalFilter filter(&settings);

    cout<<"filter start"<<endl;
    startTime = chrono::high_resolution_clock::now();
    if(settings.mode == "bin")
        filter.filter_from_file_binary();
    else if(settings.mode == "csv")
        filter.filter_from_file_csv();
    else
        cout<<"unknown mode"<<endl;
    endTime = chrono::high_resolution_clock::now();
    cout<<"filter done"<<endl;
    cout<<"filter time "<<chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count()<<"\n";
    
    return 0;
}
