#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;

// Creation of Node
struct Node* create(){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    int x;
    printf("Enter the value to enter in the node:\n");
    scanf("%d",&x);
    node->data=x;
    node->next=NULL;
}

// Insertion of Node at Beginning
void insert_at_begin(){
    struct Node* node=create();
    node->next=head;
    head=node;
    printf("Success\n");
}

// Insertion of Node at end
void insert_at_end(){
    if(head==NULL){
        head=create();
        printf("Success\n");
        return;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=create();
    printf("Success\n");
}

// Insertion of Node after specified location
void insert_at_someLocation(){
    struct Node* node=create();
    int loc;
    printf("Enter the location (starting from 1) after which position,node should be inserted:\n");
    scanf("%d",&loc);
    while(loc<1){
        printf("Enter the location (starting from 1) after which position,node should be inserted:\n");
        scanf("%d",&loc);
    }
    if(head==NULL){
       printf("Cannot be inserted\n");
       return;
    }
    struct Node* temp=head;
    if(temp==NULL){
        printf("Cannot be inserted\n");
        return;
    }
    for(int i=0;i<loc-1;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Cannot be inserted\n");
            return;
        }
    }
    node->next=temp->next;
    temp->next=node;
    printf("Success\n");
}

// Deletion of Node at beginning
void delete_at_begin(){
    if(head==NULL){
        printf("Can't be Deleted\n");
        return;
    }
    if(head->next==NULL){
        head=NULL;
        printf("Success\n");
        return;
    }
    head=head->next;
    printf("Success\n");
}

// Deletion of Node at end
void delete_at_end(){
    if(head==NULL){
        printf("Can't be deleted\n");
        return;
    }
    if(head->next==NULL){
        head=NULL;
        printf("Success\n");
        return;
    }
    struct Node* node=head;
    while(node->next!=NULL && node->next->next!=NULL){
        node=node->next;
    }
    node->next=NULL;
    printf("Success\n");
}

// Deletion of Node after specified location
void delete_at_someLocation(){
printf("Enter the location (starting from 1) after which position,node should be deleted:\n");
int loc;
scanf("%d",&loc);
while(loc<1){
    printf("Enter the location (starting from 1) after which position,node should be deleted:\n");
    scanf("%d",&loc);
}
if(head==NULL){
    printf("Can't be Deleted\n");
    return;
}
struct Node* node=head;
for(int i=0;i<loc-1;i++){
    node=node->next;
    if(node==NULL){
        printf("Can't be deleted");
        return;
    }
}
if(node->next==NULL){
    printf("Can't be deleted\n");
    return;
}
if(node->next->next==NULL){
    node->next=NULL;
    printf("Success\n");
    return;
}
node->next=node->next->next;
printf("Success\n");
}
int searchNode(struct Node* node,int val){
    struct Node* temp=node;
    while(temp){
        if(temp->data==val){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

// Printing the Linked List
void print_LinkedList(struct Node* node){
    struct Node* temp=node;
    printf("Current values in the Linked List\n");
    if(temp==NULL){
      printf("None\n");
    }
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
        printf("Following are the choices\n");
        printf("1. Insertion of Node at beginning\n");
        printf("2. Insertion of Node at end\n");
        printf("3. Insertion of Node after specific position\n");
        printf("4. Deletion of Node at beginning\n");
        printf("5. Deletion of Node at the end\n");
        printf("6. Deletion of Node at specific position\n");
        printf("7. Searching of the value in Linked List\n");
        printf("8. Printing of the Linked List\n");
        printf("other than these: Exit\n");
        printf("-----------------------------------\n\n");
        while(1){
            int n,flag=0;
            printf("Choose your option\n");
            scanf("%d",&n);
            switch(n){
                case 1:insert_at_begin();
                       break;
                case 2:insert_at_end();
                       break;
                case 3:insert_at_someLocation();
                       break;
                case 4:delete_at_begin();
                       break;
                case 5:delete_at_end();
                       break;
                case 6:delete_at_someLocation();
                       break;
                case 7:printf("Enter the value to be searched\n");
                       int val;
                       scanf("%d",&val);
                       if(searchNode(head,val)){
                           printf("Element found\n");
                       }else{
                           printf("Element not found\n");
                       }
                       break;
                case 8:print_LinkedList(head);
                       break;
                default:flag=1;
                       printf("Successfully terminated");
                       break;
            }
            if(flag==1){
                break;
            }
        }
}