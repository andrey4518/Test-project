#ifndef APPSETTINGS
#define APPSETTINGS
#include <string>

class AppSettings
{
public:
    AppSettings();
    unsigned long size;
    unsigned long buffer_size;
    std::string prepared_filename;
    std::string processed_filename;
    void load(const std::string &filename);
    void save();
    void save(const std::string &filename);
private:
    std::string m_file;
};

#endif //APPSETTINGS