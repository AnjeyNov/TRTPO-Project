#include "lesson.h"

Lesson::Lesson()
{

}

Lesson::Lesson(const Lesson &lesson)
{
    this->time_ = lesson.time_;
    this->subject_ = lesson.subject_;
    this->note_ = lesson.note_;
    this->classroom_ = lesson.classroom_;
    this->subgroupNumber_ = lesson.subgroupNumber_;
}

Lesson::Lesson(Lesson &&lesson)
{
    swap(lesson);
}

Lesson::~Lesson()
{
    this->subject_.clear();
    this->note_.clear();
    this->classroom_.clear();
}

string Lesson::getSubject() const
{
    return subject_;
}

string Lesson::getNote() const
{
    return note_;
}

string Lesson::getClassroom() const
{
    return classroom_;
}

short Lesson::getSubgroupNumber() const
{
    return subgroupNumber_;
}

void Lesson::swap(Lesson &lesson)
{
    this->time_.swap(lesson.time_);
    std::swap(this->subject_, lesson.subject_);
    std::swap(this->note_, lesson.note_);
    std::swap(this->classroom_, lesson.classroom_);
    std::swap(this->subgroupNumber_, lesson.subgroupNumber_);
}

Lesson &Lesson::operator = (const Lesson &lesson)
{
    this->time_ = lesson.time_;
    
    this->subject_.clear();
    this->subject_ = lesson.subject_;
    
    this->note_.clear();
    this->note_ = lesson.note_;
    
    this->classroom_.clear();
    this->classroom_ = lesson.classroom_;
    
    this->subgroupNumber_ = lesson.subgroupNumber_;
    
    return *this;
}

Lesson &Lesson::operator =(Lesson &&lesson)
{
    swap(lesson);
    return *this;
}

string Lesson::getType() const
{
    return type_;
}

void Lesson::setType(const string &type)
{
    type_ = type;
}

void Lesson::setTime(const Time &time)
{
    time_ = (time);
}

void Lesson::setSubject(const string &subject)
{
    this->subject_.clear();
    subject_ = subject;
}

void Lesson::setNote(const string &note)
{
    this->note_.clear();
    note_ = note;
}

void Lesson::setClassroom(const string &classroom)
{
    this->classroom_.clear();
    classroom_ = classroom;
}

void Lesson::setSubgroupNumber(short subgroupNumber)
{
    subgroupNumber_ = subgroupNumber;
}

