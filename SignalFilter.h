#ifndef SIGNALFILTER
#define SIGNALFILTER
#include <string>

class AppSettings;

/**
 * @brief class for applying Kalman filter to input sequnce
 * working according settings in passed AppSettings object
 */

class SignalFilter
{
public:
    SignalFilter(AppSettings *settings = nullptr);
    /**
     * @brief filter binary sequence
     */
    void filter_from_file_binary();
    /**
     * @brief filter csv sequence
     */
    void filter_from_file_csv();

    void setSettings(AppSettings *settings);
    AppSettings * getSettings() const;
private:
    AppSettings * _settings;
};

#endif //SIGNALFILTER