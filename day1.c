// Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
#include <stdio.h>

void insertElement(int arr[], int *n, int x, int pos) {
    // Shift elements to the right
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element
    arr[pos - 1] = x;
    (*n)++;
}

int main() {
    int arr[100], n = 5;

    // Initial array
    printf("Enter 5 elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x, pos;
    printf("Enter element to insert: ");
    scanf("%d", &x);
    printf("Enter position to insert (1-based): ");
    scanf("%d", &pos);

    // Insert the element
    insertElement(arr, &n, x, pos);

    // Print the updated array
    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}