#ifndef ODataTestEntityProvider_H
#define ODataTestEntityProvider_H

#include <ODataEntityInterface.h>
#include <ODataEntity.h>
class ODataTestEntityProvider : public ODataEntityInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ODataEntityInterface_iid FILE "ODataTestEntityProvider.json")
    Q_INTERFACES(ODataEntityInterface)

public:
    explicit ODataTestEntityProvider(QObject *parent = nullptr);

private:
    // CommandInterface interface


    // ODataEntityInterface interface
public:
    QList<ODataEntityController *> GetEntityControllers() const;
    QList<ODataEntitySet *> getEntitySets() const;
};

#endif // LISTCOMMANDSCOMMAND_H
