#include <vector>

#include "RssFeed.h"

namespace AcsFeedReader {

    RssFeed::RssFeed() {
    }

    RssFeed::RssFeed(XMLNode channel) {
        auto func = [this](XMLNode & node) {
            std::string nodeName{node.getName()};

            if (nodeName.compare("item") == 0) {
                this->addItem(node);

            } else if (nodeName.compare("image") == 0) {
                this->setImage(node);
            } else {
                auto attrEnd = attrs.end();
                auto i = std::find(attrs.begin(), attrEnd, nodeName);

                if (i != attrEnd) {
                    setAttr(*i, node.getContent());
                }
            }

            return true;
        };

        channel.iterateChildren(func);
    }

    RssFeed::~RssFeed() {
    }

    std::string RssFeed::getAttr(const char *key) const noexcept {
        return getAttr(std::string{key});
    }

    std::string RssFeed::getAttr(const std::string key) const noexcept {
        auto search = attrsValues.find(key);

        if (search != attrsValues.end()) {
            return search->second;
        }

        return std::string{};
    }
    /*
    int RssFeed::itemTotal() const {
        
    }*/

    void RssFeed::setAttr(const char *key, std::string value) {
        setAttr(std::string{key}, value);
    }

    void RssFeed::setAttr(const std::string key, std::string value) {
        attrsValues[key] = value;
    }

    void RssFeed::addItem(XMLNode &item) {
        items.push_back(generateItem(item));
    }

    RssFeedItem RssFeed::generateItem(XMLNode &item) const noexcept {
        RssFeedItem i;

        auto func = [&i](XMLNode & node) {
            std::string nodeName{node.getName()};

            if (nodeName.compare("title") == 0) {
                i.title = node.getContent();
            } else if (nodeName.compare("description") == 0) {
                i.title = node.getContent();
            } else if (nodeName.compare("link") == 0) {
                i.link = node.getContent();
            } else if (nodeName.compare("category") == 0) {
                i.category = node.getContent();
            } else if (nodeName.compare("comments") == 0) {
                i.comments = node.getContent();
            } else if (nodeName.compare("pubDate") == 0) {
                i.pubDate = node.getContent();
            }

            return true;
        };

        item.iterateChildren(func);

        return i;
    }

    void RssFeed::setImage(XMLNode &imageNode) {
        auto func = [this](XMLNode & node) {
            std::string nodeName{node.getName()};

            if (nodeName.compare("url") == 0) {
                this->image.url = node.getContent();
            } else if (nodeName.compare("title") == 0) {
                this->image.title = node.getContent();
            } else if (nodeName.compare("link") == 0) {
                this->image.link = node.getContent();
            } else if (nodeName.compare("description") == 0) {
                this->image.description = node.getContent();
            } else if (nodeName.compare("width") == 0) {
                this->image.width = node.getContent();
            } else if (nodeName.compare("height") == 0) {
                this->image.height = node.getContent();
            }

            return true;
        };

        imageNode.iterateChildren(func);        
    }
}