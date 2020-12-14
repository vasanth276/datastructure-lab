#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL;
void add_at_begin( ){
    struct node *ptr = NULL;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("enter the node data :");
    scanf("%d",& ptr->data);
    ptr->prev=NULL;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
    }
    else{
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
}


void delete_at_specifiedloc( ){
    int i,loc;
    if(head==NULL){
        printf("empty list\n");
    }
    else{
        struct node *ptr=head;
        printf("enter the location :");
        scanf("%d",& loc);
        for(i=1;i<loc;i++){
            ptr=ptr->next;
        }
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
    }
}
void display( ){
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
        struct node *temp=head;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(int argc, const char * argv[]) {
    int opt=0;
    // insert code here...
    while(1){
        printf("DOUBLY LINKED LIST\n");
        printf("1.add_at_begin\n");


        printf("2.delete_at_pos\n");
        printf("3.display\n");
        printf("enter the option :");
        scanf("%d",& opt);
        switch(opt){
            case 1:
                add_at_begin();
                break;

            case 2:
                delete_at_specifiedloc();
                break;
            case 3:
                display();
                break;
            default:
                printf("invalid option\n");
        }
    }
    return 0;
}
