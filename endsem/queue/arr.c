#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data){
    if(rear == MAX - 1){
        printf("queue overflow");
        return;
    }

    if(front == -1) front = 0;

    queue[++rear] = data;
}

void dequeue(){
    if(front == -1 || front>rear){
        printf("empty queue");
        return;
    }
    front++;
}

int peek(){
    if(front == -1 || front > rear){
        printf("empty queue");
        return -1;
    }

    return queue[front];
}

void print(){
    if(front == -1 || front > rear){
        printf("empty queue");
        return;
    }

    for(int i=front; i<=rear; i++){
        printf("%d", queue[i]);
    }
    printf(" ");
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);

    print();

    dequeue();

    
    print();

    printf("%d", peek());

    return 0;
}