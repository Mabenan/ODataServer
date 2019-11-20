#ifndef ODATA_ENTITYTEST_H
#define ODATA_ENTITYTEST_H

#include <QObject>
#include <model/ODataEntity.h>

class ODataTestEntity : public ODataEntity
{
    Q_OBJECT

public:

    ODataTestEntity(QObject * parent = nullptr);



};

#endif // !ODATA_ENTITYTEST_H
