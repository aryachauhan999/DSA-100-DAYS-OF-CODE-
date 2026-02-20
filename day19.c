#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n < 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = INT_MAX;
    int first = arr[0], second = arr[1];

    // Step 2: Two-pointer search
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            first = arr[left];
            second = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", first, second);

    return 0;
}