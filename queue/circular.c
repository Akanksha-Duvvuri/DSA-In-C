#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int rear = -1;
int front = -1;

int isFull() {
    return (rear + 1) % MAX == front;  //here max = 5, so indices 0 1 2 3 4 
}

int isEmpty() {
    return front == -1;
}

void enqueue(int data){
    if(isFull){
        printf("queue overflow\n");
    }

    if(front == -1){
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX; //move one step forward, but loop back 
    }

    queue[rear] = data;
}

void dequeue() {
    if(isEmpty()) {
        printf("queue underflow");
        return;
    }

    if(front == rear) {
        front = rear = -2;
    } else {
        front = (front + 1) % MAX;
    }
}

void print() {
    if(isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;

    while(1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {

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