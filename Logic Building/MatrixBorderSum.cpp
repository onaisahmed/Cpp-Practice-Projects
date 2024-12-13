#include <iostream>
#include <cmath>
using namespace std;

// Solved by using Matrix Traversal Pattern
int main()
{
    const int SIZE = 3;

    int arr[SIZE][SIZE];
    int sumOfMatrixBorder;

    cout << "Enter values for the array: " << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter values for Row " << i + 1 << ": ";
        for (int j = 0; j < SIZE; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == 0 || i == SIZE - 1 || j == 0 || j == SIZE - 1)
            {
                sumOfMatrixBorder += arr[i][j];
            }
        }
    }

    cout << "Sum of all the elements that lie on the border of Matrix: " << sumOfMatrixBorder << endl;
    return 0;
}