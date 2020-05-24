#include "SignalGenerator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "AppSettings.h"

using namespace std;

SignalGenerator::SignalGenerator(AppSettings * settings) : _settings(settings)
{}

void SignalGenerator::generate_to_file_binary()
{
    FILE* file = fopen(_settings->prepared_filename.c_str(),"wb");
    vector<double> buf;
    buf.reserve(_settings->buffer_size);
    default_random_engine generator;
    generator.seed( chrono::system_clock::now().time_since_epoch().count() );
    uniform_real_distribution<double> noise(_settings->min_noise, _settings->max_noise);
    unsigned long long i = 0;
    for(long double x = 0; x < _settings->size; x += _settings->generation_step)
    {
        buf.push_back(sin(x) + noise(generator));
        if(i % buf.capacity() == 0 && buf.size() > 0)
        {
            fwrite(&buf[0],sizeof (double),buf.size(),file);
            buf.clear();
        }
        ++i;
    }
    fwrite(&buf[0],sizeof (double),buf.size(),file);
    buf.clear();
    fclose(file);
}

void SignalGenerator::generate_to_file_csv()
{
    ofstream file(_settings->prepared_filename, ofstream::out | ofstream::trunc);
    if(!file.good())
    {
        cout<<"reading: error ocured\n";
        cout<<"error "<<file.rdstate();
    }

    char buffer[_settings->buffer_size];
    file.rdbuf()->pubsetbuf(buffer, _settings->buffer_size);
    

    default_random_engine generator;
    generator.seed( chrono::system_clock::now().time_since_epoch().count() );
    uniform_real_distribution<double> noise(_settings->min_noise, _settings->max_noise);

    double t;
    for(long double x = 0; x < _settings->size; x += _settings->generation_step)
    {
        t = sin(x) + noise(generator);
        file<<t<<"\n";
    }
    file.flush();
}