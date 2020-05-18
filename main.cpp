#include <iostream>

#include "XMLParser/XMLParser.h"
#include "MkRequest/MkRequest.h"

auto ShowTest(XMLParser &parser) -> void {
    auto [test, phys, vmx] = std::tie("test.xml", "phys.xml", "vmx1-conf.xml");

    for (auto &file_name : {test, phys, vmx}){
        parser.Init(file_name);
        parser.ShowAll();
    }
}

int main() {
    try {
        XMLParser parser;
        runos::MkRequest mk_req;

        //ShowTest(parser);
    }
    catch (const std::exception& er){
        std::cout <<er.what() << std::endl;
    }


    return 0;
}
