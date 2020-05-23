#ifndef SIGNLAGENERATOR
#define SIGNLAGENERATOR
#include <string>

class SignalGenerator
{
public:
    SignalGenerator();
    void generate_to_file(const std::string& filename, 
    unsigned long size, unsigned long long buffSize);
};

#endif //SIGNLAGENERATOR