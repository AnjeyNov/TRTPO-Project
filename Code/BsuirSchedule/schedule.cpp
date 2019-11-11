#include "schedule.h"

Schedule::Schedule()
{

}

Week Schedule::getWeekOne() const
{
    return weekOne;
}

void Schedule::setWeekOne(const Week &value)
{
    weekOne = value;
}

Week Schedule::getWeekTwo() const
{
    return weekTwo;
}

void Schedule::setWeekTwo(const Week &value)
{
    weekTwo = value;
}

Week Schedule::getWeekTree() const
{
    return weekTree;
}

void Schedule::setWeekTree(const Week &value)
{
    weekTree = value;
}

Week Schedule::getWeekFour() const
{
    return weekFour;
}

void Schedule::setWeekFour(const Week &value)
{
    weekFour = value;
}
