#include "AppSettings.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

namespace pt = boost::property_tree;

AppSettings::AppSettings() : size(0), buffer_size(0), min_noise(0), 
    max_noise(1), generation_step(0.1)
{}

void AppSettings::load(const std::string &filename)
{
    m_file = filename;
    pt::ptree tree;
    pt::read_json(filename,tree);
    size = tree.get<unsigned long>("data_size");
    buffer_size = tree.get<unsigned long>("buffer_size");
    prepared_filename = tree.get<std::string>("prepared_filename");
    processed_filename = tree.get<std::string>("processed_filename");
    min_noise = tree.get<double>("min_noise");
    max_noise = tree.get<double>("max_noise");
    generation_step = tree.get<double>("generation_step");
    mode = tree.get<std::string>("mode");
}

void AppSettings::save()
{
    save(m_file);
}

void AppSettings::save(const std::string &filename)
{
    m_file = filename;
    pt::ptree tree;
    tree.put("data_size",size);
    tree.put("buffer_size",buffer_size);
    tree.put("prepared_filename",prepared_filename);
    tree.put("processed_filename",processed_filename);
    tree.put("min_noise",prepared_filename);
    tree.put("max_noise",processed_filename);
    tree.put("max_noise",generation_step);
    tree.put("mode",mode);
    pt::write_json(m_file,tree);
}