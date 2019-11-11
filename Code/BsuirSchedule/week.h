// Created Andrew Novicki
// Belarus, Minsk, 2019 November 11
// All rights reserved

// This class is a day of the week that includes classes on that day.

// number - number of the week (1,2,3,4)
// dayList - days with classes this week



#ifndef WEEK_H
#define WEEK_H
#include "day.h"

class Week
{
public:
    // Constructors
    Week();
    Week(const Week &week);
    Week(Week &&week);      // Moving constructor
    // Destructor
    ~Week();

    // Get method
    short getNumber() const;

    // Set method
    void setNumber(short value);

    void addDay(Day& day);
    void swap(Week &week);              // Swap method
    Week &operator = (const Week &week);
    Week &operator = (Week &&week);     // Move assignment operator

private:
    short number_ = 0;
    list<Day> dayList_;

};

#endif // WEEK_H
