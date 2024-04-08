// "Copyright 2024 Kasimov T.

#ifndef  C__USERS_TOFIK_DESKTOP_DEANERY_INCLUDE_STUDENT_H_
#define  C__USERS_TOFIK_DESKTOP_DEANERY_INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include "Group.h"

class Group;

class Student {
 private:
    unsigned __int64 id;
    std::string fio;
    Group* group;
    std::vector <int> marks;

 public:
    explicit Student(const unsigned __int64 = 0, const std::string = "");
    ~Student();
    // enrollment in a group
    void addToGroup(Group*);

    std::string getFio();
    unsigned __int64 getId();

    void addMark(const int);
    float getAverageMark();
    void removeGroup();
    Group* getGroup();
    std::vector<int>* getMark();
};

#endif  //  C__USERS_TOFIK_DESKTOP_DEANERY_INCLUDE_STUDENT_H_
