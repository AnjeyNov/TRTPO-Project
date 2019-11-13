// Created Andrew Novicki
// Belarus, Minsk, 2019 November 11
// All rights reserved

// This class describes the lesson.

// Members:
// time_ - the time the lesson takes.
// subject_ - discipline name
// note_ - additional information (class transfer, more discipline information, etc.)
// clasroom_ - classroom where the lesson will be held
// subgroupNumber_ - the subgroup for which the lesson is organized

#ifndef LESSON_H
#define LESSON_H

#include "time.h"

using std::string;

class Lesson
{

public:
    // Constructors
    Lesson();
    Lesson(const Lesson &lesson);
    Lesson(Lesson &&lesson); // Moving constructor

    // Destructor
    ~Lesson();

    // Set methods
    void setTime(const Time &time);
    void setSubject(const string &subject);
    void setNote(const string &note);
    void setClassroom(const string &classroom);
    void setSubgroupNumber(short subgroupNumber);

    // Get methods
    string getSubject() const;
    string getNote() const;
    string getClassroom() const;
    short getSubgroupNumber() const;

    // Swap method
    void swap(Lesson &lesson);

    Lesson &operator = (const Lesson &lesson);
    Lesson &operator = (Lesson &&lesson);   // Move assignment operator

    string getType() const;
    void setType(const string &type);

private:
    Time time_;
    string subject_;
    string note_;
    string classroom_;
    string type_;
    short subgroupNumber_;
};

#endif // LESSON_H
