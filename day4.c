#include <stdio.h>

void reverseArray(int* nums, int n) {
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        // Swap elements
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        
        // Move pointers toward each other
        left++;
        right--;
    }
}

int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1) return 0;
    
    int nums[n];
    
    // Read n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    // Reverse in-place
    reverseArray(nums, n);
    
    // Print the result
    for (int i = 0; i < n; i++) {
        printf("%d%s", nums[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");
    
    return 0;
}