#ifndef ODATAURLPARSER_H
#define ODATAURLPARSER_H

#include <QObject>
#include <ODataServer_global.h>

class ODATASERVER_EXPORT ODataURLParser : public QObject
{
    Q_OBJECT

public:
    explicit ODataURLParser(QObject *parent = nullptr);

private:
    // WebInterface interface
public:
     QStringList splitUpURL(QUrl url);
};

#endif // ODATAURLPARSER_H
