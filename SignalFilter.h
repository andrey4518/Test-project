#ifndef SIGNALFILTER
#define SIGNALFILTER
#include <string>

class AppSettings;

class SignalFilter
{
public:
    SignalFilter(AppSettings *settings = nullptr);
    void filter_from_file_binary();
    void filter_from_file_csv();
    void setSettings(AppSettings *settings);
    AppSettings * getSettings() const;
private:
    AppSettings * _settings;
};

#endif //SIGNALFILTER