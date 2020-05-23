#include "SignalGenerator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

SignalGenerator::SignalGenerator() {}
void SignalGenerator::generate_to_file(const string& filename, 
    unsigned long size, unsigned long long buffSize)
{
    FILE* file = fopen(filename.c_str(),"wb");
    vector<double> buf;
    buf.reserve(buffSize);

    for(unsigned long long i = 0; i < size * 10; ++i)
    {
        buf.push_back(sin(i / 10.0) + rand());
        if(i % buf.capacity() == 0 && buf.size() > 0)
        {
            fwrite(&buf[0],sizeof (double),buf.size(),file);
            buf.clear();
        }
    }
    fwrite(&buf[0],sizeof (double),buf.size(),file);
    buf.clear();
    fclose(file);
}