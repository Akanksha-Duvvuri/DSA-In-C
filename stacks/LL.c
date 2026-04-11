#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL; 

Node* createnode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("memory allocation failed\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void push(int data) {
    Node* newnode = createnode(data);

    newnode->next = top;
    top = newnode;
}

void pop() {
    Node* temp = top;

    top = top->next;
    free(temp);
}

int peek() {
    if(top == NULL) {
        printf("empty stack\n");
        return -1;
    }

    printf("%d\n", top->data);
}

void display() {
    Node* temp = top;

    while(temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

}

int main() {

    push(3);
    push(2);
    push(1);

    display();

    pop();

    display();

    peek();

    // display();

    return 0;
}