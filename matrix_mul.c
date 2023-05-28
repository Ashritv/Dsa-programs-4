#include <stdio.h>

void read_matrix(int (*m)[100], int r, int c) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

void print_matrix(int (*m)[100], int r, int c) {
    printf("The matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrix(int (*m1)[100], int (*m2)[100], int (*res)[100], int r1, int c1, int r2, int c2) {
    if (c1 != r2)
    {
        printf("Error: matrices cannot be multiplied\n");
        return;
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;
    int m1[100][100], m2[100][100], res[100][100];

    printf("Enter n0. of rows and columns of matrix 1\n");
    scanf("%d %d", &r1, &c1);
    read_matrix(m1, r1, c1);
    printf("Enter no. of rows and columns of matrix 2\n");
    scanf("%d %d", &r2, &c2);
    read_matrix(m2, r2, c2);

    if (c1 != r2) {
        printf("Matrices cannot be multiplied\n");
        return 1;
    }

    multiply_matrix(m1, m2, res, r1, c1, r2, c2);

    print_matrix(res, r1, c2);

    return 0;
}
