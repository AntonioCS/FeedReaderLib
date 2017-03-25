#include "RssFeed.h"

namespace AcsFeedReader {

    RssFeed::RssFeed(XMLNode channel) {
        auto func = [this](XMLNode & node) {
            auto nodeType{node.getName()};
            auto attrEnd = RssFeed::attrs.end();
            auto i = std::find(RssFeed::attrs.begin(), attrEnd, nodeType);

            if (i != attrEnd) {
                std::cout << "Attr:" << *i << " name:" << node.getName() << " Value:" << node.getContent() << '\n';
            }
            /*
            if (node.getName() == "title") {
                this->title = node.getContent();
            }*/
            return true;
        };

        channel.iterateChildren(func);
    }

    RssFeed::RssFeed(const RssFeed& orig) {
    }

    RssFeed::~RssFeed() {
    }
}