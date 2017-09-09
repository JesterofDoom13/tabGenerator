#ifndef TABGENERATORMAIN_H
#define TABGENERATORMAIN_H

#include <QMainWindow>
#include <QWidget>
#include <QTabWidget>
#include <QTableWidget>
#include <QGridLayout>

#include "studenttracker.h"

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
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabCreator;
    QTableWidget *tableWidget;
    StudentTracker studentTracker;
    QAction *openStudentTrackerAction;
    QAction *quitAction;


};

#endif // TABGENERATORMAIN_H
