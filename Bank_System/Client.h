#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include"Validation.h"

using namespace std;


class Client : public Person {
    double balance;

public:
    Client() : Person(), balance(balance) {}
    Client(int id, string name, string password, double balance)
        : Person(id, name, password) {
        setBalance(balance);
    }

    void setBalance(double _balance) {
        balance = (_balance >= 1500) ? _balance : 1500;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
    bool transferTo(double amount, Client& recipient) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            return true;
        }
        return false;
    }
    void display() {
        Person::display();
        cout << "Balance: " << balance << "\n";
        cout << "___________________________________________\n";
    }
    void checkBalance() {
        cout << "Your Balance: " << balance;

    }
};

