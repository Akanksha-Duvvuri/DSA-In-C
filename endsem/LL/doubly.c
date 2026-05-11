#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createnode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

void insertatbeg(int data){
     Node* newnode = createnode(data);

    if(head == NULL) {
        head = tail = newnode;
    }else{
        newnode->next = head;
        head->prev=newnode;
        head = newnode;
    }
}

void insertatend(int data){
    Node* newnode = createnode(data);

    if(head == NULL) {
        head = tail = newnode;
    }else{
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteatbeg(){
    if(head == NULL){
        printf("empty LL");
    }

    Node* temp = head;
   
    head = head->next;
    head->prev = NULL;

    free(temp);
}

void deleteatend(){
    if(head == NULL){
        printf("empty LL");
    }

    Node* temp = tail;
   
    tail = tail->prev;
    tail->next = NULL;

    free(temp);
}

void print() {
    Node* temp = head;

    while(temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

int main(){
    insertatbeg(3);
    insertatbeg(2);
    insertatbeg(1);
    
    print();

    insertatend(1);

    print();

    deleteatbeg();

    print();

    deleteatend();
    
    print();
    return 0;
}