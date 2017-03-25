#include "FeedParser.h"

namespace AcsFeedReader {

    FeedParser::FeedParser(const std::string file) {
        xmlParser.Parse(file);

        if (isRss()) {
            RssFeed rFeed{xmlParser.getRootElement()};
        }
        else if (isAtom()) {
            
        }
        else {
            throw std::runtime_error("Invalid XML feed type");
        }
    }
}
