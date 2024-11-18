#include <iostream>
using namespace std;

int main() {
    double furnitureCost, paintingCost, displayBoardCost, totalCost;

    cout << "Enter the cost of the furniture: $";
    cin >> furnitureCost;

    cout << "Enter the cost of painting the shop: $";
    cin >> paintingCost;

    cout << "Enter the cost of the display board: $";
    cin >> displayBoardCost;

    // Calculating the total cost spent on renovation here
    totalCost = furnitureCost + paintingCost + displayBoardCost;

    cout << "Total amount spent on renovation: $" << totalCost << endl;

    return 0;
}
