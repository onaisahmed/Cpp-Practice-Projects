#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib> // For system("clear") or system("cls")

using namespace std;

// ANSI color codes for CLI
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Function to clear the screen
void clearScreen() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux/Mac
#endif
}

// Function to pause before clearing the screen
void pauseScreen() {
    cout << YELLOW << "\nPress Enter to continue..." << RESET;
    cin.ignore();
    cin.get();
    clearScreen();
}

// Function to display a decorated heading
void displayHeading(const string &heading) {
    cout << CYAN << "=========================================" << RESET << endl;
    cout << BLUE << "          " << heading << RESET << endl;
    cout << CYAN << "=========================================" << RESET << endl;
    cout << endl;
}

// Function to display a separator
void displaySeparator() {
    cout << CYAN << "-----------------------------------------" << RESET << endl;
}

// Function to get current timestamp
string getCurrentTimestamp() {
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", localtime(&now));
    return string(buf);
}

// Account structure
struct Account {
    string accountNumber;
    string name;
    string password;
    double balance;
    vector<string> transactions;
};

// Function to create a new account
void createAccount() {
    clearScreen();
    displayHeading("CREATE A NEW ACCOUNT");

    Account account;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, account.name);
    cout << "Enter a password: ";
    cin >> account.password;
    cout << "Enter initial deposit: $";
    cin >> account.balance;

    // Generate unique account number
    account.accountNumber = to_string(time(0));

    // Save account to file
    ofstream file(account.accountNumber + ".txt");
    file << account.name << endl;
    file << account.password << endl;
    file << account.balance << endl;
    file.close();

    cout << GREEN << "\nAccount created successfully!" << RESET << endl;
    cout << "Your account number is: " << YELLOW << account.accountNumber << RESET << endl;
    displaySeparator();
    pauseScreen();
}

// Function to load account from file
bool loadAccount(const string &accountNumber, Account &account) {
    ifstream file(accountNumber + ".txt");
    if (!file.is_open()) return false;

    getline(file, account.name);
    getline(file, account.password);
    file >> account.balance;

    string transaction;
    getline(file, transaction); // Skip to transactions
    while (getline(file, transaction)) {
        account.transactions.push_back(transaction);
    }

    file.close();
    account.accountNumber = accountNumber;
    return true;
}

// Function to save account to file
void saveAccount(const Account &account) {
    ofstream file(account.accountNumber + ".txt");
    file << account.name << endl;
    file << account.password << endl;
    file << account.balance << endl;
    for (const string &transaction : account.transactions) {
        file << transaction << endl;
    }
    file.close();
}

// Function to handle login
bool login(Account &account) {
    clearScreen();
    displayHeading("LOGIN TO YOUR ACCOUNT");

    string accountNumber, password;
    cout << "Enter your account number: ";
    cin >> accountNumber;
    cout << "Enter your password: ";
    cin >> password;

    if (!loadAccount(accountNumber, account)) {
        cout << RED << "Error: Account not found!" << RESET << endl;
        pauseScreen();
        return false;
    }

    if (account.password != password) {
        cout << RED << "Error: Invalid password!" << RESET << endl;
        pauseScreen();
        return false;
    }

    cout << GREEN << "\nLogin successful!" << RESET << endl;
    cout << "Welcome, " << YELLOW << account.name << RESET << "!" << endl;
    displaySeparator();
    pauseScreen();
    return true;
}

// Function to deposit money
void depositMoney(Account &account) {
    clearScreen();
    displayHeading("DEPOSIT MONEY");

    double amount;
    cout << "Enter the amount to deposit: $";
    cin >> amount;

    account.balance += amount;
    account.transactions.push_back("Deposit: +" + to_string(amount) + " at " + getCurrentTimestamp());
    cout << GREEN << "\nDeposit successful!" << RESET << endl;
    cout << "New balance: $" << fixed << setprecision(2) << account.balance << endl;
    displaySeparator();
    pauseScreen();
}

// Function to check balance
void checkBalance(const Account &account) {
    clearScreen();
    displayHeading("CHECK BALANCE");
    cout << "Your current balance is: $" << fixed << setprecision(2) << account.balance << endl;
    displaySeparator();
    pauseScreen();
}


// Function to withdraw money
void withdrawMoney(Account &account) {
    clearScreen();
    displayHeading("WITHDRAW MONEY");

    double amount;
    cout << "Enter the amount to withdraw: $";
    cin >> amount;

    if (amount > account.balance) {
        cout << RED << "Error: Insufficient balance!" << RESET << endl;
        pauseScreen();
        return;
    }

    account.balance -= amount;
    account.transactions.push_back("Withdrawal: -" + to_string(amount) + " at " + getCurrentTimestamp());
    cout << GREEN << "\nWithdrawal successful!" << RESET << endl;
    cout << "New balance: $" << fixed << setprecision(2) << account.balance << endl;
    displaySeparator();
    pauseScreen();
}

// Function to send money
void sendMoney(Account &account) {
    clearScreen();
    displayHeading("SEND MONEY");

    string recipientAccountNumber;
    double amount;

    cout << "Enter the recipient's account number: ";
    cin >> recipientAccountNumber;
    cout << "Enter the amount to send: $";
    cin >> amount;

    if (amount > account.balance) {
        cout << RED << "Error: Insufficient balance!" << RESET << endl;
        pauseScreen();
        return;
    }

    Account recipient;
    if (!loadAccount(recipientAccountNumber, recipient)) {
        cout << RED << "Error: Recipient account not found!" << RESET << endl;
        pauseScreen();
        return;
    }

    account.balance -= amount;
    recipient.balance += amount;

    string timestamp = getCurrentTimestamp();
    account.transactions.push_back("Sent: -" + to_string(amount) + " to " + recipient.name + " at " + timestamp);
    recipient.transactions.push_back("Received: +" + to_string(amount) + " from " + account.name + " at " + timestamp);

    saveAccount(account);
    saveAccount(recipient);

    cout << GREEN << "\nMoney sent successfully!" << RESET << endl;
    cout << "New balance: $" << fixed << setprecision(2) << account.balance << endl;
    displaySeparator();
    pauseScreen();
}

// Function to view transaction history
void viewTransactionHistory(const Account &account) {
    clearScreen();
    displayHeading("TRANSACTION HISTORY");

    if (account.transactions.empty()) {
        cout << YELLOW << "No transactions available." << RESET << endl;
    } else {
        for (const string &transaction : account.transactions) {
            cout << transaction << endl;
        }
    }
    displaySeparator();
    pauseScreen();
}

// Main menu and program flow remain unchanged.


// Main menu
void mainMenu(Account &account, bool &loggedIn) {
    while (!loggedIn) {
        clearScreen();
        displayHeading("MAIN MENU");
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        displaySeparator();
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                if (login(account)) loggedIn = true;
                break;
            case 3:
                cout << GREEN << "Thank you for using EasyBank CLI!" << RESET << endl;
                exit(0);
            default:
                cout << RED << "Invalid choice! Please try again." << RESET << endl;
        }
    }
}

// Logged-in menu
void loggedInMenu(Account &account) {
    while (true) {
        clearScreen();
        displayHeading("USER MENU");
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Send Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Transaction History" << endl;
        cout << "6. Logout" << endl;
        displaySeparator();
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                depositMoney(account);
                break;
            case 2:
                withdrawMoney(account);
                break;
            case 3:
                sendMoney(account);
                break;
            case 4:
                checkBalance(account);
                break;
            case 5:
                viewTransactionHistory(account);
                break;
            case 6:
                return; // Logout and return to main menu
            default:
                cout << RED << "Invalid choice! Please try again." << RESET << endl;
        }
    }
}

// Main function
int main() {
    Account account;
    bool loggedIn = false;

    while (true) {
        if (!loggedIn) {
            mainMenu(account, loggedIn);
        } else {
            loggedInMenu(account);
            loggedIn = false; // Reset login state after logout
        }
    }

    return 0;
}
