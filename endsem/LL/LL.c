#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->next = NULL;
}

void insertatbeg(int data){
    Node* newnode = createNode(data);

    if(head == NULL){
        head = tail = newnode;
    }else {
        newnode->next = head;
        head = newnode;
    }
}

void insertatend(int data){
    Node* newnode = createNode(data);

    Node* temp = head;

    if(head == NULL){
        head = tail = newnode;
    } 

    while(temp != NULL){
        temp = temp->next;
    }

    tail->next = newnode;
    tail = newnode;
}

void insertatpos(int data, int position){
    Node* newnode = createNode(data);

    Node* temp = head;

    for(int i=0; i<position; i++){
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteatbeg(){
    if(head == NULL){
        printf("empty LL");
    }

    Node* temp = head;

    head = head->next;
    temp->next = NULL;

    free(temp);
}

void deleteatend(){
    if(head == NULL){
        printf("empty LL");
    }

    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    tail = temp;
}

void deleteatpos(int pos){
    Node* temp = head;

    for(int i=0; i<pos; i++){
        temp = temp->next;
    }

    temp->next = temp->next->next;
}

void reverseLL(){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    tail = head;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

}

void display(){
    if(head == NULL){
        printf("empty LL");
    }

    Node* temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    insertatbeg(5);
    insertatbeg(3);
    insertatbeg(2);

    display();

    insertatend(6);

    display();

    insertatpos(4, 2);

    display();

    deleteatend();

    display();

    deleteatbeg();

    display();

    deleteatpos(2);

    display();

    reverseLL();

    display();
    return 0;
}