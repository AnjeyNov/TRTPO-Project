#include "time.h"

Time::Time()
{

}

Time::Time(const Time &time)
{
    this->start_ = time.start_;
    this->end_ = time.end_;
}

Time::Time(Time &&time)
{
    swap(time);
}

Time::Time(std::string &&start, std::string &&end)
{
    std::swap(this->start_, start);
    std::swap(this->end_, end);
}

Time::~Time()
{

}

std::string Time::getStart() const
{
    return start_;
}

std::string Time::getEnd() const
{
    return end_;
}

void Time::swap(Time &time)
{
    std::swap(this->start_, time.start_);
    std::swap(this->end_, time.end_);
}

Time &Time::operator =(const Time &time)
{
    this->start_.clear();
    this->start_ = time.start_;
    this->end_.clear();
    this->end_ = time.end_;
    return *this;
}

Time &Time::operator =(Time &&time)
{
    swap(time);
    return *this;
}

void Time::setStart(const std::string &start)
{
    start_ = start;
}

void Time::setEnd(const std::string &end)
{
    end_ = end;
}

