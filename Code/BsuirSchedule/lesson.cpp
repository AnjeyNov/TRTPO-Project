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

Lesson &Lesson::operator =(const Lesson &lesson)
{
    this->time_ = lesson.time_;
    this->subject_.clear();
    this->subject_ = lesson.subject_;
    this->note_.clear();
    this->note_ = lesson.note_;
    this->classroom_ = lesson.classroom_;
    this->subgroupNumber_ = lesson.subgroupNumber_;
    return *this;
}

Lesson &Lesson::operator =(Lesson &&lesson)
{
    swap(lesson);
    return *this;
}

void Lesson::setTime(Time &time)
{
    time_ = std::move(time);
}

void Lesson::setSubject(const string &subject)
{
    subject_ = subject;
}

void Lesson::setNote(const string &note)
{
    note_ = note;
}

void Lesson::setClassroom(const string &classroom)
{
    classroom_ = classroom;
}

void Lesson::setSubgroupNumber(short subgroupNumber)
{
    subgroupNumber_ = subgroupNumber;
}

