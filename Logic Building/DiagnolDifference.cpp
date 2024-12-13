#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int SIZE = 3;

    int arr[SIZE][SIZE];
    int diagnol1, diagnol2;

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
            if (i == j)
            {
                diagnol1 += arr[i][j];
            }
            if (i + j == SIZE - 1)
            {
                diagnol2 += arr[i][j];
            }
        }
    }
    cout << "The difference of diagnols is: " << abs((diagnol1 - diagnol2)) << endl;
    return 0;
}