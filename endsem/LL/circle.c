#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node; 

Node* head = NULL;
Node* tail = NULL;

Node* createnode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void pushfront(int data){
    Node* newnode = createnode(data);

    if(head == NULL){
        head = tail = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

int isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            printf("cycle exists");
            return 1;
        }
    }
    printf("cycle doesnt exist");
    return 0;
}

void removeCycle(struct Node* headNode){
    struct Node* slow = headNode;
    struct Node* fast = headNode;
    int cycleFound = 0;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cycleFound = 1;
            break;
        }
    }

    if(cycleFound == 0){
        printf("Cycle doesn't exist\n");
        return;
    }

    // Case 1: cycle starts at head
    if(slow == headNode){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    // Case 2: cycle starts elsewhere
    else{
        slow = headNode;          // reset slow to head
        
        while(slow->next != fast->next){  // ✅ FIXED
            slow = slow->next;
            fast = fast->next;
        }
        
        fast->next = NULL;        // break the cycle
    }
    
    printf("Cycle removed\n");
}

int main(){
    pushfront(4);
    pushfront(3);
    pushfront(2);
    pushfront(1);

    tail->next = head;

    removeCycle(head);
    print(head);
    return 0;
}