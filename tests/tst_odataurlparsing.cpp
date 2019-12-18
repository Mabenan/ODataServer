
#include "gtest/gtest.h"
#include <QList>
#include <QString>
#include <QUrl>
#include <request/ODataURLParser.h>
TEST(ODataURLParsingTest, encodesURLCorrect)
{
	ODataURLParser * urlParser = new ODataURLParser();
    QStringList segments = urlParser->splitUpURL(QUrl("http://host/service/People('O''Neil')"));
    EXPECT_TRUE(segments.count() == 1);
    EXPECT_TRUE(segments.contains("People('O''Neil')"));
    segments = urlParser->splitUpURL(QUrl("http://host/service/People(%27O%27%27Neil%27)"));
    EXPECT_TRUE(segments.count() == 1);
    EXPECT_TRUE(segments.contains("People('O''Neil')"));
    segments = urlParser->splitUpURL(QUrl("http://host/service/People%28%27O%27%27Neil%27%29"));
    EXPECT_TRUE(segments.count() == 1);
    EXPECT_TRUE(segments.contains("People('O''Neil')"));
    segments = urlParser->splitUpURL(QUrl("http://host/service/Categories('Smartphone%2FTablet')"));
    EXPECT_TRUE(segments.count() == 1);
    EXPECT_TRUE(segments.contains("Categories('Smartphone/Tablet')"));
}
