#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double startBalance, deposits, withdrawals, interestRate, currentBalance;
    
    // Get starting balance
    cout << "Enter the starting balance: $";
    cin >> startBalance;
    
    // Get total deposits
    cout << "Enter total deposits made: $";
    cin >> deposits;
    
    // Get total withdrawals
    cout << "Enter total withdrawals made: $";
    cin >> withdrawals;
    
    // Get monthly interest rate
    cout << "Enter monthly interest rate (as a percentage): ";
    cin >> interestRate;
    
    // Calculate balance before interest
    currentBalance = startBalance + deposits - withdrawals;
    
    // Calculate interest and add to balance
    currentBalance += (currentBalance * (interestRate / 100));

    // Display results
    cout << "------------------------" << endl;
    cout << "Account Balance Summary" << endl;
    cout << "------------------------" << endl;
    cout << "Starting Balance: $" << startBalance << endl;
    cout << "Total Deposits: $" << deposits << endl;
    cout << "Total Withdrawals: $" << withdrawals << endl;
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Current Balance: $" << currentBalance << endl;
    
    return 0;
}