#include <iostream>
#include <vector>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(std::string accNumber, std::string accHolderName)
        : accountNumber(accNumber), accountHolderName(accHolderName), balance(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " into account " << accountNumber << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from account " << accountNumber << std::endl;
        } else {
            std::cout << "Insufficient balance or invalid withdrawal amount." << std::endl;
        }
    }

    void checkBalance() {
        std::cout << "Account " << accountNumber << " balance: $" << balance << std::endl;
    }

    std::string getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    std::vector<BankAccount> accounts;

    while (true) {
        std::cout << "Bank Account Management System" << std::endl;
        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Check Balance" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                {
                    std::string accNumber, accHolderName;
                    std::cout << "Enter account number: ";
                    std::cin >> accNumber;
                    std::cout << "Enter account holder name: ";
                    std::cin >> accHolderName;
                    accounts.push_back(BankAccount(accNumber, accHolderName));
                    std::cout << "Account created successfully." << std::endl;
                }
                break;

            case 2:
                {
                    std::string accNumber;
                    double amount;
                    std::cout << "Enter account number: ";
                    std::cin >> accNumber;
                    std::cout << "Enter deposit amount: $";
                    std::cin >> amount;
                    for (auto &account : accounts) {
                        if (account.getAccountNumber() == accNumber) {
                            account.deposit(amount);
                            break;
                        }
                    }
                }
                break;

            case 3:
                {
                    std::string accNumber;
                    double amount;
                    std::cout << "Enter account number: ";
                    std::cin >> accNumber;
                    std::cout << "Enter withdrawal amount: $";
                    std::cin >> amount;
                    for (auto &account : accounts) {
                        if (account.getAccountNumber() == accNumber) {
                            account.withdraw(amount);
                            break;
                        }
                    }
                }
                break;

            case 4:
                {
                    std::string accNumber;
                    std::cout << "Enter account number: ";
                    std::cin >> accNumber;
                    for (auto &account : accounts) {
                        if (account.getAccountNumber() == accNumber) {
                            account.checkBalance();
                            break;
                        }
                    }
                }
                break;

            case 5:
                std::cout << "Exiting program." << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
