// "Copyright 2024 Kasimov T.

#include "..\include\Group.h"
#include "..\include\Student.h"
#include <string>

Group::Group(const std::string temp_title, const std::string temp_spec) {
    this->title = temp_title;
    this->head = nullptr;
    this->spec = temp_spec;
}

Group::~Group() {
    delete head;
}

void Group::addStudent(Student* temp_student) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i]->getId() == temp_student->getId()) {
            return;
        }
    }

    students.push_back(temp_student);
}

void Group::chooseHead(const Student& temp_head) {
    head = &const_cast<Student&>(temp_head);
}

Student* Group::getStudent(const std::string temp_name) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i]->getFio() == temp_name) {
            return students[i];
        }
    }

    return nullptr;
}

Student* Group::getStudent(const unsigned __int64 temp_id) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i]->getId() == temp_id) {
            return students[i];
        }
    }

    return nullptr;
}

float Group::getAverageMark() {
    double ans = 0;

    if (this->isEmpty()) return 0;

    for (size_t i = 0; i < students.size(); ++i) {
        ans += students[i]->getAverageMark();
    }
    ans /= students.size();

    return ans;
}

bool Group::isEmpty() {
    return students.empty();
}

void Group::removeStudent(Student& temp_student) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i]->getId() == temp_student.getId()) {
            students.erase(students.begin() + i);
            temp_student.removeGroup();
        }
    }
}

bool Group::containsStudent(Student& temp_student) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i]->getId() == temp_student.getId()) {
            return true;
        }
    }
    return false;
}

std::string Group::getTitle() {
    return title;
}

std::vector <Student*>* Group::getStudent() {
    return &students;
}

std::string Group::getSpec() {
    return spec;
}
