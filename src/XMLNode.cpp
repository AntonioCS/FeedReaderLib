#include "XMLNode.h"

namespace AcsFeedReader {

    std::string XMLNode::getContent() const noexcept {
        std::string data;

        xmlChar *key = xmlNodeListGetString(nptr->doc, nptr->xmlChildrenNode, 1);
        data = reinterpret_cast<char*> (key);
        xmlFree(key);

        return data;
    }

    void XMLNode::iterateChildren(std::function<bool(XMLNode&) > func) const noexcept {
        auto ele = getChildrenNode();

        while (ele) {
            if (!ele.isBlank()) {
                if (!func(ele)) {
                    break;
                }
            }
            ele = ele.getNext();
        }
    }

}