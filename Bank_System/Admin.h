#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include"Validation.h"

using namespace std;


class Admin : public Employee {
public:
    Admin() :Employee() {}

    Admin(int _id, string _name, string _password, double _salary)
        : Employee(_id, _name, _password, _salary) {}

    void display() {
        Employee::display();
    }
};

