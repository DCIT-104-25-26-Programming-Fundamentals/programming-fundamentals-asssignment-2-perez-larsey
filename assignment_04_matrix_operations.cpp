// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void transpose(int matrix[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int m, int n, int p, int result[10][10]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matrix[10][10], result[10][10];
    int rows, cols;

    // ---------------- PART A: Transpose ----------------
    cout << "=== Part A: Transpose ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix, rows, cols);

    cout << endl << "Original Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    transpose(matrix, rows, cols, result);

    cout << endl << "Transposed Matrix:" << endl;
    printMatrix(result, cols, rows); // note: dimensions flip

    // ---------------- PART B: Addition ----------------
    cout << endl << "=== Part B: Addition ===" << endl;
    int matrixA[10][10], matrixB[10][10], sumResult[10][10];
    int addRows, addCols;

    cout << "Enter number of rows: ";
    cin >> addRows;
    cout << "Enter number of columns: ";
    cin >> addCols;

    cout << "Matrix A:" << endl;
    readMatrix(matrixA, addRows, addCols);

    cout << "Matrix B:" << endl;
    readMatrix(matrixB, addRows, addCols);

    addMatrices(matrixA, matrixB, addRows, addCols, sumResult);

    cout << endl << "Sum of Matrices:" << endl;
    printMatrix(sumResult, addRows, addCols);

    // ---------------- PART C: Multiplication ----------------
    cout << endl << "=== Part C: Multiplication ===" << endl;
    int matrixC[10][10], matrixD[10][10], productResult[10][10];
    int m, n, n2, p;

    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A (N): ";
    cin >> n;

    cout << "Matrix A:" << endl;
    readMatrix(matrixC, m, n);

    cout << "Enter columns of Matrix B (P): ";
    cin >> p;
    n2 = n; // rows of B must equal columns of A

    cout << "Matrix B:" << endl;
    readMatrix(matrixD, n2, p);

    multiplyMatrices(matrixC, matrixD, m, n, p, productResult);

    cout << endl << "Product of Matrices:" << endl;
    printMatrix(productResult, m, p);

    return 0;
}