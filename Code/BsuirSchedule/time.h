// Created Andrew Novicki
// Belarus, Minsk, 2019 November 11
// All rights reserved

// This class describes the time the class takes.

// Members:
// start_ - class start time
// end_ - class end time

#ifndef TIME_H
#define TIME_H

#include <string>

class Time
{
public:
    // Constructors
    Time();
    Time(const Time &time);
    Time(Time &&time); // Moving constructor
    Time(std::string&&, std::string&&);

    // Destructor
    ~Time();

    // Get methods
    std::string getStart() const;
    std::string getEnd() const;

    // Set methods
    void setStart(const std::string &start);
    void setEnd(const std::string &end);

    // Swap method
    void swap(Time &time);

    Time &operator = (const Time &time);
    Time &operator = (Time &&time);     // Move assignment operator

private:
    std::string start_;
    std::string end_;
};

#endif // TIME_H
