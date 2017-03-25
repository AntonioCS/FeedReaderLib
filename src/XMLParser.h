#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <exception> //runtime_error
#include <string>
#include <libxml/parser.h>
#include "XMLNode.h"

namespace AcsFeedReader {

    class XMLParser {
    public:
        XMLParser();
        XMLParser(const char *file);
        XMLParser(const std::string file);
        //copy construct
        XMLParser(const XMLParser &orig) = default;

        ~XMLParser();

        void Parse(const std::string file);

        XMLNode getRootElement() const noexcept {
            return doc ? XMLNode{xmlDocGetRootElement(doc)} : XMLNode{nullptr};
        }

        xmlDocPtr getDocument() const noexcept {
            return doc ? doc : nullptr;
        }

        XMLNode findNode(const char *name) const noexcept {
            return findNode(std::string{name});
        }

        XMLNode findNode(const std::string name) const noexcept {
            return findNode(getRootElement(), name);
        }

        XMLNode findNode(XMLNode cur, const std::string name) const noexcept;
    private:
        xmlDocPtr doc = nullptr;
        xmlNodePtr cur = nullptr;
        std::string xml_file;
    };


}
#endif /* XMLPARSER_H */

