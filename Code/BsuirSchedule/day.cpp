#include "day.h"

Day::Day()
{

}

Day::Day(const Day &day)
{
    this->name_ = day.name_;
    this->lessonList_ = day.lessonList_;
}

Day::Day(Day &&day)
{
    swap(day);
}

Day::~Day()
{

}

void Day::addLesson(Lesson &&lesson)
{
    this->lessonList_.push_back(std::move(lesson));
}

void Day::swap(Day &day)
{
    std::swap(this->name_, day.name_);
    std::swap(this->lessonList_,day.lessonList_);
}

Day &Day::operator = (const Day &day)
{
    this->name_.clear();
    this->name_ = day.name_;
    this->lessonList_.clear();
    this->lessonList_ = day.lessonList_;
    return *this;
}

Day &Day::operator = (Day &&day)
{
    swap(day);
    return *this;
}

void Day::setName(const string &name)
{
    name_ = name;
}

list<Lesson> Day::getLessonList() const
{
    return lessonList_;
}

string Day::getName() const
{
    return name_;
}
