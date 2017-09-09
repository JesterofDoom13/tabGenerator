#ifndef STUDENTTRACKER_H
#define STUDENTTRACKER_H

#include <QObject>
#include <QMap>
#include <QVector>
#include <QAbstractTableModel>

// a pair that answers the questions"Did they pass the
// problem" and "How many attempts are they on?"
typedef QPair<bool, int> passedAndAttempts;
// Problem number with their passedAndAttempts pair
typedef QMap<int, passedAndAttempts> problems;
// Which Section and the problems associated with them.
typedef QMap<int, problems> sections;
/* Just to make things clear, these typedefs were all just layering
   everything within the other. This is a real onion of a data structure.*/

class StudentTracker : public QObject
{
    Q_OBJECT
public:
    explicit StudentTracker(QObject *parent = nullptr);

    int sectionsCount();
    int studentCount();
    int problemCount();

    inline sections getStudent(QString student)
        { return tracker->value(student); }
    inline problems getSection(QString student, int section)
        { return tracker->value(student).value(section); }
    inline bool problemPassed(QString student, int section, int problem)
        { return tracker->value(student).value(section).value(problem).first; }
    inline int problemAttempts(QString student, int section, int problem)
        { return tracker->value(student).value(section).value(problem).second; }

signals:
    void trackerUpdated();

public slots:
    void updateTracker();

private:
    QMap<QString, sections> *tracker;
    int numberOfSections;

};

class StudentTrackerModel : public QAbstractTableModel
{
public:
    StudentTrackerModel(QObject *parent = nullptr);

    void setTracker(StudentTracker &tracker);
    void setSection(int newSection);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role) const;
private:
    QString passedAt(int offset);
    QString triesAt(int offset);
    int currentSection;
    StudentTracker *modelTracker;

};

#endif // STUDENTTRACKER_H
