#include <stdio.h>

void deleteElement(int arr[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Array after deletion: ");
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, pos;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete an element (0 to %d): ", n-1);
    scanf("%d", &pos);

    deleteElement(arr, n, pos);

    return 0;
}

