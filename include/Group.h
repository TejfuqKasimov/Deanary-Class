// "Copyright 2024 Kasimov T.

#ifndef C__USERS_TOFIK_DESKTOP_DEANERY_INCLUDE_GROUP_H_
#define C__USERS_TOFIK_DESKTOP_DEANERY_INCLUDE_GROUP_H_

#include <string>
#include <vector>
#include "Student.h"

class Student;

class Group {
 private:
    std::string title;
    std::string spec;
    std::vector <Student*> students;
    Student* head;

 public:
    explicit Group(const std::string = "", const std::string = "");
    ~Group();

    void addStudent(Student*);

    void chooseHead(const Student&);

    Student* getStudent(const std::string);
    Student* getStudent(const unsigned __int64 temp_id);

    float getAverageMark();

    bool isEmpty();
    bool containsStudent(Student&);
    std::vector <Student*>* getStudent();

    void removeStudent(Student&);

    std::string getTitle();
    std::string getSpec();
};

#endif  // C__USERS_TOFIK_DESKTOP_DEANERY_INCLUDE_GROUP_H_
