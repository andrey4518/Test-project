#ifndef APPSETTINGS
#define APPSETTINGS
#include <string>

/**
 * @brief class containing all application settings
 */

class AppSettings
{
public:
    AppSettings();
    /**
     * @brief size of generated sequence
     */
    unsigned long size;
    /**
     * @brief size of buffer used in generation and filtering
     */
    unsigned long buffer_size;
    /**
     * @brief filename for generated sequence
     */
    std::string prepared_filename;
    /**
     * @brief filename for filtered sequence
     */
    std::string processed_filename;
    /**
     * @brief minimum value of noise used in generation
     */
    double min_noise;
    /**
     * @brief maximum value of noise used in generation
     */
    double max_noise;
    /**
     * @brief step size which is taken from 0 to sequence size
     */
    double generation_step;
    /**
     * @brief mode of work
     * bin for generating binary files
     * csv for gnerating csv files
     */
    std::string mode;
    /**
     * @brief loads settings from file
     * 
     * @param filename 
     */
    void load(const std::string &filename);
    /**
     * @brief saves settings to last destination
     */
    void save();
    /**
     * @brief saves settings to file
     * 
     * @param filename 
     */
    void save(const std::string &filename);
private:
    std::string m_file;
};

#endif //APPSETTINGS