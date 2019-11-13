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
    this->name_.clear();
    this->lessonList_.clear();
}

void Day::swap(Day &day)
{
    std::swap(this->name_, day.name_);
    std::swap(this->lessonList_,day.lessonList_);
}

bool Day::empty()
{
    return this->lessonList_.empty();
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
    this->name_.clear();
    name_ = name;
}

void Day::addLesson(const Lesson &lesson)
{
    this->lessonList_.push_back(lesson);
}

list<Lesson> Day::getLessonList() const
{
    return lessonList_;
}

string Day::getName() const
{
    return name_;
}
