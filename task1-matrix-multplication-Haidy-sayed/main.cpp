
#include <iostream>
#include <vector>
using namespace std;
 
// declaration of matrices dimensions
#define R1 4            // number of rows in matrix_1
#define C1 4            // number of columns in matrix_1_1
#define R2 4            // number of rows in matrix_2
#define C2 4            // number of columns in matrix_2
// naiive matrix multiplication algorithm
vector<vector<int>> naiveMulMat(vector<vector<int>> matrix_1, vector<vector<int>> matrix_2) {
    vector<vector<int>> naiveMatrixMultip (C1 , vector<int> (R2));
    cout << "Multiplication of given two matrices is:\n" << endl;
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            naiveMatrixMultip[i][j] = 0;
            for (int k = 0; k < R2; k++) {
                naiveMatrixMultip[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
            cout << naiveMatrixMultip[i][j] << "\t";
        }
        cout << endl;
    }
    return naiveMatrixMultip;
}
vector<vector<int>> add(vector< vector<int> > matrixA, vector< vector<int> > matrixB,unsigned int mSize) {
        vector<vector<int>> addition(mSize, vector<int>(mSize));
        for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            addition[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return addition;
}

// subtract two matrices
vector<vector<int>> sub(vector< vector<int> > matrixA, vector< vector<int> > matrixB, unsigned int mSize) {
    vector<vector<int>> subtract(mSize, vector<int>(mSize));
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            subtract[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return subtract;
}

//Strassen matrix multiplication function
vector<vector<int>> strassenMatMul(vector<vector<int>> matrixA, vector<vector<int>> matrixB, unsigned int size){
    vector<vector<int>> strassenMatricMultip(C1 , vector<int> (size));
    //base case matrix 1X1
    if (size == 1) {
        strassenMatricMultip[0][0] = matrixA[0][0] * matrixB[0][0];
        return strassenMatricMultip;
    }
    else if(size%2 !=0){
        std::cout << "Strassen matrix multiplication can only be applied to matrices with size that is devisivle by 2" << std::endl;
    }
    else {
        int newMSize = size / 2;
        vector<int> innerVector(newMSize, 0);

        // initialize matrices
        vector< vector<int> > matrixA11(newMSize, innerVector),
                            matrixA12(newMSize, innerVector),
                            matrixA21(newMSize, innerVector),
                            matrixA22(newMSize, innerVector),
                            matrixB11(newMSize, innerVector),
                            matrixB12(newMSize, innerVector),
                            matrixB21(newMSize, innerVector),
                            matrixB22(newMSize, innerVector),
                            matrixC11(newMSize, innerVector),
                            matrixC12(newMSize, innerVector),
                            matrixC21(newMSize, innerVector),
                            matrixC22(newMSize, innerVector),
                            s1(newMSize, innerVector),
                            s2(newMSize, innerVector),
                            s3(newMSize, innerVector),
                            s4(newMSize, innerVector),
                            s5(newMSize, innerVector),
                            s6(newMSize, innerVector),
                            s7(newMSize, innerVector),
                            s8(newMSize, innerVector),
                            s9(newMSize, innerVector),
                            s10(newMSize, innerVector),
                            p1(newMSize, innerVector),
                            p2(newMSize, innerVector),
                            p3(newMSize, innerVector),
                            p4(newMSize, innerVector),
                            p5(newMSize, innerVector),
                            p6(newMSize, innerVector),
                            p7(newMSize, innerVector),
                            tempMatrixA(newMSize, innerVector),
                            tempMatrixB(newMSize, innerVector);

        // divide matrices into 4 submatrices
        for (int i = 0; i < newMSize; i++) {
            for (int j = 0; j < newMSize; j++) {
                matrixA11[i][j] = matrixA[i][j];
                matrixA12[i][j] = matrixA[i][j + newMSize];
                matrixA21[i][j] = matrixA[i + newMSize][j];
                matrixA22[i][j] = matrixA[i + newMSize][j + newMSize];

                matrixB11[i][j] = matrixB[i][j];
                matrixB12[i][j] = matrixB[i][j + newMSize];
                matrixB21[i][j] = matrixB[i + newMSize][j];
                matrixB22[i][j] = matrixB[i + newMSize][j + newMSize];
            }
            // s1 = b12 - b22
        s1=sub(matrixB12, matrixB22, newMSize);

        // s2 = a11 + a12
        s2=add(matrixA11, matrixA12, newMSize);

        // s3 = a21 + a22
        s3=add(matrixA21, matrixA22, newMSize);

        // s4 = b21 - b11
        s4=sub(matrixB21, matrixB11, newMSize);

        // s5 = a11 + a22
        s5=add(matrixA11, matrixA22, newMSize);

        // s6 = b11 + b22
        s6=add(matrixB11, matrixB22, newMSize);

        // s7 = a12 - a22
        s7=sub(matrixA12, matrixA22, newMSize);

        // s8 = b21 + b22
        s8=add(matrixB21, matrixB22, newMSize);

        // s9 = a11 - a21
        s9=sub(matrixA11, matrixA21, newMSize);

        // s10 = b11 + b12
        s10=add(matrixB11, matrixB12, newMSize);

        // p1 = a11 * s1
        p1=strassenMatMul(matrixA11, s1, newMSize);

        // p2 = s2 * b22
        p2= strassenMatMul(s2, matrixB22, newMSize);

        // p3 = s3 * b11
        p3= strassenMatMul(s3, matrixB11, newMSize);

        // p4 = a22 * s4
        p4=strassenMatMul(matrixA22, s4, newMSize);

        // p5 = s5 * s6
        p5=strassenMatMul(s5, s6, newMSize);

        // p6 = s7 * s8
        p6= strassenMatMul(s7, s8, newMSize);

        // p7 = s9 * s10
        p7= strassenMatMul(s9, s10 , newMSize);

        // c11 = p5 + p4 - p2 + p6
        tempMatrixA=add(p5, p4, newMSize); // p5 + p4
        tempMatrixB=add(tempMatrixA, p6, newMSize); // (p5 + p4) + p6
        matrixC11=sub(tempMatrixB, p2, newMSize); // (p5 + p4 + p6) - p2

        // c12 = p1 + p2
        matrixC12=add(p1, p2, newMSize);

        // c21 = p3 + p4
        matrixC21=add(p3, p4, newMSize);

        // c22 = p5 + p1 - p3 + p7
        tempMatrixA =add(p5, p1, newMSize); // p5 + p1
        tempMatrixB=sub(tempMatrixA, p3, newMSize); // (p5 + p1) - p3
        matrixC22=sub(tempMatrixB, p7, newMSize); // (p5 + p1 - p3) - p7

        // group into matrixC
        for (int i = 0; i < newMSize ; i++) {
            for (int j = 0 ; j < newMSize ; j++) {
                strassenMatricMultip[i][j] = matrixC11[i][j];
                strassenMatricMultip[i][j + newMSize] = matrixC12[i][j];
                strassenMatricMultip[i + newMSize][j] = matrixC21[i][j];
                strassenMatricMultip[i + newMSize][j + newMSize] = matrixC22[i][j];
            }

        }
        }
    }
    return strassenMatricMultip;
}
//Display of a matrix function
void matDisplay(vector<vector<int>> matrix){
    for(int k=0;k<R1;k++){
        for(int m=0;m<C1;m++){
            std::cout << matrix[k][m] << '\t';
        }
        std::cout<<std::endl;
    }
}
//Matrix generating function
vector<vector<int>> matGenerate(int R, int C){
    vector<vector<int>> matrixGen(R, vector<int>(C));
    for(int i=0;i<R1;i++){
        for(int j=0;j<C1;j++){
            matrixGen[i][j]=rand()%9;
        }
    }
    return matrixGen;
}

int main(void) {
    // definition of the 2 matrices
    vector<vector<int>> matrix_1(R1, vector<int>(C1));
    vector<vector<int>> matrix_2(R2, vector<int>(C2));
    vector<vector<int>> strass_result(R1, vector<int>(C1));
    vector<vector<int>> naiive_result(R1, vector<int>(C2));
    //Genraating 2 random Matrices
    matrix_1=matGenerate(R1,C1);
    matrix_2=matGenerate(R2,C2);

    if (C1 != R2) {
        cout << "The number of columns in matrix_1  must be equal to the number of rows in "
                "matrix_2" << endl;
        exit(EXIT_FAILURE);
    }
    //Displaying the content of the 2 Matrices

    std::cout << "Matrix_1 content" << std::endl;
    matDisplay(matrix_1);
    std::cout << "Matrix_2 content" << std::endl;
    matDisplay(matrix_2);
    naiive_result =naiveMulMat(matrix_1, matrix_2);
    std::cout << "strassenMatricMultip" << std::endl;
    strass_result=strassenMatMul(matrix_1,matrix_2,R1);
    matDisplay(strass_result);
    if (strass_result == naiive_result)
        {
            std::cout << "equivalent result ";
        }
        else
        {
            cout << "error, check your inputs and algortihms " << endl;
            // you may want to store your variables in a file to re-run the test on the same inputs;
        }
    
    return 0;
}