#ifndef MONITORPLUGININTERFACE_H
#define MONITORPLUGININTERFACE_H

#include <QObject>
#include <QWidget>

class MonitorPluginInterface
{
public:
    virtual ~MonitorPluginInterface() {}
    
    // 返回插件名称
    virtual QString getName() const = 0;
    
    // 创建监控界面部件
    virtual QWidget* createWidget() = 0;
    
    // 初始化插件
    virtual void initialize() = 0;
    
    // 刷新监控数据
    virtual void refreshData() = 0;
};

#define MonitorPluginInterface_iid "com.example.SystemMonitor.MonitorPluginInterface"

Q_DECLARE_INTERFACE(MonitorPluginInterface, MonitorPluginInterface_iid)

#endif // MONITORPLUGININTERFACE_H    