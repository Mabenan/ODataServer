#ifndef ODATA_ENTITYTEST2_H
#define ODATA_ENTITYTEST2_H

#include <QObject>
#include <model/ODataEntity.h>

class ODataTestEntity2 : public ODataEntity
{


public:
	virtual ODataEntity* clone() const;
    ODataTestEntity2();
    ODataTestEntity2(const ODataTestEntity2 &ODataTestEntity2);

	virtual void deleteEntity() const;
	virtual void update() const;
	virtual void insert() const;
	virtual void get(QMap<QString, QVariant> keys, QUrlQuery query);


};

#endif // !ODATA_ENTITYTEST2_H
