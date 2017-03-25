#ifndef FEEDPARSER_H
#define FEEDPARSER_H

#include <string>
#include <exception> //runtime_error
#include "XMLParser.h"

namespace AcsFeedReader {

    class FeedParser {
    public:
        FeedParser(const std::string file);
        FeedParser(const FeedParser &fp) = default;
        ~FeedParser() = default;
    private:
        XMLParser xmlParser;

        bool isRss() {
            return (xmlParser.getRootElement().getName() == "channel");
        }

        bool isAtom() {
            return (xmlParser.getRootElement().getName() == "feed");
        }
    };
}
#endif /* FEEDPARSER_H */

