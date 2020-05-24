#include "MkRequest.h"
//#include <libnetconf.h>
#include "pugixml/pugixml.hpp"

#include "trim.h"
#include <algorithm>
#include <iostream>
#include <boost/format.hpp>

namespace {

void create_sub_interface(){
    pugi::xml_document doc;
    int vlan_id = 123, x = 2;
    auto request = (boost::format ( "<configuration>\n"
                                    "  <interfaces>\n"
                                    "    <interface>\n"
                                    "                    <name>ge-0/0/%2%</name>\n"
                                    "                    <vlan-tagging/>\n"
                                    "                    <unit>\n"
                                    "                        <name>%1%</name>\n"
                                    "                        <vlan-id>%1%</vlan-id>\n"
                                    "                        <family>\n"
                                    "                            <iso>       \n"
                                    "                            </iso>\n"
                                    "                        </family>\n"
                                    "                    </unit>\n"
                                    "                </interface>"
                                    "  </interfaces>\n"
                                    "</configuration>") % vlan_id % x).str();
    pugi::xml_parse_result result = doc.load_buffer(request.data(), request.size());
    if (!result) std::cout << "sub failed";
    XMLParser::Show(doc.root());
    std::cout <<std::endl;

}

void set_policer(){
    pugi::xml_document doc;
    int id = 123, burst_size_limit=50, bandwidth_limit = 1;
    auto source_address = "123.123.123.123";
    auto request = (boost::format ("<configuration> <firewall>\n"
                                   "                <policer>\n"
                                   "                    <name>out-%1%-policer</name>\n"
                                   "                    <if-exceeding>\n"
                                   "                        <bandwidth-limit>%2%m</bandwidth-limit>\n"
                                   "                        <burst-size-limit>%3%k</burst-size-limit>\n"
                                   "                    </if-exceeding>\n"
                                   "                    <then>\n"
                                   "                        <discard/>\n"
                                   "                    </then>\n"
                                   "                </policer>\n"
                                   "            </firewall> </configuration>") % id % bandwidth_limit % burst_size_limit).str();
    pugi::xml_parse_result result = doc.load_buffer(request.data(), request.size());
    if (!result) std::cout << "policer failed" <<std::endl;
    XMLParser::Show(doc.root());
    std::cout <<std::endl;
}



void set_filter(){
    pugi::xml_document doc;
    int id = 123, burst_size_limit=50, x = 2;
    auto source_address = "123.123.123.123";
    auto next_interface = (boost::format("ge-0/0/%2%.%1%") % id % x).str();
    auto request = (boost::format ("<configuration> <firewall>\n"
                                   "                <filter>\n"
                                   "                    <name>out-filter</name>\n"
                                   "                    <term>\n"
                                   "                        <name>out-%1%-term</name>\n"
                                   "                        <from>\n"
                                   "                            <source-address>\n"
                                   "                                <name>%2%/32</name>\n"
                                   "                            </source-address>\n"
                                   "                        </from>\n"
                                   "                        <then>\n"
                                   "                            <policer>out-123-policer</policer>\n"
                                   "                            <next-interface>\n"
                                   "                                <interface-name>%3%</interface-name>\n"
                                   "                            </next-interface>\n"
                                   "                        </then>\n"
                                   "                    </term>\n"
                                   "                </filter>\n"
                                   "            </firewall> </configuration>") % id % source_address % next_interface).str();
    pugi::xml_parse_result result = doc.load_buffer(request.data(), request.size());
    if (!result) std::cout << "filter failed" <<std::endl;
    XMLParser::Show(doc.root());
    std::cout <<std::endl;
}

void last(){
    pugi::xml_document doc;
    int id = 0, s = 3;
    auto request = (boost::format ("<configuration>\n"
                                   "  <interfaces>\n"
                                   "    <interface>\n"
                                   "                    <name>ge-0/0/%2%</name>\n"
                                   "                    <unit>\n"
                                   "                        <name>%1%</name>\n"
                                   "                        <family>\n"
                                   "                            <inet>\n"
                                   "                                <filter>\n"
                                   "                                    <input>\n"
                                   "                                        <filter-name>out-filter</filter-name>\n"
                                   "                                    </input>\n"
                                   "                                </filter>\n"
                                   "                            </inet>\n"
                                   "                        </family>\n"
                                   "                    </unit>\n"
                                   "                </interface>\n"
                                   "  </interfaces>\n"
                                   "</configuration>") % id % s).str();
    pugi::xml_parse_result result = doc.load_buffer(request.data(), request.size());
    if (!result) std::cout << "last failed";
    XMLParser::Show(doc.root());
    std::cout <<std::endl;

}
}

namespace runos {

auto MkRequest::GetInterfaces(uint64_t dpid) -> interfaces {
    //Getting dpid of switch -> returning its ports
    return std::set<uint32_t>();
}
auto MkRequest::GetInterfaceInfo() -> void {
    //TODO - make a structure for interface - use it for something
    //right now we need only identificators of switches and ports.
    //
}
auto MkRequest::GetNeighbours() -> void {

}

auto MkRequest::GetSubscribe(uint64_t dpid) -> void {
    //Get subscription on events from switch"
}


auto MkRequest::GetVlans(uint64_t dpid) -> void {
    /*
        having dpid of switch
        returning its vlans - dont know how exactly
    */
}

auto MkRequest::CreateVlan(uint64_t dpid) -> void {
    /*
        having dpid of switch
        creating vlan rule?
    */
    create_sub_interface();
    set_policer();
    set_filter();
    last();

}

auto MkRequest::DeleteVlan() -> void {

}

auto MkRequest::SendRequest(const std::string &&xpath, const std::string &&val) -> std::string {
    return std::string();
}


}// namespace runos