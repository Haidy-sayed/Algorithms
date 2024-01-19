#include <bits/stdc++.h>
using namespace std;

/**
 * implement the naive matrix multiplication algorithm
 * 
 * @param
 *  a --> a 2d vector
 *  b --> a 2d vector
 * 
 * @return
 * the result of a*b "matrix multiplcation"
*/
vector<vector<int>> naive(vector<vector<int>> a, vector<vector<int>> b){
}
#define R1 4            // number of rows in Matrix-1
#define C1 4            // number of columns in Matrix-1
#define R2 4            // number of rows in Matrix-2
#define C2 4            // number of columns in Matrix-2

void mulMat(int matrix1[R1][C1], int matrix2[R2][C2]) {
    int matrixMultip[R1][C2];
 
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            matrixMultip[i][j] = 0;
 
            for (int k = 0; k < R2; k++) {
                matrixMultip[i][j] += matrix1[i][k] * matrix2[k][j];
            }
 
            cout << matrixMultip[i][j] << "  ";
        }
 
        cout << endl;
    }
}
 
int main(void) {
    // Square Matrices
    // R1 = 4, C1 = 4 and R2 = 4, C2 = 4 (Update these values in MACROs)
    int mat1[R1][C1] = {
            {7, 1, 1, 1},
            {2, 5, 2, 2},
            {3, 3, 3, 3},
            {4, 9, 4, 4}
    };
 
    int mat2[R2][C2] = {
            {1, 8, 1, 1},
            {2, 0, 2, 2},
            {3, 3, 5, 3},
            {4, 2, 4, 4}
    };
 
    /*
    // Rectangular Matrices
    // R1 = 3, C1 = 4 and R2 = 4, C2 = 3 (Update these values in MACROs)
    int mat1[R1][C1] = {
                {1, 1, 1, 1},
                {2, 2, 2, 2},
                {3, 3, 3, 3}
    };
 
    int mat2[R2][C2] = {
                {1, 1, 1},
                {2, 2, 2},
                {3, 3, 3},
                {4, 4, 4}
    };
    */
 
    if (C1 != R2) {
        cout << "The number of columns in Matrix-1  must be equal to the number of rows in "
                "Matrix-2" << endl;
        cout << "Please update MACROs according to your array dimension in #define section"
                << endl;
 
        exit(EXIT_FAILURE);
    }
 
    mulMat(mat1, mat2);
 
    return 0;
}