#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    // Employee объект үүсгэх
    Employee emp("Bold", "123-456", 35,
                 "EMP001", "engineer", "2020-01-15",
                 "IT");

    // Ажлын тодорхойлолт нэмэх (1..n)
    emp.addJobDescription("System Development");
    emp.addJobDescription("Code Review");

    // Spouse нэмэх (0..1)
    Spouse sp("Nomin", "789-012", 32, "2018-06-20");
    emp.setSpouse(&sp);

    // Хүүхэд нэмэх (0..n)
    Child c1("temuulen", "111-222", 5, "lego");
    Child c2("chinguun", "333-444", 3, "doll");
    emp.addChild(&c1);
    emp.addChild(&c2);

    // Мэдээлэл хэвлэх
    emp.printInfo();

    return 0;
}
