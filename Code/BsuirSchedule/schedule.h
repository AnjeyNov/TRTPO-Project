#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "week.h"

class Schedule
{
public:
    Schedule();
    ~Schedule();


    Week getWeekOne() const;
    Week getWeekTwo() const;
    Week getWeekTree() const;
    Week getWeekFour() const;

    void setWeekOne(const Week &value);
    void setWeekTwo(const Week &value);
    void setWeekTree(const Week &value);
    void setWeekFour(const Week &value);

private:
    Week weekOne = {};
    Week weekTwo = {};
    Week weekTree = {};
    Week weekFour = {};
};

#endif // SCHEDULE_H
