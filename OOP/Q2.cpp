#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;
    vector<string> transactionHistory;

public:
    Account(int accNo, string holderName, double bal)
        : accountNumber(accNo), accountHolderName(holderName), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back("Deposited: " + to_string(amount));
    }

    virtual bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactionHistory.push_back("Withdrawn: " + to_string(amount));
            return true;
        }
        transactionHistory.push_back("Failed withdrawal: " + to_string(amount));
        return false;
    }

    virtual void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Holder Name: " << accountHolderName
             << ", Balance: " << balance << endl;
    }

    void displayTransactionHistory() {
        cout << "Transaction History for Account " << accountNumber << ":\n";
        for (const string& entry : transactionHistory) {
            cout << entry << endl;
        }
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string holderName, double bal, double rate)
        : Account(accNo, holderName, bal), interestRate(rate) {}

    double calculateInterest() {
        return balance * (interestRate / 100);
    }

    void displayDetails() override {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNo, string holderName, double bal, double overdraft)
        : Account(accNo, holderName, bal), overdraftLimit(overdraft) {}

    bool withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            transactionHistory.push_back("Withdrawn: " + to_string(amount));
            return true;
        }
        transactionHistory.push_back("Failed withdrawal: " + to_string(amount));
        return false;
    }

    void displayDetails() override {
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount savings(1001, "Alice", 5000, 3.5);
    CurrentAccount current(2001, "Bob", 2000, 1000);

    // Operations on Savings Account
    savings.deposit(1000);
    savings.withdraw(2000);
    savings.deposit(500);
    savings.withdraw(7000); // Should fail
    cout << "Interest earned on savings: " << savings.calculateInterest() << endl;

    // Operations on Current Account
    current.deposit(3000);
    current.withdraw(4000);
    current.withdraw(2000); // Within overdraft limit
    current.withdraw(3000); // Should fail

    // Display Account Details
    cout << "\nSavings Account Details:\n";
    savings.displayDetails();

    cout << "\nCurrent Account Details:\n";
    current.displayDetails();

    // Display Transaction History
    cout << "\nSavings Account Transaction History:\n";
    savings.displayTransactionHistory();

    cout << "\nCurrent Account Transaction History:\n";
    current.displayTransactionHistory();

    return 0;
}

    
    
