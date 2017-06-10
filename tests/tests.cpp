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
/*
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
    REQUIRE(rss.getAttr("description").compare("RSS is a fascinating technology. The uses for RSS are expanding daily. Take a closer look at how various industries are using the benefits of RSS in their businesses.") == 0);
    REQUIRE(rss.getAttr("link").compare("http://www.feedforall.com/industry-solutions.htm") == 0);
    REQUIRE(rss.getAttr("category").compare("Computers/Software/Internet/Site Management/Content Management") == 0);
    REQUIRE(rss.getAttr("copyright").compare("Copyright 2004 NotePage, Inc.") == 0);
    REQUIRE(rss.getAttr("docs").compare("http://blogs.law.harvard.edu/tech/rss") == 0);
    REQUIRE(rss.getAttr("language").compare("en-us") == 0);
    REQUIRE(rss.getAttr("lastBuildDate").compare("Tue, 19 Oct 2004 13:39:14 -0400") == 0);
    REQUIRE(rss.getAttr("managingEditor").compare("marketing@feedforall.com") == 0);
    REQUIRE(rss.getAttr("pubDate").compare("Tue, 19 Oct 2004 13:38:55 -0400") == 0);
    REQUIRE(rss.getAttr("webMaster").compare("webmaster@feedforall.com") == 0);
    REQUIRE(rss.getAttr("generator").compare("FeedForAll Beta1 (0.0.1.8)") == 0);
    
    REQUIRE(rss.itemTotal() == 9);

    AcsFeedReader::RssFeedItem x =  rss.getItem(0);
}
*/