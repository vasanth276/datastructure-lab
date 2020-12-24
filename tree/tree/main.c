//
//  main.c
//  tree
//
//  Created by Vasanth Kumar on 23/12/20.
//

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* create(int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void insert(struct node *root,struct node *temp){
    if(temp->data<root->data){
        if(root->left!=NULL){
            insert(root->left,temp);
        }
        else{
            root->left=temp;
        }
    }
    else{
        if(root->right!=NULL){
            insert(root->right,temp);
        }
        else{
            root->right=temp;
        }
    }
}
void inorder(struct node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void prorder(struct node *root){
    if(root==NULL)
        return;
    printf("%d",root->data);
    prorder(root->left);
    prorder(root->right);
}
void posorder(struct node *root){
    if(root==NULL)
        return;
    posorder(root->left);
    posorder(root->right);
    printf("%d",root->data);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int opt,data;
    struct node *root=NULL;
    while(1){
        printf("1.insert node\n");
        printf("2.inorder traversal\n");
        printf("3.preorder traversal\n");
        printf("4.postorder traversal\n");
        printf("5.exit\n");
        printf("enter the option : ");
        scanf("%d",& opt);
        switch(opt){
            case 1 :
                printf("enter the the node data : ");
                scanf("%d",& data);
                if(root==NULL){
                    root=create(data);
                }
                else{
                    insert(root,create(data));
                }
            case 2 :
                if(root==NULL){
                    printf("tree is empty\n");
                }
                else{
                    printf("tree contains : ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3 :
                if(root==NULL){
                    printf("tree is empty\n");
                }
                else{
                    printf("tree contains : ");
                    prorder(root);
                    printf("\n");
                }
                break;
            case 4 :
                if(root==NULL){
                    printf("tree is empty\n");
                }
                else{
                    printf("tree contains : ");
                    posorder(root);
                    printf("\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("invalid option\n");
        }
    }
    return 0;
}
