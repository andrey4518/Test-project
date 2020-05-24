#ifndef SIGNALFILTER
#define SIGNALFILTER
#include <string>

class AppSettings;

/*
    class for applying Kalman filter to input sequnce
*/

class SignalFilter
{
public:
    SignalFilter(AppSettings *settings = nullptr);
    //filter binary sequence
    void filter_from_file_binary();
    //filter csv sequence
    void filter_from_file_csv();

    void setSettings(AppSettings *settings);
    AppSettings * getSettings() const;
private:
    AppSettings * _settings;
};

#endif //SIGNALFILTER