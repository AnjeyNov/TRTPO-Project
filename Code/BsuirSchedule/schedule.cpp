#include "schedule.h"

Schedule::Schedule()
{
    
}

Schedule::Schedule(const Schedule &schedule)
{
    this->weekOne_ = schedule.weekOne_;
    this->weekTwo_ = schedule.weekTwo_;
    this->weekTree_ = schedule.weekTree_;
    this->weekFour_ = schedule.weekFour_;
}

Schedule::Schedule(Schedule &&schedule)
{
    this->swap(schedule);
}

Schedule::~Schedule()
{
    this->weekOne_.clear();
    this->weekTwo_.clear();
    this->weekTree_.clear();
    this->weekFour_.clear();
}

Week Schedule::getWeekOne() const
{
    return weekOne_;
}

void Schedule::setWeekOne(const Week &week)
{
    weekOne_ = week;
}

Week Schedule::getWeekTwo() const
{
    return weekTwo_;
}

void Schedule::setWeekTwo(const Week &week)
{
    weekTwo_ = week;
}

Week Schedule::getWeekTree() const
{
    return weekTree_;
}

void Schedule::setWeekTree(const Week &week)
{
    weekTree_ = week;
}

Week Schedule::getWeekFour() const
{
    return weekFour_;
}

void Schedule::setWeekFour(const Week &week)
{
    weekFour_ = week;
}

void Schedule::swap(Schedule &schedule)
{
    this->weekOne_.swap(schedule.weekOne_);
    this->weekTwo_.swap(schedule.weekTwo_);
    this->weekTree_.swap(schedule.weekTree_);
    this->weekFour_.swap(schedule.weekFour_);
}

Schedule &Schedule::operator =(const Schedule &schedule)
{
    this->weekOne_ = schedule.weekOne_;
    this->weekTwo_ = schedule.weekTwo_;
    this->weekTree_ = schedule.weekTree_;
    this->weekFour_ = schedule.weekFour_;
    return *this;
}

Schedule &Schedule::operator =(Schedule &&schedule)
{
    this->swap(schedule);
    return *this;
}
