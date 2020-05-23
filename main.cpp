#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include "AppSettings.h"
#include "SignalGenerator.h"
#include <boost/program_options.hpp>

namespace po = boost::program_options;

using namespace std;

int main(int argc, char** argv) {

    po::options_description desc("General options");
    string settingsFilename;
    desc.add_options()
        ("help,h","Show help")
        ("settings,s",po::value<string>(&settingsFilename),"Settings file name");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    if(vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }
    if(!vm.size())
    {
        settingsFilename = "/media/win/VSCode_projects/CPP/Test-project/Test-project/settings.json";
    }

    AppSettings settings;
    settings.load(settingsFilename);
    cout<<settings.size<<"  "<<settings.buffer_size<<endl;

    srand(time(nullptr));

    SignalGenerator generator;

    cout<<"generates start"<<endl;
    auto startTime = chrono::high_resolution_clock::now();
    generator.generate_to_file(settings.prepared_filename,settings.size,settings.buffer_size);
    auto endTime = chrono::high_resolution_clock::now();
    cout<<"time "<<chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count()<<"\n";
    cout<<"generates done\n";

    return 0;
}
