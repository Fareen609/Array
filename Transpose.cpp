#include <stdio.h>
#define MAX 10 
void transpose(int matrix[MAX][MAX], int res[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[j][i] = matrix[i][j];
        }
    }
}
void display(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int matrix[MAX][MAX], result[MAX][MAX];
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nOriginal Matrix:\n");
    display(matrix, rows, cols);
    transpose(matrix, result, rows, cols);
    printf("\nTransposed Matrix:\n");
    display(result, cols, rows);
    return 0;
}

