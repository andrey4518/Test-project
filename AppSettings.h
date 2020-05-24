#ifndef APPSETTINGS
#define APPSETTINGS
#include <string>

/*
    class containing all application settings
*/

class AppSettings
{
public:
    AppSettings();
    //size of generated sequence
    unsigned long size;
    //size of buffer used in generation and filtering
    unsigned long buffer_size;
    //filename for generated sequence
    std::string prepared_filename;
    //filename for filtered sequence
    std::string processed_filename;
    //minimum value of noise used in generation
    double min_noise;
    //maximum value of noise used in generation
    double max_noise;
    //step size which is taken from 0 to sequence size
    double generation_step;
    //mode of work
    //bin for generating binary files
    //csv for gnerating csv files
    std::string mode;
    //loads settings from file
    void load(const std::string &filename);
    //saves settings to last destination
    void save();
    //saves settings to file
    void save(const std::string &filename);
private:
    std::string m_file;
};

#endif //APPSETTINGS