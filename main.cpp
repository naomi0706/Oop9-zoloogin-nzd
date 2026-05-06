#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    // 1. Create Division objects representing different departments
    Division itDivision("IT");
    Division hrDivision("HR");
    Division financeDivision("Finance");

    // 2. Create JobDescription objects representing various roles
    JobDescription jd1("System Development");
    JobDescription jd2("Code Review");
    JobDescription jd3("Recruitment");
    JobDescription jd4("Payroll Management");
    JobDescription jd5("Budget Analysis");

    // 3. Create Employee objects and configure their Division (1 relationship) and JobDescriptions (1..n relationship)
    Employee emp1("Bold", "123-456", 35,
                  "EMP001", "Engineer", "2020-01-15",
                  "IT");
    emp1.setDivision(itDivision); // Assign division
    emp1.addJobDescription(jd1);  // Add first job description
    emp1.addJobDescription(jd2);  // Add second job description

    Employee emp2("Munkh", "234-567", 29,
                  "EMP002", "HR Specialist", "2019-07-01",
                  "HR");
    emp2.setDivision(hrDivision);
    emp2.addJobDescription(jd3);

    Employee emp3("Tsetseg", "345-678", 31,
                  "EMP003", "Finance Analyst", "2021-03-10",
                  "Finance");
    emp3.setDivision(financeDivision);
    emp3.addJobDescription(jd4);
    emp3.addJobDescription(jd5);

    // 4. Configure Spouse (0..1 relationship) and Child (0..n relationship) for emp1
    Spouse sp("Nomin", "789-012", 32, "2018-06-20");
    emp1.setSpouse(&sp); // Assign a spouse to emp1

    Child c1("temuulen", "111-222", 5, "lego");
    Child c2("chinguun", "333-444", 3, "doll");
    emp1.addChild(&c1); // Add first child to emp1
    emp1.addChild(&c2); // Add second child to emp1

    // Print initial information for all employees
    emp1.printInfo();
    cout << endl;
    emp2.printInfo();
    cout << endl;
    emp3.printInfo();

    // Task 1: for the objects of Employee class configure spouse and child.
    // Configure relationships for emp2
    Spouse sp2("Saraa", "999-888", 28, "2021-02-14");
    emp2.setSpouse(&sp2);
    Child c3("Bold", "777-666", 3, "Ball");
    emp2.addChild(&c3);

    // Configure relationships for emp3
    Spouse sp3("Tulga", "555-444", 33, "2019-10-10");
    Child c4("Maral", "333-222", 5, "Book");
    Child c5("Anar", "111-000", 1, "Toy");
    emp3.setSpouse(&sp3);
    emp3.addChild(&c4);
    emp3.addChild(&c5);

    // Task 2: for each object of Employee class print all of it's information 
    // (0..1, 0..n, and 1, 1..n relationships are to be programmed correctly)
    // Print the fully configured profiles of all employees
    cout << "\n--- Updated Employee Information ---\n" << endl;
    emp1.printInfo();
    cout << endl;
    emp2.printInfo();
    cout << endl;
    emp3.printInfo();

    return 0;
}
