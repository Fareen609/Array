#include <stdio.h>
#define MAX 10 
void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int firstRows, int firstCols, int secondRows, int secondCols) {
    for (int i = 0; i < firstRows; i++) {
        for (int j = 0; j < secondCols; j++) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < firstRows; i++) {
        for (int j = 0; j < secondCols; j++) {
            for (int k = 0; k < firstCols; k++) {
                result[i][j] += first[i][k] * second[k][j]; 
            }
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
    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];
    int firstRows, firstCols, secondRows, secondCols;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &firstRows, &firstCols);
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < firstRows; i++) {
        for (int j = 0; j < firstCols; j++) {
            scanf("%d", &first[i][j]);
        }
    }
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &secondRows, &secondCols);
    if (firstCols != secondRows) {
        printf("Matrix multiplication is not possible. The number of columns in the first matrix must equal the number of rows in the second matrix.\n");
        return 1;
    }
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < secondRows; i++) {
        for (int j = 0; j < secondCols; j++) {
            scanf("%d", &second[i][j]);
        }
    }
    multiplyMatrices(first, second, result, firstRows, firstCols, secondRows, secondCols);
    printf("\nResultant Matrix after multiplication:\n");
    display(result, firstRows, secondCols);

    return 0;
}

