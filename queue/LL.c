#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

// create node
Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void enqueue(int data) {
    Node* newnode = createNode(data);

    if(rear == NULL) {
        rear = front = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    if(front == NULL){
        printf("empty queue\n");
        return;
    }

    Node* temp = front;
    front = front->next;

    free(temp);
}

void print() {
    Node* temp = front;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    print();

    dequeue();

    print();

    return 0;
}