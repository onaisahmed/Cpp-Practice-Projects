#include <iostream>
using namespace std;

int main() {
    double productionCost = 14.95;
    double profitRate = 35 / 100;  // Converted the percentage when initializing, so it = 0.35

    double sellingPrice = productionCost * (1 + profitRate);

    cout << "The selling price for a 35% profit should be: $" << sellingPrice << endl;

    return 0;
}
