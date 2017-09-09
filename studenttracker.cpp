#include "studenttracker.h"
#include <QDebug>

StudentTracker::StudentTracker(QObject *parent)
    : QObject(parent)
{
    updateTracker();
}

int StudentTracker::sectionsCount()
{
    QMap<QString, sections>::const_iterator i = tracker->constBegin();
    int count = 0;
    while (i != tracker->constEnd()){
        if (count < i.value().count())
        {
            count = i.value().count();
        }
        ++i;
    }
    return count;
}

int StudentTracker::studentCount()
{
    int j = 0;
    QMap<QString, sections>::const_iterator i = tracker->constBegin();
    while (i != tracker->constEnd())
    {
        if (j < i.key().count())
        {
            j = i.key().count();
        }
    }
    return j;
}

int StudentTracker::problemCount()
{
    qDebug() << "Running StudentTracker::problemCount()";
    return 0;
}

void StudentTracker::updateTracker()
{
    tracker = new QMap<QString, sections>;
    qsrand(0);
    QStringList students;
    students << "John" << "Smith" << "Hello";
    for(auto s = 0; s < students.size(); ++s)
    {
        passedAndAttempts problemAttempts;
        problems problemNumber;
        sections section;
        QString student = students.at(s);
        for(auto i = 1; i <= 10; ++i)
        {
            for(auto j = 1; j <= 13; ++j)
            {
                problemAttempts.first = qrand() % 2 == 0 ? true : false;
                problemAttempts.second = qrand() % 10 ;
                problemNumber.insert(j, problemAttempts);
                section.insert(i, problemNumber);
            }
        }
        tracker->insertMulti(student, section);
    }
    emit trackerUpdated();
}

/************************************************************************
 *  The beginning of the StudenTrackerModel
************************************************************************/
StudentTrackerModel::StudentTrackerModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

void StudentTrackerModel::setTracker(StudentTracker &tracker)
{
    modelTracker = &tracker;
    //    reset();
}

void StudentTrackerModel::setSection(int newSection)
{
    if (newSection <= modelTracker->sectionsCount())
    {
        currentSection = newSection;
    }
}

int StudentTrackerModel::rowCount(const QModelIndex &/*parent*/) const
{
    return modelTracker->studentCount();
}

int StudentTrackerModel::columnCount(const QModelIndex &/*parent*/) const
{
    return modelTracker->problemCount();
}

QVariant StudentTrackerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        // Find out how many attempts were made on a problem
//        modelTracker->problemAttemptsCount(student, section, problem)
//        modelTracker->problemAttemptsCount(i, currentSection, index.column())
//        QMap<QString, sections>::const_iterator i = modelTracker.constBegin();
//        i += index.row();
//        if (index.column() == 0)
//                return i.key();
        // return the number of failed attempts.
        // The row is the student.
        // The current Section is what sections you're pulling data from
        // the column ends up being the problem.
        // Finally we check for the second in the pair for how many times they
        // have attempted.
//        return i->value(currentSection).value(index.column()).second;
    }
    return QVariant();
}

QVariant StudentTrackerModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    qDebug() << section << orientation << role;
    return QVariant();
}

