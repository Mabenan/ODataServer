#include <tst_odataurlparsing.h>
// add necessary includes here


ODataURLParsingTest::ODataURLParsingTest()
{
	this->urlParser = nullptr;
}

ODataURLParsingTest::~ODataURLParsingTest()
{
}

void ODataURLParsingTest::encodesURLCorrect()
{
    QStringList segments = this->urlParser->splitUpURL(QUrl("http://host/service/People('O''Neil')"));
    QVERIFY(segments.count() == 1);
    QVERIFY(segments.contains("People('O''Neil')"));
    segments = this->urlParser->splitUpURL(QUrl("http://host/service/People(%27O%27%27Neil%27)"));
    QVERIFY(segments.count() == 1);
    QVERIFY(segments.contains("People('O''Neil')"));
    segments = this->urlParser->splitUpURL(QUrl("http://host/service/People%28%27O%27%27Neil%27%29"));
    QVERIFY(segments.count() == 1);
    QVERIFY(segments.contains("People('O''Neil')"));
    segments = this->urlParser->splitUpURL(QUrl("http://host/service/Categories('Smartphone%2FTablet')"));
    QVERIFY(segments.count() == 1);
    QVERIFY(segments.contains("Categories('Smartphone/Tablet')"));
}

#include "tst_odataurlparsing.moc"
