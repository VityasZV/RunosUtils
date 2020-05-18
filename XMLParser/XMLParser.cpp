//
// Created by Виктор Задябин on 18.05.2020.
//

#include "XMLParser.h"
#include <iostream>
#include "trim.h"

using namespace trim;
struct Config {

};

auto XMLParser::ShowAll() -> void {
    Show(root);
}

auto XMLParser::Show(pugi::xml_node node) -> void {
    static int i = 0;
    std::cout << i++ << " ";
    std::cout << node.name() << " value{v=" << node.value() <<"} atrs={";
    for (auto atr : node.attributes()){
        std::cout << atr.as_string() << ", ";
    }
    std::cout << "}" << std::endl;
    for (auto c : node.children()){
        Show(c);
    }
    --i;
}

auto XMLParser::VMXConfigParse() -> Config {
    return Config();
}

auto XMLParser::GetInterfaceSpeed(pugi::xml_node node) -> uint32_t {
    auto phys_interface = node.select_node("rpc-reply/interface-information/physical-interface");
    auto speed = phys_interface.node().child("speed").child_value();
    std::cout << "answer of get_interface_speed: ";
    std::cout << trim_copy(speed) << std::endl;
    auto speed_str = trim_copy(speed);
    return std::stoi(std::string(speed_str.begin(), std::prev(speed_str.end(),4))); //cutting last 4 chars that equal to mbps
}

auto XMLParser::GetInterfaceName(pugi::xml_node node) -> std::string {
    auto log_interface = node.select_node("rpc-reply/interface-information/logical-interface");
    std::cout << "answer of get_interface_name: ";
    //show(interface.node());
    auto result = log_interface.node().child("name").child_value();
    std::cout << trim_copy(result) << std::endl;
    return trim_copy(result);
}

auto XMLParser::Init(const std::string &&filename) -> void {
    pugi::xml_parse_result result = doc.load_file(filename.data());
    if (!result) {
        std::cout << "cant parse this xml" << std::endl;
        throw std::runtime_error("cant parse this xml");
    }
    root = doc.root();
    //pugi::xml_parse_result result = doc.load_buffer(text.data(), text.size());

}
