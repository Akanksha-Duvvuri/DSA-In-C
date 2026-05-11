#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff;    // coefficient
    int expo;     // exponent/power
    struct Node* next;
};

struct Node* createNode(int coeff, int expo) {
    struct Node* newNode = 
        (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->expo  = expo;
    newNode->next  = NULL;
    return newNode;
}


int main(){

    return 0;
}
