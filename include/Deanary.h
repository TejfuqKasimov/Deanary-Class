// "Copyright 2024 Kasimov T.

#ifndef C__USERS_TOFIK_DESKTOP_DEANERY_INCLUDE_DEANARY_H_
#define C__USERS_TOFIK_DESKTOP_DEANERY_INCLUDE_DEANARY_H_

#include <string>
#include <vector>
#include <iostream>
#include "Group.h"

class Group;

class Deanary {
 private:
    std::vector <Group*> groups;

 public:
    Deanary();
    ~Deanary();

    void createGroups(const std::string);
    void addGroup(const Group&);
    bool containsGroup(const std::string);
    void hireStudent(const std::string);
    Group* getGroup(const std::string);
    void addMarksToAll();
    void moveStudents(const std::vector <Student*>&, const Group&);
    void safeStaff(std::string = "", std::string = "");
    void initHeads();
    void fireStudent(const std::vector <Student*>&);
    std::vector <Group*>* getGroup();
};

#endif  // C__USERS_TOFIK_DESKTOP_DEANERY_INCLUDE_DEANARY_H_
