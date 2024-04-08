// "Copyright 2024 Kasimov T.

#include "..\include\Deanary.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>
#include <locale>

Deanary::Deanary() {
    return;
}

Deanary::~Deanary() {
    return;
}

void Deanary::createGroups(const std::string dataPath) {
    std::ifstream DeanaryData(dataPath);

    if (!DeanaryData.is_open()) {
        std::cout << "groups.txt open Error" << std::endl;
        return;
    }
    std::string DataLine;
    std::string temp_name, temp_spec, tmpSpec;

    while (std::getline(DeanaryData, DataLine)) {
        temp_spec = "";
        std::istringstream isData(DataLine);
        isData >> temp_name;
        while (isData >> tmpSpec) {
            temp_spec += tmpSpec + ' ';
        }
        if (!this->containsGroup(temp_name)) {
            Group* temp_group = new Group(temp_name, temp_spec);
            groups.push_back(temp_group);
        }
    }
}



bool Deanary::containsGroup(const std::string temp_title) {
    for (int i = 0; i < groups.size(); ++i) {
        if (groups[i]->getTitle() == temp_title) {
            return true;
        }
    }

    return false;
}

void Deanary::hireStudent(const std::string dataPath) {
    std::ifstream DeanaryData(dataPath);

    if (!DeanaryData.is_open()) {
        std::cout << "students.txt open Error" << std::endl;
        return;
    }

    std::string DataLine;
    while (std::getline(DeanaryData, DataLine)) {
        unsigned __int64 temp_id;
        std::string temp_surname, temp_name, temp_fatheName, temp_group;

        std::istringstream istreamData(DataLine);

        istreamData >> temp_id;
        istreamData >> temp_surname >> temp_name
                    >> temp_fatheName >> temp_group;

        std::string temp_fio = temp_surname + ' ' +
                    temp_name + ' ' + temp_fatheName;

        Student* temp_student = new Student(temp_id, temp_fio);

        temp_student->addToGroup(getGroup(temp_group));

        int mark;
        while (istreamData >> mark) temp_student->addMark(mark);
    }
}

Group* Deanary::getGroup(const std::string temp_title) {
    for (Group* x : groups) {
        if (x->getTitle() == temp_title) {
            return x;
        }
    }

    return nullptr;
}

void Deanary::addMarksToAll() {
    srand(time(NULL));
    for (Group* x : groups) {
        for (Student* y : *(x->getStudent())) {
            y->addMark(rand() % 10);
        }
    }
}

void Deanary::moveStudents(const std::vector <Student*>& temp_students,
                           const Group& temp_group) {
    for (Student* x : temp_students) {
        x->removeGroup();
        x->addToGroup(&const_cast<Group&>(temp_group));
    }
}

void Deanary::safeStaff(std::string pathToStudents, std::string pathToGroups) {
    setlocale(LC_ALL, "Russian");

    std::fstream DeanaryData;

    DeanaryData.open(pathToGroups, std::ios::out | std::ios::trunc);

    if (DeanaryData.fail()) {
        std::cout << "groups.txt open Error for Writing" << std::endl;
        return;
    }

    for (Group* x : groups) {
        DeanaryData << x->getTitle() << ' ' << x->getSpec() << std::endl;
    }
    DeanaryData.close();

    DeanaryData.open(pathToStudents, std::ios::out | std::ios::trunc);

    if (DeanaryData.fail()) {
        std::cout << "students.txt open Error for Writing" << std::endl;
        return;
    }

    for (Group* x : groups) {
        for (Student* y : *x->getStudent()) {
            DeanaryData << y->getId() << ' ' <<y->getFio() <<
                           " " << y->getGroup()->getTitle() << ' ';
            for (int k : *y->getMark()) {
                DeanaryData << k << ' ';
            }
            DeanaryData << std::endl;
        }
    }
    DeanaryData.close();
}

void Deanary::initHeads() {
    srand(time(NULL));
    for (Group* x : groups) {
        Student* y = *x->getStudent()->begin() +
                    (rand() % x->getStudent()->size());
        x->chooseHead(*y);
    }
}

void Deanary::fireStudent(const std::vector <Student*>& temp_students) {
    for (Student* x : temp_students) {
        x->removeGroup();
    }
}

std::vector <Group*>* Deanary::getGroup() {
    return &groups;
}

void Deanary::addGroup(const Group& temp_group) {
    if (!containsGroup(const_cast<Group&>(temp_group).getTitle())) {
        groups.push_back(&const_cast<Group&>(temp_group));
    }
}
