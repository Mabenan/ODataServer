#ifndef ODataTestEntityProvider_H
#define ODataTestEntityProvider_H

#include <interface/ODataEntityInterface.h>
#include <model/ODataEntity.h>
class ODataTestEntityProvider : public ODataEntityInterface
{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.odataserver.ODataEntityInterface" FILE "ODataTestEntityProvider.json")
    Q_INTERFACES(ODataEntityInterface)

public:
    explicit ODataTestEntityProvider(QObject *parent = nullptr);

private:
    // CommandInterface interface


    // ODataEntityInterface interface
public:
	virtual QList<ODataSchema*> GetSchemas();
};

#endif // LISTCOMMANDSCOMMAND_H
