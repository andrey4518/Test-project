#ifndef SIGNALGENERATOR
#define SIGNALGENERATOR
#include <string>

class AppSettings;

/**
 * @brief class used for generating noised sequence
 * working according settings in passed AppSettings object
 */

class SignalGenerator
{
public:
    SignalGenerator(AppSettings * settings = nullptr);
    /**
     * @brief generates bin file
     */
    void generate_to_file_binary();
    /**
     * @brief generates csv file
     */
    void generate_to_file_csv();

    void setSettings(AppSettings *settings);
    AppSettings * getSettings() const;
private:
    AppSettings * _settings;
};

#endif //SIGNALGENERATOR