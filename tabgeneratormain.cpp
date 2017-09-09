#include "tabgeneratormain.h"
#include "ui_tabgeneratormain.h"
#include <QDebug>

tabGeneratorMain::tabGeneratorMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabGeneratorMain)
{
    ui->setupUi(this);

    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11,11,11,11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    tabWidget = new QTabWidget();

    QMap<int, QString> tabs;     
    for(int i = 1; i <= 20; i++)
    {
        tabs[i] = QString("%1").arg(i);;
    }
    QMap<int, QString>::const_iterator i = tabs.constBegin();
    while(i != tabs.constEnd()){
        tabCreator = new QWidget();
        tabCreator->setObjectName(QStringLiteral("tab %1").arg(i.value()));
        int position = i.value().size() - 1;
        QString tabTitle = QString(i.value()).insert(position, "&");
        tabWidget->addTab(tabCreator, tabTitle);
        i++;
    }

    gridLayout->addWidget(tabWidget, 0, 0 , 1, 1);
    this->setCentralWidget(centralWidget);
}

tabGeneratorMain::~tabGeneratorMain()
{
    delete ui;
}
