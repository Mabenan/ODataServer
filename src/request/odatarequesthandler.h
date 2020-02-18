#ifndef ODATAURLHANDLER_H
#define ODATAURLHANDLER_H

#include <QObject>
#include <ODataServer_global.h>
#include <QUrl>
#include <QUrlQuery>
#include <QVariant>
#include <model/ODataModel.h>
#include <request/ODataURLParser.h>
class ODATASERVER_EXPORT ODataRequestHandler : public QObject
{
    Q_OBJECT

public:
    enum class Method
    {
                    Unknown = 0x0000,
        Get = 0x0001,
        Put = 0x0002,
        Delete = 0x0004,
        Post = 0x0008,
        Head = 0x0010,
        Options = 0x0020,
        Patch = 0x0040,

        All = Get | Put | Delete | Post | Head | Options | Patch,

        // Include upper-case aliases for the sake of parsing from strings:
        GET = Get,
        PUT = Put,
        DELETE = Delete,
        POST = Post,
        HEAD = Head,
        OPTIONS = Options,
        PATCH = Patch

    };
        Q_ENUM(Method)
            Q_DECLARE_FLAGS(Methods, Method)
                Q_FLAG(Methods)

private:
    ODataURLParser *urlParser;
    ODataModel *model;
    QString host;
    QString base;

public:
    explicit ODataRequestHandler(QString host, QString base, QObject *parent = nullptr);

    QVariant handleRequest(QUrl url, QUrlQuery query, QVariant body, Method method);

signals:

public slots:
};

#endif // ODATAURLHANDLER_H
