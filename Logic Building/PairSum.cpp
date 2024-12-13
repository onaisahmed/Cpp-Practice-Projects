#include <iostream>
using namespace std;

// Solved using Two Pointer Pattern
int main()
{
    int SIZE, sum, target;
    cout << "Enter size of array: ";
    cin >> SIZE;
    cout << "Enter target value: ";
    cin >> target;
    int arr[SIZE];

    cout << "Enter " << SIZE << " elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << "Pair found at index " << i << " and " << j << endl;
                return 0;
            }
        }
    }

    cout << "Pair not found" << endl;

    return 0;
}