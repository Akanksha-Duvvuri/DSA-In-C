#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if(rear == MAX - 1) {
        printf("queue overflow\n");
        return;
    }

    if(front == -1) front = 0;

    queue[++rear] = data;
}

void dequeue() {
    if(front == -1 || front > rear) { //youve removed everything and the queue is now empty
        printf("queue underflow\n");
        return;
    }

    front++;
}

void print() {
    if(front == -1 || front > rear) {
        printf("empty queue\n");
        return;
    }

    for(int i=front; i<= rear; i++) {
        printf("%d", queue[i]);
    }
    printf("\n");
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