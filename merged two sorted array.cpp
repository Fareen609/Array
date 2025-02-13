#include <stdio.h>
#include <stdlib.h>

void merge(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge the two arrays
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy any remaining elements from arr1
    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    // Copy any remaining elements from arr2
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int N1, N2;

    // Get sizes of both arrays
    printf("Enter size of first array (N1): ");
    scanf("%d", &N1);
    printf("Enter size of second array (N2): ");
    scanf("%d", &N2);

    int *arr1 = (int *)malloc(N1 * sizeof(int));
    int *arr2 = (int *)malloc(N2 * sizeof(int));
    int *merged = (int *)malloc((N1 + N2) * sizeof(int));

    // Input elements for the first array
    printf("Enter elements of the first array (sorted):\n");
    for (int i = 0; i < N1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input elements for the second array
    printf("Enter elements of the second array (sorted):\n");
    for (int i = 0; i < N2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merge the two sorted arrays
    merge(arr1, N1, arr2, N2, merged);

    // Output the merged array
    printf("Merged array:\n");
    for (int i = 0; i < N1 + N2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
    return 0;
}


