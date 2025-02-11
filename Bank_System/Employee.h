#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include"Validation.h"

using namespace std;

class Employee : public Person {
    double salary;

public:
    Employee() : Person(), salary(salary) {}
    Employee(int id, string name, string password, double salary)
        : Person(id, name, password) {
        setSalary(salary);
    }

    void setSalary(double _salary) {
        salary = (_salary >= 5000) ? _salary : 5000;
    }

    double getSalary() {
        return salary;
    }

    void display() {
        Person::display();
        cout << "Salary: " << salary << "\n";
        cout << "___________________________________________\n";
    }
};


