#include "RssFeed.h"

namespace AcsFeedReader {

    RssFeed::RssFeed() {        
    }
    
    RssFeed::RssFeed(XMLNode channel) {
        auto func = [this](XMLNode & node) {
            auto nodeType{node.getName()};
            auto attrEnd = attrs.end();
            auto i = std::find(attrs.begin(), attrEnd, nodeType);

            if (i != attrEnd) {
                setAttr(*i, node.getContent());
                //std::cout << "Attr:" << *i << " name:" << node.getName() << " Value:" << node.getContent() << '\n';
            }
            /*
            if (node.getName() == "title") {
                this->title = node.getContent();
            }*/
            return true;
        };

        channel.iterateChildren(func);
    }

    RssFeed::~RssFeed() {
    }

    std::string *RssFeed::getAttr(const char *key) {
        auto search = attrsValues.find(key);

        if (search != attrsValues.end()) {
            return &(search->second);
        }
        
        return nullptr;

    }

    void RssFeed::setAttr(const char *key, std::string value) {
        attrsValues[key] = value;
    }
}