#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100003   // Prime number for better hashing

// Node for linked list (separate chaining)
typedef struct Node {
    long long key;          // prefix sum
    long long count;        // frequency
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

// Hash function
int hash(long long key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

// Insert or update frequency
long long insert(long long key) {
    int index = hash(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            temp->count++;
            return temp->count - 1;  // return previous count
        }
        temp = temp->next;
    }

    // Not found, create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *arr = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    long long prefix_sum = 0;
    long long result = 0;

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    // Important: prefix sum 0 occurs once
    insert(0);

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        result += insert(prefix_sum);
    }

    printf("%lld\n", result);

    free(arr);
    return 0;
}