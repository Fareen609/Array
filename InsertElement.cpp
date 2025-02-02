#include <stdio.h>

void insertElement(int arr[], int n, int element, int index) {
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
}

int main() {
    int arr[100], n, element, index;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert the element (0 to %d): ", n);
    scanf("%d", &index);
    if (index < 0 || index > n) {
        printf("Invalid index!\n");
        return 1;
    }
    insertElement(arr, n, element, index);
    printf("Array after insertion:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

