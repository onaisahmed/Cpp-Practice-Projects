#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

void inputMatrix(int rows, int cols, int matrix[][10], const string& name) {
    cout << "Enter elements of " << name << " (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

int findBiggestNumber(int rows, int cols, int matrix[][10]) {
    int maxNum = INT_MIN; // Initialize to the smallest integer
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > maxNum) {
                maxNum = matrix[i][j];
            }
        }
    }
    return maxNum;
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input for first matrix
    cout << "Enter rows and columns for the first matrix: ";
    cin >> rows1 >> cols1;
    int matrix1[10][10]; // Assuming maximum size is 10x10
    inputMatrix(rows1, cols1, matrix1, "Matrix 1");

    // Input for second matrix
    cout << "Enter rows and columns for the second matrix: ";
    cin >> rows2 >> cols2;
    int matrix2[10][10]; // Assuming maximum size is 10x10
    inputMatrix(rows2, cols2, matrix2, "Matrix 2");

    // Find the largest number in both matrices
    int max1 = findBiggestNumber(rows1, cols1, matrix1);
    int max2 = findBiggestNumber(rows2, cols2, matrix2);

    // Determine the overall largest number
    int biggestNumber = max(max1, max2);
    cout << "The biggest number in the merged matrices is: " << biggestNumber << endl;

    return 0;
}
