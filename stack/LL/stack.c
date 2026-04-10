#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int x) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop(){
    Node* temp = top;

    if(top == NULL) {
        printf("empty stack");
    }

    top = top->next; //make the next one as top and then free the temp
    free(temp);
}

void peek() {
    if(top == NULL) {
        printf("empty stack");
    }

    printf("peek: %d", top->data);
}


void display() {
    Node* temp = top;

    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    push(1);
    push(2);
    push(3);

    display();

    pop();
    display();

    peek();
    return 0;
}