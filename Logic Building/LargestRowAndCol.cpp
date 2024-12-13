#include <iostream>
using namespace std;

int main()
{
    int SIZE = 3;
    int arr[SIZE][SIZE];

    cout << "Enter the elements of the 2D array: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter the elements of row " << i + 1 << ": ";
        for (int j = 0; j < SIZE; j++)
        {
            cin >> arr[i][j];
        }
    }

    int maxRowSum = 0;
    int maxRow = -1;
    for (int i = 0; i < SIZE; i++)
    {
        int sum = 0;
        for (int j = 0; j < SIZE; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxRowSum)
        {
            maxRowSum = sum;
            maxRow = i + 1;
        }
    }

    int maxColSum = 0;
    int maxCol = -1;
    for (int j = 0; j < SIZE; j++)
    {
        int sum = 0;
        for (int i = 0; i < SIZE; i++)
        {
            sum += arr[i][j];
        }
        if (sum > maxColSum)
        {
            maxColSum = sum;
            maxCol = j + 1;
        }
    }

    cout << "Max Row " << maxRow << " with sum of: " << maxRowSum << endl;
    cout << "Max Col " << maxCol << " with sum of: " << maxColSum << endl;

    return 0;
}