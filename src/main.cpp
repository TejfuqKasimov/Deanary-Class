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

    Student a(12, "Касимов Тейфук Эльманович");
    a.addToGroup(deanary.getGroup("23КНТ6"));

    deanary.addGroup(Group("23КНТ4", "Компьютерные Науки И Технологии"));

    deanary.safeStaff("..\\bd\\students.txt", "..\\bd\\groups.txt");
    return 0;
}
