#include "tabgeneratormain.h"
#include "ui_tabgeneratormain.h"

tabGeneratorMain::tabGeneratorMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tabGeneratorMain)
{
    ui->setupUi(this);
}

tabGeneratorMain::~tabGeneratorMain()
{
    delete ui;
}
