#include <stdio.h>

// Add two 2x2 matrices
void add(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Subtract two 2x2 matrices
void sub(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Multiply two 2x2 matrices (normal)
void multiply2(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            C[i][j] = 0;
            for(int k=0;k<2;k++)
                C[i][j] += A[i][k]*B[k][j];
        }
    }
}

int main() {
    int A[4][4], B[4][4], C[4][4];

    printf("Enter elements of Matrix A (4x4):\n");
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter elements of Matrix B (4x4):\n");
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            scanf("%d", &B[i][j]);

    // Divide matrices
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+2];
            A21[i][j] = A[i+2][j];
            A22[i][j] = A[i+2][j+2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+2];
            B21[i][j] = B[i+2][j];
            B22[i][j] = B[i+2][j+2];
        }
    }

    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];
    int T1[2][2], T2[2][2];

    // Strassen formulas
    add(A11, A22, T1);
    add(B11, B22, T2);
    multiply2(T1, T2, M1);

    add(A21, A22, T1);
    multiply2(T1, B11, M2);

    sub(B12, B22, T2);
    multiply2(A11, T2, M3);

    sub(B21, B11, T2);
    multiply2(A22, T2, M4);

    add(A11, A12, T1);
    multiply2(T1, B22, M5);

    sub(A21, A11, T1);
    add(B11, B12, T2);
    multiply2(T1, T2, M6);

    sub(A12, A22, T1);
    add(B21, B22, T2);
    multiply2(T1, T2, M7);

    int C11[2][2], C12[2][2], C21[2][2], C22[2][2];

    add(M1, M4, T1);
    sub(T1, M5, T2);
    add(T2, M7, C11);

    add(M3, M5, C12);
    add(M2, M4, C21);

    sub(M1, M2, T1);
    add(T1, M3, T2);
    add(T2, M6, C22);

    // Combine result
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            C[i][j] = C11[i][j];
            C[i][j+2] = C12[i][j];
            C[i+2][j] = C21[i][j];
            C[i+2][j+2] = C22[i][j];
        }
    }

    // Output
    printf("\nResult Matrix:\n");
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}