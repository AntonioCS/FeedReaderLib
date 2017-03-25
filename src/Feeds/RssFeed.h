#ifndef RSSFEED_H
#define RSSFEED_H

#include <unordered_map>
#include <array>
#include <vector>
#include <iostream> //using it for debuing will remove in the future
#include "XMLNode.h"

namespace AcsFeedReader {

    struct RssFeedImage {
        std::string url;
        std::string title;
        std::string link;
        std::string description;
        std::string width;
        std::string height;
    };

    struct RssFeedItem {
        std::string title;
        std::string description;
        std::string link;
        std::string category;
        std::string comments;
        std::string pubDate; //Possible change to some date format
    };

    class RssFeed {
    public:
        RssFeed(XMLNode channel);
        RssFeed::~RssFeed();        

    private:
        static const std::array<const char *, 11> attrs{
            "title",
            "description",
            "link",
            "category",
            "copyright",
            "language",
            "lastBuildDate",
            "managingEditor",
            "pubDate",
            "webMaster",
            "generator"};

        std::unordered_map<const char *, std::string> attrsValues;
        RssFeedImage image;
        std::vector<RssFeedItem> items;
    };

}
#endif /* RSSFEED_H */

