#include "group.h"

Group::Group()
{

}

string Group::getNumber() const
{
    return number;
}

void Group::setNumber(const string &value)
{
    number = value;
}

string Group::getFaculty() const
{
    return faculty;
}

void Group::setFaculty(const string &value)
{
    faculty = value;
}

string Group::getSpeciality() const
{
    return speciality;
}

void Group::setSpeciality(const string &value)
{
    speciality = value;
}

short Group::getCourse() const
{
    return course;
}

void Group::setCourse(short value)
{
    course = value;
}

Schedule Group::getSchedule() const
{
    return schedule;
}

void Group::setSchedule(const Schedule &value)
{
    schedule = value;
}
