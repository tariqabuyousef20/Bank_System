#pragma once
#include <iostream>
#include <string>
#include"Validation.h"


using namespace std;

class Person {
    int id;
    string name;
    string password;

public:
    Person() : id(id), name(name), password(password) {}
    Person(int id, string name, string password) : id(id) {
        setName(name);
        setPassword(password);
    }

    void setId(int _id) {
        this->id = _id;
    }

    int getId() {
        return id;
    }

    void setName(string name) {
        if (Validation::isValidName(name)) {
            this->name = name;
        }
        else {
            cout << "Invalid name! Must be alphabetic and between 3 and 20 characters." << endl;
            return;
        }
    }

    string getName() {
        return name;
    }

    void setPassword(string _password) {
        if (Validation::isValidPassword(_password)) {
            this->password = _password;
        }
        else {
            cout << "Password must be between 8 characters long, with at least 1 small letter, 1 capital letter and 1 special character." << endl;
            return;
        }
    }

    string getPassword() {
        return password;
    }

    void display() {
        cout << "Details:\n";
        cout << "ID: " << id << "\nName: " << name << "\n";
    }
};

