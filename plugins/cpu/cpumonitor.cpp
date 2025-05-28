#include "cpumonitor.h"
#include <QDebug>

CPUMonitorWidget::CPUMonitorWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    // 添加标题
    QLabel *titleLabel = new QLabel("CPU 监控", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 16pt; font-weight: bold;");
    layout->addWidget(titleLabel);
    
    // 添加CPU信息标签
    m_cpuLabel = new QLabel("CPU 使用率: --%", this);
    m_cpuLabel->setAlignment(Qt::AlignCenter);
    m_cpuLabel->setStyleSheet("font-size: 14pt;");
    layout->addWidget(m_cpuLabel);
    
    // 添加刷新按钮
    QPushButton *refreshButton = new QPushButton("刷新", this);
    connect(refreshButton, &QPushButton::clicked, this, &CPUMonitorWidget::refreshData);
    layout->addWidget(refreshButton);
    
    setLayout(layout);
}

void CPUMonitorWidget::refreshData()
{
    // 这里是底层实现的空接口
    // 实际应用中，这里会调用真实的系统监控API获取CPU信息
    qDebug() << "CPUMonitor: 调用真实CPU监控接口";
    
    // 模拟数据
    m_cpuLabel->setText("CPU 使用率: 42%");
}

QString CPUMonitor::getName() const
{
    return "CPU 监控";
}

QWidget* CPUMonitor::createWidget()
{
    m_widget = new CPUMonitorWidget();
    return m_widget;
}

void CPUMonitor::initialize()
{
    qDebug() << "CPUMonitor: 初始化";
}

void CPUMonitor::refreshData()
{
    if (m_widget)
        m_widget->refreshData();
}

#include "cpumonitor.moc"    