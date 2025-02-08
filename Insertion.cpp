#include <stdio.h>
void insertElement(int arr[], int size, int pos, int value) {
    if (pos < 0 || pos > size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = value;
    printf("Array after insertion: ");
    for (int i = 0; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, pos, value;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to insert an element : ", n);
    scanf("%d", &pos);

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    insertElement(arr, n, pos, value);

    return 0;
}

