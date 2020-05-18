//
// Created by Виктор Задябин on 18.05.2020.
//

#ifndef XML_PARSING_XMLPARSER_H
#define XML_PARSING_XMLPARSER_H

#include <optional>
#include "pugixml/pugixml.hpp"

struct Config; // Config struct that could be used both for getting some fields of config

class XMLParser {
private:
    pugi::xml_document doc;
    pugi::xml_node root;
public:
    XMLParser() = default;
    ~XMLParser() = default;
    auto Init(const std::string &&filename) -> void;

    auto ShowAll() -> void;
    auto Show(pugi::xml_node node) -> void;
    auto VMXConfigParse() -> Config;
    auto GetInterfaceSpeed(pugi::xml_node node) -> uint32_t;
    auto GetInterfaceName(pugi::xml_node node) -> std::string;


};


#endif //XML_PARSING_XMLPARSER_H
