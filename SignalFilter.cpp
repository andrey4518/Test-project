#include "SignalFilter.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "AppSettings.h"
#include "Kalman.h"
#include "Utilities.h"

using namespace std;

SignalFilter::SignalFilter(AppSettings *settings) : _settings(settings) {}

void SignalFilter::filter_from_file_binary()
{
    if(!_settings)
    {
        cout<<"can't run filter without settings";
        return;
    }
    FILE* ofile = fopen(_settings->processed_filename.c_str(),"wb");
    FILE* ifile = fopen(_settings->prepared_filename.c_str(),"rb");
    Kalman kalmanX;
    kalmanX.setAngle(0);
    double buf[_settings->buffer_size];
    int count;
    while(true)
    {
        count = fread(&buf[0],sizeof (double), _settings->buffer_size, ifile);
        if(!count)
            break;
        for(int i = 0; i < count; ++i)
        {
            buf[i] = kalmanX.getAngle(buf[i],_settings->generation_step,_settings->generation_step);
        }
        fwrite(&buf[0],sizeof (double),count,ofile);
    }
    fclose(ofile);
    fclose(ifile);
}

void SignalFilter::filter_from_file_csv()
{
    if(!_settings)
    {
        cout<<"can't run filter without settings";
        return;
    }

    ifstream ifile(_settings->prepared_filename, ifstream::in);
    if(!ifile.good())
    {
        cout<<"can't read input file"<<endl;
        return;
    }

    ofstream ofile(_settings->processed_filename, ofstream::out | ofstream::trunc);
    if(!ofile.good())
    {
        cout<<"can't open output file"<<endl;
        return;
    }

    char buffer[_settings->buffer_size];
    ofile.rdbuf()->pubsetbuf(buffer, _settings->buffer_size);

    Kalman kalmanX;

    kalmanX.setAngle(0);

    string s;
    double t = 0;
    while(!ifile.eof())
    {
        getline(ifile,s);
        
        if(!s.empty())
        {
            s = s.substr(1,s.length() - 2);
            utils::replace(s,",",".");
            t = stod(s);
            t = kalmanX.getAngle(t,_settings->generation_step,_settings->generation_step);
            s = to_string(t);
            utils::replace(s, ".", ",");
            s = "\"" + s + "\"";

            ofile<<s<<"\n";
        }
    }
    ofile.flush();
}