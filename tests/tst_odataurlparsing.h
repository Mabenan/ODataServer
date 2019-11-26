#ifndef ODATA_URL_PARSING_TEST_H
#define ODATA_URL_PARSING_TEST_H
#include <QtTest>
#include <QList>
#include <QString>
#include <request/ODataURLParser.h>

class ODataURLParsingTest : public QObject
{
    Q_OBJECT

private:
    ODataURLParser * urlParser;
public:
    ODataURLParsingTest();
    ~ODataURLParsingTest();

public:
private slots:
    void initTestCase()
    {
        this->urlParser = new ODataURLParser(this);
    }
    void encodesURLCorrect();

    void cleanupTestCase()
    {
    }
};
#endif
