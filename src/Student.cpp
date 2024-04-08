// "Copyright 2024 Kasimov T.

#include "..\include\Student.h"
#include "..\include\Group.h"
#include <string>
#include <vector>

Student::Student(const unsigned __int64 temp_id, const std::string temp_fio) {
    id = temp_id;
    fio = temp_fio;
    group = nullptr;
}

Student::~Student() {
    delete group;
}

void Student::addMark(const int temp_mark) {
    marks.push_back(temp_mark);
}

float Student::getAverageMark() {
    double ans = 0;

    if (marks.size() == 0) return 0;

    for (size_t i = 0; i < marks.size(); ++i) {
        ans += marks[i];
    }
    ans /= marks.size();

    return ans;
}

void Student::addToGroup(Group* temp_group) {
    group = temp_group;
    temp_group->addStudent(this);
}

std::string Student::getFio() {
    return fio;
}

unsigned __int64 Student::getId() {
    return id;
}

void Student::removeGroup() {
    for (int i = 0; i < group->getStudent()->size(); ++i) {
        if ((*group->getStudent())[i]->id == id) {
            group->getStudent()->erase(group->getStudent()->begin() + i);
        }
    }
    group = nullptr;
}

Group* Student::getGroup() {
    return group;
}

std::vector<int>* Student::getMark() {
    return &marks;
}
