#ifndef STUDENTTRACKER_H
#define STUDENTTRACKER_H

#include <QObject>

class StudentTracker : public QObject
{
    Q_OBJECT
public:
    explicit StudentTracker(QObject *parent = nullptr);

signals:

public slots:
};

#endif // STUDENTTRACKER_H