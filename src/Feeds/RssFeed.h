#ifndef RSSFEED_H
#define RSSFEED_H

#include <unordered_map>
#include <array>
#include <string>
#include <vector>
#include <algorithm> //find
#include <iostream> //using it for debugging will remove in the future
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
        std::string pubDate;
    };

    class RssFeed {
    public:
        RssFeed();
        RssFeed(XMLNode channel);
        ~RssFeed();

        std::string getAttr(const char *) const noexcept;
        std::string getAttr(const std::string) const noexcept;

        int itemTotal() const noexcept {
            return static_cast<int>(items.size());
        }
        
        RssFeedItem getItem(int n) const {
            //return items.at(static_cast<std::vector<::size_t>(n));
            return RssFeedItem{items.at(n)};
        }

    private:
        const std::array<std::string, 12> attrs{
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
            std::string{"generator"},
            std::string{"docs"}};

        std::unordered_map<std::string, std::string> attrsValues;
        RssFeedImage image;
        std::vector<RssFeedItem> items;

        void setAttr(const char *, std::string);
        void setAttr(const std::string, std::string);

        void addItem(XMLNode &);
        void setImage(XMLNode &);

        RssFeedItem generateItem(XMLNode &) const noexcept;
    };

}
#endif /* RSSFEED_H */

