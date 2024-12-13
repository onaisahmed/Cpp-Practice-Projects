#include <iostream>
using namespace std;

// Solved using Mathematical and Recursive Pattern
int main()
{
    int SIZE;
    cout << "Enter size of Pascal's Triangle: ";
    cin >> SIZE;
    int arr[SIZE][SIZE];
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}