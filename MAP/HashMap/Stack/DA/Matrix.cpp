#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 10

void inputMatrix(double mat[MAX][MAX], int r, int c, char name) {
    cout << "\nEnter elements of Matrix " << name << ":\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << "Element [" << i+1 << "][" << j+1 << "] : ";
            cin >> mat[i][j];
        }
    }
}

void displayMatrix(double mat[MAX][MAX], int r, int c) {
    cout << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << setw(10) << fixed << setprecision(2) << mat[i][j] << " ";
        cout << endl;
    }
}

void addMatrix(double A[MAX][MAX], double B[MAX][MAX], int r, int c) {
    double result[MAX][MAX];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            result[i][j] = A[i][j] + B[i][j];

    cout << "\nAddition Result:";
    displayMatrix(result, r, c);
}

void subtractMatrix(double A[MAX][MAX], double B[MAX][MAX], int r, int c) {
    double result[MAX][MAX];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            result[i][j] = A[i][j] - B[i][j];

    cout << "\nSubtraction Result:";
    displayMatrix(result, r, c);
}

void multiplyMatrix(double A[MAX][MAX], double B[MAX][MAX], int r1, int c1, int c2) {
    double result[MAX][MAX] = {0};

    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++)
            for(int k = 0; k < c1; k++)
                result[i][j] += A[i][k] * B[k][j];

    cout << "\nMultiplication Result:";
    displayMatrix(result, r1, c2);
}

void transposeMatrix(double A[MAX][MAX], int r, int c) {
    double result[MAX][MAX];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            result[j][i] = A[i][j];

    cout << "\nTranspose of Matrix A:";
    displayMatrix(result, c, r);
}

bool inverseMatrix(double A[MAX][MAX], int n) {
    double aug[MAX][2*MAX];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            aug[i][j] = A[i][j];
        for(int j = n; j < 2*n; j++)
            aug[i][j] = (i == j-n) ? 1 : 0;
    }

    for(int i = 0; i < n; i++) {

        if(aug[i][i] == 0) {
            for(int k = i+1; k < n; k++) {
                if(aug[k][i] != 0) {
                    for(int j = 0; j < 2*n; j++)
                        swap(aug[i][j], aug[k][j]);
                    break;
                }
            }
        }

        if(aug[i][i] == 0)
            return false;

        double pivot = aug[i][i];
        for(int j = 0; j < 2*n; j++)
            aug[i][j] /= pivot;

        for(int k = 0; k < n; k++) {
            if(k != i) {
                double factor = aug[k][i];
                for(int j = 0; j < 2*n; j++)
                    aug[k][j] -= factor * aug[i][j];
            }
        }
    }

    cout << "\nInverse of Matrix A:\n";
    for(int i = 0; i < n; i++) {
        for(int j = n; j < 2*n; j++)
            cout << setw(10) << fixed << setprecision(2) << aug[i][j] << " ";
        cout << endl;
    }

    return true;
}

int main() {

    double A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2, choice;

    cout << "Enter number of rows for Matrix A: ";
    cin >> r1;
    cout << "Enter number of columns for Matrix A: ";
    cin >> c1;

    cout << "\nEnter number of rows for Matrix B: ";
    cin >> r2;
    cout << "Enter number of columns for Matrix B: ";
    cin >> c2;

    if(r1 > MAX || c1 > MAX || r2 > MAX || c2 > MAX) {
        cout << "\nMatrix size exceeds maximum limit (" << MAX << ").\n";
        return 0;
    }

    inputMatrix(A, r1, c1, 'A');
    inputMatrix(B, r2, c2, 'B');

    do {
        cout << "\n========== MATRIX OPERATIONS ==========\n";
        cout << "1. Addition (A + B)\n";
        cout << "2. Subtraction (A - B)\n";
        cout << "3. Multiplication (A x B)\n";
        cout << "4. Transpose of A\n";
        cout << "5. Inverse of A\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if(r1 == r2 && c1 == c2)
                    addMatrix(A, B, r1, c1);
                else
                    cout << "\nAddition not possible (Dimensions must be same).\n";
                break;

            case 2:
                if(r1 == r2 && c1 == c2)
                    subtractMatrix(A, B, r1, c1);
                else
                    cout << "\nSubtraction not possible (Dimensions must be same).\n";
                break;

            case 3:
                if(c1 == r2)
                    multiplyMatrix(A, B, r1, c1, c2);
                else
                    cout << "\nMultiplication not possible (Columns of A must equal rows of B).\n";
                break;

            case 4:
                transposeMatrix(A, r1, c1);
                break;

            case 5:
                if(r1 == c1) {
                    if(!inverseMatrix(A, r1))
                        cout << "\nInverse not possible (Matrix is singular).\n";
                } else
                    cout << "\nInverse not possible (Matrix A must be square).\n";
                break;

            case 6:
                cout << "\nThank you! Program ended successfully.\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while(choice != 6);

    return 0;
}