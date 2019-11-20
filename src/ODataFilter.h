#ifndef ODATA_FILTER_H
#define ODATA_FILTER_H

#include "ODataServer_global.h"
#include <QObject>

class ODATASERVER_EXPORT ODataFilter : public QObject
{
    Q_OBJECT

public:

    ODataFilter(QObject * parent = nullptr);



};

#endif // !ODATA_FILTER_H