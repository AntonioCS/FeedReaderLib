#ifndef ATOMFEED_H
#define ATOMFEED_H

#include "Feed.h"

namespace AcsFeedReader {
    class AtomFeed : public Feed {
    public:
        AtomFeed();
        AtomFeed(const AtomFeed& orig);
        virtual ~AtomFeed();
    private:

    };
}
#endif /* ATOMFEED_H */

