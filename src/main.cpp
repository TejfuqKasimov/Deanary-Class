// Copyright 2024 Kasimov T.

#include <string>
#include <iostream>
#include <fstream>
#include <clocale>

#include "..\include\Student.h"
#include "..\include\Group.h"
#include "..\include\Deanary.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Deanary deanary;

    deanary.createGroups("..\\bd\\groups.txt");
    deanary.hireStudent("..\\bd\\students.txt");
    deanary.addGroup(Group("23MББЭ1",
                    "Международный Бакалавриат по Бизнесу и Экономике"));
    Student a(8, "Пацанчик СКрутым Именем");
    a.addToGroup(deanary.getGroup("23MББЭ1"));
    deanary.initHeads();
    deanary.addMarksToAll();
    std::vector <Student*> students_vector;
    students_vector.push_back(deanary.getStudent(4));
    students_vector.push_back(deanary.getStudent(6));
    deanary.moveStudents(students_vector, deanary.getGroup("23MББЭ1"));
    deanary.fireStudent(students_vector);
    deanary.safeStaff("..\\bd\\students.txt", "..\\bd\\groups.txt");

    return 0;
}
