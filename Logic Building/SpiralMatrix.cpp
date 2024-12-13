#include <iostream>
using namespace std;

// Solved using Matrix Traversal Pattern
int main()
{
    int SIZE;
    cout << "Enter size of matrix: ";
    cin >> SIZE;
    int arr[SIZE][SIZE];
    int top = 0, bottom = SIZE - 1, left = 0, right = SIZE - 1;
    int direction = 0;
    int i;

    cout << "Enter values for the matrix: " << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter values for Row " << i + 1 << ": ";
        for (int j = 0; j < SIZE; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (top <= bottom && left <= right)
    {
        if (direction == 0)
        {
            for (i = left; i <= right; i++)
            {
                cout << arr[top][i] << " ";
            }
            top++;
        }
        else if (direction == 1)
        {
            for (i = top; i <= bottom; i++)
            {
                cout << arr[i][right] << " ";
            }
            right--;
        }
        else if (direction == 2)
        {
            for (i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }
        else if (direction == 3)
        {
            for (i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
    cout << endl;
    return 0;
}