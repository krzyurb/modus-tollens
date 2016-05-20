#pragma once

#include <string>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class GameData {
public:
    template<typename T>
    static T read(std::string fileName, std::string key){
        T value {};
        try
        {
            boost::property_tree::ptree pt;
            read_json("data/"+fileName+".mtd", pt);
            value = pt.get<T>(key);
        }
        catch (std::exception const&e)
        {
            std::cerr << "GameData error: " << e.what() << std::endl;
        }
        return value;
    }
};
