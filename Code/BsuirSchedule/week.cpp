#include "week.h"

Week::Week()
{

}

Week::Week(const Week &week)
{
    this->number_ = week.number_;
    this->dayList_ = week.dayList_;
}

Week::Week(Week &&week)
{
    swap(week);
}

Week::~Week()
{
    dayList_.clear();
}

void Week::addDay(const Day &day)
{
    this->dayList_.push_back(day);
}

void Week::swap(Week &week)
{
    std::swap(this->dayList_, week.dayList_);
    std::swap(this->number_, week.number_);
}

void Week::clear()
{
    this->dayList_.clear();
}

Week &Week::operator = (const Week &week)
{
    this->number_ = week.number_;
    
    this->dayList_.clear();
    this->dayList_ = week.dayList_;
    
    return *this;
}

Week &Week::operator = (Week &&week)
{
    swap(week);
    return *this;
}

short Week::getNumber() const
{
    return number_;
}

void Week::setNumber(short value)
{
    number_ = value;
}
