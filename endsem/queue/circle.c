#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX];
int rear = -1;
int front = -1;

int isFull(){
    return (rear + 1) % MAX == front;
}

int isEmpty(){
    return front == -1;
}

void enqueue(int data){
    if(isFull()){
        printf("queue overflow");
        return;
    }

    if(front == -1){
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = data;
}

void dequeue(){
    if(isEmpty()){
        printf("queue underflow");
        return;
    }

    if(front == rear){
        front = rear = -1;
        return;
    }

    front = (front + 1) % MAX;
}

void print(){
    if(isEmpty()){
        printf("empty queue");
        return;
    }

    int i = front;

    while(1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }

    printf(" ");
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