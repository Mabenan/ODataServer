#ifndef ODATA_ENTITYTEST_H
#define ODATA_ENTITYTEST_H

#include <QObject>
#include <model/ODataEntity.h>

class ODataTestEntity : public ODataEntity
{

public:

	virtual void deleteEntity(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const;
	virtual void update(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const;
	virtual void insert(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head) const;
	virtual void get(QMap<QString, QVariant> keys, QUrlQuery query, QVariantMap head);
	virtual ODataEntity* clone() const;
    ODataTestEntity();
    ODataTestEntity(const ODataTestEntity &oDataTestEntity);
};

#endif // !ODATA_ENTITYTEST_H
