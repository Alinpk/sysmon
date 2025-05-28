#ifndef CPUMONITOR_H
#define CPUMONITOR_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "monitorplugininterface.h"

class CPUMonitorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CPUMonitorWidget(QWidget *parent = nullptr);

public slots:
    void refreshData();

private:
    QLabel *m_cpuLabel;
};

class CPUMonitor : public QObject, public MonitorPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID MonitorPluginInterface_iid)
    Q_INTERFACES(MonitorPluginInterface)

public:
    QString getName() const override;
    QWidget* createWidget() override;
    void initialize() override;
    void refreshData() override;

private:
    CPUMonitorWidget *m_widget;
};

#endif // CPUMONITOR_H    