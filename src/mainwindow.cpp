#include "mainwindow.h"
#include <QListWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPluginLoader>
#include <QApplication>
#include <QLabel>
#include <QDir>
#include "monitorplugininterface.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 创建中心部件
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 创建主布局
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // 创建左侧列表
    m_monitorListWidget = new QListWidget(this);
    mainLayout->addWidget(m_monitorListWidget, 1);

    // 创建右侧堆叠窗口
    m_monitorStackedWidget = new QStackedWidget(this);
    mainLayout->addWidget(m_monitorStackedWidget, 3);

    // 加载插件
    loadPlugins();

    // 连接信号与槽
    connect(m_monitorListWidget, &QListWidget::currentRowChanged,
            this, &MainWindow::changeMonitorWidget);

    // 设置初始大小
    resize(800, 600);
}

MainWindow::~MainWindow()
{
    // 卸载插件
    for (auto loader : m_plugins) {
        loader->unload();
        delete loader;
    }
}

void MainWindow::changeMonitorWidget(int index)
{
    m_monitorStackedWidget->setCurrentIndex(index);
}

void MainWindow::loadPlugins()
{
    // 扫描插件目录
    QDir pluginsDir(QApplication::instance()->applicationDirPath() + "/../plugins");
    qDebug() << "Scanning plugins directory:" << pluginsDir.absolutePath();
    // 加载所有插件
    for (const QString &fileName : pluginsDir.entryList(QDir::Files)) {
        qDebug() << "load new plugins:" << pluginsDir.absoluteFilePath(fileName);
        QPluginLoader *loader = new QPluginLoader(pluginsDir.absoluteFilePath(fileName), this);
        QObject *plugin = loader->instance();

        if (plugin) {
            MonitorPluginInterface *monitorPlugin = qobject_cast<MonitorPluginInterface*>(plugin);
            if (monitorPlugin) {
                // 添加到列表和堆叠窗口
                m_monitorListWidget->addItem(monitorPlugin->getName());
                m_monitorStackedWidget->addWidget(monitorPlugin->createWidget());
                m_plugins[monitorPlugin->getName()] = loader;
                qDebug() << "Loaded plugin:" << monitorPlugin->getName();
            } else {
                qDebug() << "Plugin" << fileName << "does not implement MonitorPluginInterface";
                delete loader;
            }
        } else {
            qDebug() << "Failed to load plugin:" << loader->errorString();
            delete loader;
        }
    }

    // 如果没有加载任何插件，添加一个空页面
    if (m_monitorListWidget->count() == 0) {
        m_monitorListWidget->addItem("无可用监控插件");
        m_monitorStackedWidget->addWidget(new QLabel("未找到监控插件", this));
    } else {
        // 选择第一个项目
        m_monitorListWidget->setCurrentRow(0);
    }
}    