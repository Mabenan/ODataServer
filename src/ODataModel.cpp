#include "ODataModel.h"
#include "ODataEntityInterface.h"
#include "odataentitycontroller.h"
#include <QPluginLoader>
#include <QCoreApplication>
#include <QDir>

ODataModel::ODataModel(QObject *parent) : QObject(parent)
{
}

QMap<QString, ODataEntityController *> ODataModel::getEntities()
{
    if (this->entities.count() == 0)
    {
        QDir pluginsDir = QDir(QCoreApplication::applicationDirPath());
        pluginsDir.cd("plugins");
        const auto entryList = pluginsDir.entryList(QDir::Files);
        for (const QString &fileName : entryList)
        {
            QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
            QObject *plugin = loader.instance();
            auto entityInterface = qobject_cast<ODataEntityInterface *>(plugin);
            if (entityInterface)
            {
                QList<ODataEntityController *> controllers = entityInterface->GetEntityControllers();
                foreach (ODataEntityController * controller, controllers) {

                    this->entities.insert(controller->getName(), controller);
                }
            }
        }
    }

    return this->entities;
}
