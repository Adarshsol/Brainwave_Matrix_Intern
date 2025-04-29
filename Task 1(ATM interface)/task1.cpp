#include <iostream>
#include <string>
using namespace std;

// Class for ATM operations
class ATM {
private:
    string userId;
    string userPin;
    double balance;
    string history;

public:
    ATM() {
        balance = 10000.0; // Default balance
        history = "";
    }

    void setUser(string id, string pin) {
        userId = id;
        userPin = pin;
    }

    bool authenticate(string id, string pin) {
        return (userId == id && userPin == pin);
    }

    void showMenu() {
        cout << "\n--- ATM Main Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
    }

    void checkBalance() {
        cout << "\nCurrent Balance: ₹" << balance << endl;
    }

    void depositMoney() {
        double amount;
        cout << "\nEnter amount to deposit: ₹";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            history += "Deposited: ₹" + to_string(amount) + "\n";
            cout << "Amount Deposited Successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdrawMoney() {
        double amount;
        cout << "\nEnter amount to withdraw: ₹";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            history += "Withdrawn: ₹" + to_string(amount) + "\n";
            cout << "Please collect your cash.\n";
        } else {
            cout << "Invalid amount or Insufficient balance.\n";
        }
    }

    void viewHistory() {
        if (history.empty()) {
            cout << "\nNo transactions yet.\n";
        } else {
            cout << "\n--- Transaction History ---\n";
            cout << history;
        }
    }
};

// Main function
int main() {
    ATM atm;
    string id, pin;

    // Setting default user credentials
    atm.setUser("user123", "1234");

    cout << "----- Welcome to the ATM Machine -----\n";

    // Authentication
    cout << "\nEnter User ID: ";
    cin >> id;
    cout << "Enter PIN: ";
    cin >> pin;

    if (atm.authenticate(id, pin)) {
        int choice;
        do {
            atm.showMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    atm.checkBalance();
                    break;
                case 2:
                    atm.depositMoney();
                    break;
                case 3:
                    atm.withdrawMoney();
                    break;
                case 4:
                    atm.viewHistory();
                    break;
                case 5:
                    cout << "\nThank you for using our ATM. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    } else {
        cout << "\nAuthentication Failed! Please check your User ID or PIN.\n";
    }

    return 0;
}