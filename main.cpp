#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;

void generateFile(const string& filename, unsigned long size)
{
    ofstream file(filename, ofstream::out | ofstream::binary | ofstream::trunc);
    if(!file.good())
    {
        cout<<"writing: error ocured\n";
        cout<<"error "<<file.rdstate()<<"\n";
    }
    double t;
    for(unsigned long long i = 0; i < size * 10; ++i)
    {
        t = sin(i / 10.0) + rand();
        file.write(reinterpret_cast<char *>(&t),sizeof(double));
    }
    file.flush();
}

void generateFile2(const string& filename, unsigned long size, unsigned long long buffSize)
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

int main(int, char**) {
    srand(time(nullptr));
    cout<<"start\n";
    string filename = "/home/andrey/test_data/data.in";
    unsigned long size = 10000000;
    cout<<"using file: "<<filename<<"\n";

    cout<<"generates start\n";
    auto startTime = chrono::high_resolution_clock::now();
    generateFile(filename,size);
    auto endTime = chrono::high_resolution_clock::now();
    cout<<"time "<<chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count()<<"\n";
    cout<<"generates done\n";

    cout<<"generates start type 2 buff 80000\n";
    startTime = chrono::high_resolution_clock::now();
    generateFile2(filename,size,80000);
    endTime = chrono::high_resolution_clock::now();
    cout<<"time "<<chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count()<<"\n";
    cout<<"generates done\n";
}
