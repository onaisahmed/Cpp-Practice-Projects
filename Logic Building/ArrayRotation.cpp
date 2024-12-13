#include <iostream>
using namespace std;

// Solved using Array Manipulation Pattern (Demonstrates cyclic rotation logic using modular arithmetic)
int main()
{
    int SIZE, numOfRotations;
    cout << "Enter size of array" << endl;
    cin >> SIZE;
    cout << "Enter rotation value" << endl;
    cin >> numOfRotations;
    int arr[SIZE];

    cout << "Enter " << SIZE << " elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> arr[i];
    }

    int temp[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        temp[(i + SIZE - numOfRotations) % SIZE] = arr[i];
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;

    return 0;
}