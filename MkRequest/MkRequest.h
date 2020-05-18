//
// Created by Виктор Задябин on 18.05.2020.
//

#ifndef XML_PARSING_MKREQUEST_H
#define XML_PARSING_MKREQUEST_H


#pragma once

#include <set>
#include <optional>
#include "pugixml/pugixml.hpp"
#include <libyang/libyang.h>

#include "XMLParser/XMLParser.h"


namespace runos {
using interfaces = std::set<uint32_t>;

class MkRequest {
private:
    auto SendRequest(const std::string &&xpath, const std::string &&val) -> std::string;
public:
    MkRequest() = default;
    ~MkRequest() = default;
    auto GetInterfaces(uint64_t dpid) -> interfaces;
    auto GetInterfaceInfo() -> void;
    auto GetNeighbours() -> void;
    auto GetSubscribe(uint64_t dpid) -> void;
    auto GetVlans(uint64_t dpid) -> void;
    auto CreateVlan(uint64_t dpid) -> void;
    auto DeleteVlan() -> void;

};

}// namespace runos



#endif //XML_PARSING_MKREQUEST_H
