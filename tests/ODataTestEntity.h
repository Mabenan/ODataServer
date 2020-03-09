#ifndef ODATA_ENTITYTEST_H
#define ODATA_ENTITYTEST_H

#include <QObject>
#include <model/ODataEntity.h>

class ODataTestEntity : public ODataEntity
{

public:

	virtual void deleteEntity() const;
	virtual void update() const;
	virtual void insert() const;
	virtual void get(QMap<QString, QVariant> keys, QUrlQuery query);
	virtual ODataEntity* clone() const;
    ODataTestEntity();
    ODataTestEntity(const ODataTestEntity &oDataTestEntity);
};

#endif // !ODATA_ENTITYTEST_H
