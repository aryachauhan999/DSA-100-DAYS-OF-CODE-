#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list ahead by diff
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Move both pointers together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp1 = NULL, *temp2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head1 == NULL) {
            head1 = newNode;
            temp1 = head1;
        } else {
            temp1->next = newNode;
            temp1 = newNode;
        }
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head2 == NULL) {
            head2 = newNode;
            temp2 = head2;
        } else {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    // Find intersection
    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}