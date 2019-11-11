#ifndef GROUP_H
#define GROUP_H

#include "schedule.h"

class Group
{
public:
    Group();

    string getNumber() const;
    string getFaculty() const;
    string getSpeciality() const;
    short getCourse() const;
    Schedule getSchedule() const;

    void setSchedule(const Schedule &value);
    void setNumber(const string &value);
    void setFaculty(const string &value);
    void setSpeciality(const string &value);
    void setCourse(short value);

private:
    string number = {0};
    string faculty = {0};
    string speciality = {0};
    short course = 0;
    Schedule schedule = {};

};

#endif // GROUP_H
