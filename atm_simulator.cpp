#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

double checkBalance(double balance);                
bool deposit(double &balance, double amount);        
bool withdraw(double &balance, double amount);       
int    getMenuChoice();                              
double getPositiveAmount(const std::string &label);  

int main() {
    double balance = 0.0; 
       cout << "Welcome to the ATM\n";

    while (true) {
         cout << "\n===== ATM Menu =====\n"
                  << "1. Check Balance\n"
                  << "2. Deposit Money\n"
                  << "3. Withdraw Money\n"
                  << "4. Exit\n";

        int choice = getMenuChoice();

        switch (choice) {
            case 1: {
                double b = checkBalance(balance); 
                   cout << "Current balance: $" << fixed << setprecision(2) << b << "\n";
                break;
            }
            case 2: {
                double amount = getPositiveAmount("deposit");
                if (deposit(balance, amount)) {
                    cout << "Deposited $" << fixed << setprecision(2) << amount
                              << ". New balance: $" << balance << "\n";
                } else {
                    cout << "Deposit failed. Amount must be greater than $0.00.\n";
                }
                break;
            }
            case 3: {
                double amount = getPositiveAmount("withdraw");
                if (withdraw(balance, amount)) {
                    cout << "Withdrew $" << fixed << setprecision(2) << amount
                              << ". New balance: $" << balance << "\n";
                } else {
                     cout << "Withdrawal failed. Amount must be > $0.00 and not exceed current balance.\n";
                }
                break;
            }
            case 4:
                cout << "Thank you for using the ATM. Goodbye!\n";
                return 0;
            default:
                
                   cout << "Invalid selection. Please choose 1-4.\n";
        }
    }
}
double checkBalance(double balance) {
      return balance;
}
bool deposit(double &balance, double amount) {
    if (amount <= 0.0) return false;
    balance += amount;
    return true;
}
bool withdraw(double &balance, double amount) {
    if (amount <= 0.0 || amount > balance) return false;
    balance -= amount;
    return true;
}
int getMenuChoice() {
    int choice;
       cout << "Enter your choice: ";
    while (!(cin >> choice) || choice < 1 || choice > 4) {
           cout << "Invalid choice. Please enter a number 1-4: ";
           cin.clear();
           cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}
double getPositiveAmount(const std::string &label) {
    double amount;
      cout << "Enter amount to " << label << ": $";
    while (!(cin >> amount) || amount <= 0.0) {
           cout << "Invalid amount. Enter a value greater than $0.00: $";
           cin.clear();
           cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return amount;
}