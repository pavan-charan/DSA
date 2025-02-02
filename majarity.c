#include <stdio.h>
#include <stdlib.h>

// Node structure for the BST
typedef struct Node {
    int value;
    int count;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the BST
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    } else {
        root->count++;
    }

    return root;
}

// Function to find the majority element in the BST
int findMajorityElement(Node* root, int size) {
    int candidate = -1;
    int count = 0;

    while (root != NULL) {
        if (root->count > count) {
            candidate = root->value;
            count = root->count;
        }

        if (count > size / 2) {
            return candidate;
        }

        if (root->left != NULL) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return -1; // no majority element found
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int* cards = (int*)malloc(size * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &cards[i]);
    }

    Node* root = NULL;

    // Insert all elements into the BST
    for (int i = 0; i < size; i++) {
        root = insertNode(root, cards[i]);
    }

    int majorityElement = findMajorityElement(root, size);

    if (majorityElement != -1) {
        printf("A majority element exists: %d\n", majorityElement);
    } else {
        printf("No majority element found.\n");
    }

    free(cards);

    return 0;
}