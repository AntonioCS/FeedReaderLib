#include <iostream>
#include "XMLParser.h"
#include "XMLNode.h"

namespace AcsFeedReader {

    XMLParser::XMLParser() {
    }

    XMLParser::XMLParser(const char *file) : XMLParser(std::string{file}) {
    }

    XMLParser::XMLParser(const std::string file) {
        Parse(file);
    }

    XMLParser::~XMLParser() {
        if (doc) {
            xmlFreeDoc(doc);
        }
    }

    void XMLParser::Parse(const std::string file) {
        //@todo Disable libxml2 console output
        //on failure it will output messages
        //ex.: When a file does not exist: I/O warning : failed to load external entity "./Tests/feeds/123.xml" 
        doc = xmlParseFile(file.c_str());

        if (doc == nullptr) {
            throw std::runtime_error("XML document not parsed successfully");
        }

        xml_file = file;
    }

    XMLNode XMLParser::findNode(XMLNode cur, const std::string name) const noexcept {
        auto ele = cur.getChildrenNode();

        while (ele) {                         
            if (!ele.isBlank() && ele.getName() == name) {                
                return ele;
            }

            ele = ele.getNext();
        }

        return XMLNode{nullptr};
    }

}