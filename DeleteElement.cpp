#include <stdio.h>

void deleteElement(int arr[], int n, int index) {
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int main() {
    int arr[100], n, index;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position to delete the element (0 to %d): ", n - 1);
    scanf("%d", &index);
    if (index < 0 || index >= n) {
        printf("Invalid index!\n");
        return 1;
    }
    deleteElement(arr, n, index);
    printf("Array after deletion:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

