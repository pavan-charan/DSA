#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL; // Initialize the next pointer

    if (front == NULL) {
        front = newnode;
        rear = newnode;
        rear->next = front;
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
    printf("Enqueued..!\n");
}

void dequeue() {
    if (rear == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node *temp = front;
        if (front == rear) { // Only one element
            front = NULL;
            rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
        }
        free(temp);
        printf("Dequeued..!\n");
    }
}

void display() {
    if (rear == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node *temp = front;
        printf("Elements in Circular Queue are: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main() {
    int x, choice;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
