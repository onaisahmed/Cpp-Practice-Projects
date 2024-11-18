#include <iostream>
using namespace std;

int main() {
    double startBalance, deposits, withdrawals, interestRate, currentBalance;
    
    cout << "Enter the starting balance: $";
    cin >> startBalance;
    
    cout << "Enter total deposits made: $";
    cin >> deposits;
    
    cout << "Enter total withdrawals made: $";
    cin >> withdrawals;
    
    cout << "Enter monthly interest rate (as a percentage): ";
    cin >> interestRate;
    
    currentBalance = startBalance + deposits - withdrawals;
    
    currentBalance += (currentBalance * (interestRate / 100));

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