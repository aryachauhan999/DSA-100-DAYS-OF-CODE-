#include <stdio.h>

void mergeLogs(int* log1, int p, int* log2, int q) {
    int i = 0, j = 0;

    // While both logs have elements remaining
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    // Print remaining elements from log1, if any
    while (i < p) {
        printf("%d%s", log1[i], (i == p - 1 && j == q) ? "" : " ");
        i++;
    }

    // Print remaining elements from log2, if any
    while (j < q) {
        printf("%d%s", log2[j], (j == q - 1) ? "" : " ");
        j++;
    }
    printf("\n");
}

int main() {
    int p, q;

    // Server 1 Input
    if (scanf("%d", &p) != 1) return 0;
    int log1[p];
    for (int i = 0; i < p; i++) scanf("%d", &log1[i]);

    // Server 2 Input
    if (scanf("%d", &q) != 1) return 0;
    int log2[q];
    for (int i = 0; i < q; i++) scanf("%d", &log2[i]);

    mergeLogs(log1, p, log2, q);

    return 0;
}