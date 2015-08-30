#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	struct node *right;
	int data;
};

void insertNode(struct node **root, int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	if(*root == NULL){	
		temp->data = data;
		*root = temp;
		return;
	}
	else if((*root)->data >= data){
		insertNode(&((*root)->left), data);
	}
	else{
		insertNode(&((*root)->right), data);
	}

}

void inOrder(struct node *root){
	if(root == NULL) return;
	inOrder(root->left);
	printf("%d\t",root->data);
	inOrder(root->right);
}

void preOrder(struct node *root){
	if(root ==NULL) return;
	printf("%d\t",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	int i =0;
	struct node *root = (struct node *)malloc(sizeof(struct node));
	insertNode(&root, 5);
	insertNode(&root, 3);
	insertNode(&root, 8);
	insertNode(&root, 1);
	insertNode(&root, 2);
	insertNode(&root, 9);
	inOrder(root);
	preOrder(root);
}
