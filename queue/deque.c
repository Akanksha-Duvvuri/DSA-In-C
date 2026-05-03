#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty(){
    return front == NULL;
}

void insertFront(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = front;

    if(isEmpty()){
        front = rear = newNode;
    }
    else{
        front->prev = newNode;
        front = newNode;
    }
}

void insertRear(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = rear;

    if(isEmpty()){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void deleteFront(){
    if(isEmpty()){
        printf("Deque Underflow\n");
        return;
    }

    struct Node* temp = front;

    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
}

void deleteRear(){
    if(isEmpty()){
        printf("Deque Underflow\n");
        return;
    }

    struct Node* temp = rear;

    if(front == rear){
        front = rear = NULL;
    }
    else{
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);
}

void print(){
    if(isEmpty()){
        printf("Deque is empty\n");
        return;
    }

    struct Node* temp = front;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main(){
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);

    print();

    deleteFront();
    deleteRear();

    print();

    insertRear(30);
    insertFront(1);

    print();

    return 0;
}