#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int k = 0;  // index of last unique element

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[k]) {
            k++;
            nums[k] = nums[i];
        }
    }

    // Print unique elements
    for (int i = 0; i <= k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
