#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;
    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    int x = front->data;
    struct node *temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return x;
}

int main() {
    int choice, val;
    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                printf("\nDequeued Element is: %d\n", dequeue());
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);
    return 0;
}
