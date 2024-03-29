// Created Andrew Novicki
// Belarus, Minsk, 2019 November 11
// All rights reserved

// This class is a day of the week that includes classes on that day.
// name - day of week (Monday...Saturday)
// lessonList - lessons on that Day


#ifndef DAY_H
#define DAY_H

#include "lesson.h"
#include <list>

using std::list;

class Day
{
public:    
    // Constructors
    Day();
    Day(const Day &day);
    Day(Day &&day);                   // Moving constructor

    // Destructor
    ~Day();

    // Set methods
    void setName(const string &name);

    // Get methods
    string getName() const;
    list<Lesson> getLessonList() const;

    void addLesson(Lesson &&lesson);
    void swap(Day &day);              // Swap method

    Day &operator = (const Day &day);
    Day &operator = (Day &&day);      // Move assignment operator

private:
    string name_;
    list<Lesson> lessonList_;

};

#endif // DAY_H
