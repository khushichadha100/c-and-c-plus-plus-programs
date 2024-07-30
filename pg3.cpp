#include <iostream.h>
#include <string>
#include<conio.h>
class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance) {}

    // Friend function declaration
    friend void transferFunds(BankAccount& source, BankAccount& destination, double amount);
    
    // Function to display account details
    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << \n;
        cout << "Balance: $" << balance << \n;
    }
};

// Friend function definition
void transferFunds(BankAccount& source, BankAccount& destination, double amount) {
    if (amount <= source.balance) {
        source.balance -= amount;
        destination.balance += amount;
        cout << "$" << amount << " transferred from Account " << source.accountNumber 
                  << " to Account " << destination.accountNumber << \n;
    } else {
        cout << "Insufficient funds in Account " << source.accountNumber << \n;
    }
}

int main() {
    // Create two BankAccount objects
    BankAccount account1("12345", 1000.0);
    BankAccount account2("67890", 500.0);

    cout << "Before transfer:" << endl;
    cout << "Account 1 Details:" << endl;
    account1.displayAccountDetails();
    cout << "Account 2 Details:" << endl;
    account2.displayAccountDetails();

    // Transfer funds using friend function
    transferFunds(account1, account2, 300.0);

    cout << "\nAfter transfer:" << endl;
    cout << "Account 1 Details:" << endl;
    account1.displayAccountDetails();
    cout << "Account 2 Details:" << endl;
    account2.displayAccountDetails();

    return 0;
}
