// "Copyright 2024 Kasimov T.

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

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

    void chooseHead(const Student* = nullptr);
    Student* getHead();

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

#endif  // INCLUDE_GROUP_H_
