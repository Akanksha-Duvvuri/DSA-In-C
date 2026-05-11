#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

Node* createnode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void push(int data){
    Node* newnode = createnode(data);

    newnode->next = top;
    top = newnode;
}

void pop(){
    if(top == NULL){
        printf("empty stack");
        return;
    }

    Node* temp = top;
    top = top->next;

    free(temp);
}

int peek(){
    if(top == NULL){
        printf("empty stack");
        return -1;
    }

    return top->data;
}

void display() {
    Node* temp = top;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("NULL ");

}


int main(){
    push(3);
    push(2);
    push(1);

    display();

    pop();

    display();

    printf("%d", peek());

    display();

    return 0;
}