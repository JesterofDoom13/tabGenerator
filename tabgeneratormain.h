#ifndef TABGENERATORMAIN_H
#define TABGENERATORMAIN_H

#include <QMainWindow>

namespace Ui {
class tabGeneratorMain;
}

class tabGeneratorMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit tabGeneratorMain(QWidget *parent = 0);
    ~tabGeneratorMain();

private:
    Ui::tabGeneratorMain *ui;
};

#endif // TABGENERATORMAIN_H
