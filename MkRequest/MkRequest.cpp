#include "MkRequest.h"
//#include <libnetconf.h>
#include "pugixml/pugixml.hpp"

#include "trim.h"
#include <algorithm>

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
}

auto MkRequest::DeleteVlan() -> void {

}

auto MkRequest::SendRequest(const std::string &&xpath, const std::string &&val) -> std::string {
    return std::string();
}


}// namespace runos