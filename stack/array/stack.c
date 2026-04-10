#include<stdio.h>
//using arrays
#define MAX 100

int stack[MAX]; //how you define an array right? same thing
int top = -1; //means stack is empty

void push(int x) {
    if(top == MAX - 1){ //checks if the stack is full - 0 base indexing so max - 1
        printf("stack overflow\n"); //its full
    } 
    stack[++top] = x; //initially top is -1 right, so ++-1 = 0 ka index mei lagalo x ka value
}

void pop() {
    if(top == -1) {
        printf("stack undeflow\n"); //empty
    }

    printf("popped\n", stack[top--]); //say top is 2nd index - do top--, its gonne become the first index, so it gets popped
}

void peek() {
    if(top == -1) {
        printf("empty stack\n");
    }

    printf("peek: %d", stack[top]);
}

void display() {
    for(int i=top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main(){
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    peek();

    // display();

    return 0;
}