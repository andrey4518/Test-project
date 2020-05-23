#include "AppSettings.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

namespace pt = boost::property_tree;

AppSettings::AppSettings() : size(0), buffer_size(0) {}

void AppSettings::load(const std::string &filename)
{
    m_file = filename;
    pt::ptree tree;
    pt::read_json(filename,tree);
    size = tree.get<unsigned long>("data_size");
    buffer_size = tree.get<unsigned long>("buffer_size");
    prepared_filename = tree.get<std::string>("prepared_filename");
    processed_filename = tree.get<std::string>("processed_filename");
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
}