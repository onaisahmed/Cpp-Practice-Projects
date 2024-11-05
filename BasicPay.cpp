#include <iostream>
using namespace std;

int main() {
    double basicPay = 5000.0;
    double bonusRate = 55 / 100;         
    double medicalAllowanceRate = 12.5 / 100; // Converted the percentages when initializing

    double bonus = basicPay * bonusRate;
    double medicalAllowance = basicPay * medicalAllowanceRate;
    double totalMonthlyIncome = basicPay + bonus + medicalAllowance;

    cout << "Basic Pay: $" << basicPay << endl;
    cout << "Bonus Amount: $" << bonus << endl;
    cout << "Medical Allowance: $" << medicalAllowance << endl;
    cout << "Total Monthly Income: $" << totalMonthlyIncome << endl;

    return 0;
}
