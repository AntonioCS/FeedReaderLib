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
            }
            
            return true;
        };

        channel.iterateChildren(func);
    }

    RssFeed::~RssFeed() {
    }

    std::string RssFeed::getAttr(const char *key) {
        return getAttr(std::string{key});
    }

    std::string RssFeed::getAttr(const std::string key) {
        auto search = attrsValues.find(key);

        if (search != attrsValues.end()) {
            return search->second;
        }
        
        return std::string{};
    }

    void RssFeed::setAttr(const char *key, std::string value) {
        setAttr(std::string{key}, value);
    }
    void RssFeed::setAttr(const std::string key, std::string value) {
        attrsValues[key] = value;
    }
}