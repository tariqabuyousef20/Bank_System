#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include"Validation.h"

using namespace std;

const int MAX_CLIENTS = 100;
const int MAX_EMPLOYEES = 50;
const int MAX_ADMINS = 10;

Client clients[MAX_CLIENTS];
Employee employees[MAX_EMPLOYEES];
Admin admins[MAX_ADMINS];

int clientCount = 0;
int employeeCount = 0;
int adminCount = 0;

//  قائمة العميل (Client Menu)
void clientMenu() {
    bool clientRunning = true;
    while (clientRunning) {
        int clientChoice, searchId, senderId, receiverId;
        double amount;

        cout << "\nClient Menu:\n";
        cout << "1. View Account Details (Enter ID)\n";
        cout << "2. Deposit Money (Enter ID)\n";
        cout << "3. Withdraw Money (Enter ID)\n";
        cout << "4. Transfer Money (Enter Sender & Receiver ID)\n";
        cout << "5. Check Balance (Enter ID)\n";
        cout << "6. Show All Clients\n";
        cout << "7. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> clientChoice;

        switch (clientChoice) {
        case 1: {
            cout << "Enter Client ID to view details: ";
            cin >> searchId;
            bool found = false;
            for (int i = 0; i < clientCount; i++) {
                if (clients[i].getId() == searchId) {
                    clients[i].display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Error: Client ID not found!\n";
            break;
        }

        case 2: {
            cout << "Enter Client ID for deposit: ";
            cin >> searchId;
            bool found = false;
            for (int i = 0; i < clientCount; i++) {
                if (clients[i].getId() == searchId) {
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    clients[i].deposit(amount);
                    cout << "Deposit successful! New balance: " << clients[i].getBalance() << " EGP\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Error: Client ID not found!\n";
            break;
        }

        case 3: {
            cout << "Enter Client ID for withdrawal: ";
            cin >> searchId;
            bool found = false;
            for (int i = 0; i < clientCount; i++) {
                if (clients[i].getId() == searchId) {
                    cout << "Enter withdraw amount: ";
                    cin >> amount;
                    if (amount > clients[i].getBalance()) {
                        cout << "Insufficient balance! Withdrawal canceled.\n";
                    }
                    else {
                        clients[i].withdraw(amount);
                        cout << "Withdrawal successful! New balance: " << clients[i].getBalance() << " EGP\n";
                    }
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Error: Client ID not found!\n";
            break;
        }

        case 4: {
            cout << "Enter Sender Client ID: ";
            cin >> senderId;
            cout << "Enter Receiver Client ID: ";
            cin >> receiverId;
            cout << "Enter amount to transfer: ";
            cin >> amount;

            Client* sender = nullptr;
            Client* receiver = nullptr;
            for (int i = 0; i < clientCount; i++) {
                if (clients[i].getId() == senderId) sender = &clients[i];
                if (clients[i].getId() == receiverId) receiver = &clients[i];
            }

            if (!sender || !receiver) {
                cout << "Error: Sender or Receiver ID not found. Transfer canceled.\n";
            }
            else if (!sender->transferTo(amount, *receiver)) {
                cout << "Transfer failed. Insufficient balance.\n";
            }
            else {
                cout << "Transfer successful from " << senderId << " to " << receiverId << "!\n";
            }
            break;
        }

        case 5: {
            cout << "Enter Client ID to check balance: ";
            cin >> searchId;
            bool found = false;
            for (int i = 0; i < clientCount; i++) {
                if (clients[i].getId() == searchId) {
                    cout << "Current balance: " << clients[i].getBalance() << " EGP\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Error: Client ID not found!\n";
            break;
        }

        case 6:
            if (clientCount == 0) {
                cout << "No clients registered yet.\n";
            }
            else {
                cout << "\nList of All Clients:\n";
                for (int i = 0; i < clientCount; i++) {
                    clients[i].display();
                }
            }
            break;

        case 7:
            cout << "Returning to main menu...\n";
            clientRunning = false;
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
int main() {
    bool running = true;
    int id;
    string name, password;
    double balance, salary;

    while (running) {
        cout << "========================================\n";
        cout << "Welcome to the Bank System\n";
        cout << "========================================\n\n";

        int userType;
        cout << "Select your account type:\n";
        cout << "1. Client\n";
        cout << "2. Employee\n";
        cout << "3. Admin\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> userType;

        switch (userType) {
        case 1:
            if (clientCount >= MAX_CLIENTS) {
                cout << "Client storage is full! Cannot add more clients.\n";
                break;
            }

            bool idExists;
            do {
                idExists = false;
                cout << "\nClient Registration:\n";
                cout << "Enter Client ID: ";
                cin >> id;

                for (int i = 0; i < clientCount; i++) {
                    if (clients[i].getId() == id) {
                        cout << "Error: Client ID already exists! Please enter a different ID.\n";
                        idExists = true;
                        break;
                    }
                }
            } while (idExists);

            cout << "Enter Client Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Initial Balance (minimum 1500 EGP): ";
            cin >> balance;

            clients[clientCount] = Client(id, name, password, balance);
            cout << "Client account successfully created.\n";
            clients[clientCount].display();
            clientCount++;

            clientMenu();
            break;

        case 2:
            cout << "\nEmployee Registration:\n";
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Salary: ";
            cin >> salary;

            employees[employeeCount] = Employee(id, name, password, salary);
            cout << "Employee account successfully created.\n";
            employees[employeeCount].display();
            employeeCount++;
            break;

        case 3:
            cout << "\nAdmin Registration:\n";
            cout << "Enter Admin ID: ";
            cin >> id;
            cout << "Enter Admin Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Salary: ";
            cin >> salary;

            admins[adminCount] = Admin(id, name, password, salary);
            cout << "Admin account successfully created.\n";
            admins[adminCount].display();
            adminCount++;
            break;

        case 4:
            cout << "Exiting the Bank System. Thank you!\n";
            running = false;
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}