#ifndef RSSFEED_H
#define RSSFEED_H

#include <unordered_map>
#include <array>
#include <string>
#include <vector>
#include <algorithm> //find
#include <iostream> //using it for debuing will remove in the future
#include "../XMLNode.h"

namespace AcsFeedReader {

        /*
        enum class RssAttribute {
            title,
            description,
            link,
            category,
            copyright,
            language,
            lastBuildDate,
            managingEditor,
            pubDate,
            webMaster,
            generator
        };
     */
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
        RssFeed();
        RssFeed(XMLNode channel);
        ~RssFeed();

        std::string getAttr(const char *);
        std::string getAttr(const std::string);

    private:
        const std::array<std::string, 11> attrs{
            std::string{"title"},
            std::string{"description"},
            std::string{"link"},
            std::string{"category"},
            std::string{"copyright"},
            std::string{"language"},
            std::string{"lastBuildDate"},
            std::string{"managingEditor"},
            std::string{"pubDate"},
            std::string{"webMaster"},
            std::string{"generator"}
        };

        std::unordered_map<std::string, std::string> attrsValues;
        RssFeedImage image;
        std::vector<RssFeedItem> items;

        void setAttr(const char *, std::string);
        void setAttr(const std::string, std::string);
    };

}
#endif /* RSSFEED_H */

