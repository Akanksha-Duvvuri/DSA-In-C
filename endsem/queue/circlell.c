#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* front = NULL;
Node* rear = NULL;

Node* createNode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->next = NULL;
}

int isEmpty(){
    return front == NULL;
}

void enqueue(int data){
    Node* newnode = createNode(data);

    if(isEmpty()){
        front = rear = newnode;
        rear->next = front;
    } else {
        newnode->next = front;
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("empty queue");
        return;
    }

    Node* temp = front;
    front = front->next;
    rear->next = front;
    free(temp);
}

void print(){
     if(isEmpty()){
        printf("Queue is empty");
        return;
    }

    Node* temp = front;

    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != front);

    printf("\n");
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    print();

    dequeue();
    dequeue();

    print();

    enqueue(5);
    enqueue(6);

    print();
    return 0;
}