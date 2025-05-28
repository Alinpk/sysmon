#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPluginLoader>

class QListWidget;
class QStackedWidget;
class MonitorPluginInterface;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeMonitorWidget(int index);
    void loadPlugins();

private:
    QListWidget *m_monitorListWidget;
    QStackedWidget *m_monitorStackedWidget;
    QMap<QString, QPluginLoader*> m_plugins;
};
#endif // MAINWINDOW_H    