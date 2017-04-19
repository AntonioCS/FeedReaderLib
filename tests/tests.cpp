#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include <string>
#include <iostream>
#include <typeinfo>
#include "../src/XMLParser.h"
#include "../src/XMLNode.h"
#include "../src/Feeds/RssFeed.h"

namespace {
    const char *file = "./tests/feeds/rss2.0.xml";
    const char *fake_file = "./tests/feeds/123.xml";
}

TEST_CASE("XML document created", "[feedParser]") {
    REQUIRE_NOTHROW(AcsFeedReader::XMLParser{file});
    REQUIRE_THROWS(AcsFeedReader::XMLParser{fake_file});

    AcsFeedReader::XMLParser xmlParser;
    REQUIRE_NOTHROW(xmlParser.Parse(file));

    AcsFeedReader::XMLNode channelNode = xmlParser.findNode("channel");

    SECTION("XMLNode findNode - RSS2.0") {
        REQUIRE(channelNode);
        AcsFeedReader::XMLNode doesnoexist = xmlParser.findNode("channel123");
        REQUIRE_FALSE(doesnoexist);
    }

    SECTION("XMLNode iterate children - RSS2.0") {
        int nodeCount{0};
        auto func = [&nodeCount](auto &node) {
            nodeCount++;
            return true;
        };
        channelNode.iterateChildren(func);

        REQUIRE(nodeCount == 22);
    }
}

TEST_CASE("Fill RSS2.0 object", "[rss2.0]") {
    AcsFeedReader::XMLParser xmlParser;
    xmlParser.Parse(file);

    AcsFeedReader::XMLNode channelNode = xmlParser.findNode("channel");
    AcsFeedReader::RssFeed rss{channelNode};

    REQUIRE(rss.getAttr("title").compare("FeedForAll Sample Feed") == 0);
}
