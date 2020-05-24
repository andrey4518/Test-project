#ifndef SIGNALGENERATOR
#define SIGNALGENERATOR
#include <string>

class AppSettings;

class SignalGenerator
{
public:
    SignalGenerator(AppSettings * settings = nullptr);
    void generate_to_file_binary();
    void generate_to_file_csv();

    void setSettings(AppSettings *settings);
    AppSettings * getSettings() const;
private:
    AppSettings * _settings;
};

#endif //SIGNALGENERATOR