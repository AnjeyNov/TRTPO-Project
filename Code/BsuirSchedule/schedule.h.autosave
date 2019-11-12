// Created Andrew Novicki
// Belarus, Minsk, 2019 November 11
// All rights reserved

// This class describes all classes at all weeks.

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "week.h"

class Schedule
{
public:
    // Constructors
    Schedule();
    Schedule(const Schedule &schedule);
    Schedule(Schedule &&schedule);      // Moving constructor
    // Destructor
    ~Schedule();

    // Get methods
    Week getWeekOne() const;
    Week getWeekTwo() const;
    Week getWeekTree() const;
    Week getWeekFour() const;

    // Set methods
    void setWeekOne(const Week &week);
    void setWeekTwo(const Week &week);
    void setWeekTree(const Week &week);
    void setWeekFour(const Week &week);
    
    void swap(Schedule &schedule);

    Schedule &operator = (const Schedule &schedule);
    Schedule &operator = (Schedule &&schedule);
    
private:
    Week weekOne_ = {};
    Week weekTwo_ = {};
    Week weekTree_ = {};
    Week weekFour_ = {};
};

#endif // SCHEDULE_H
