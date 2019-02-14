#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct BST node;
struct BST
{
	char data[20];
	node *left;
	node *right;
};

node* insert(node *root, char *item){
	if(root==NULL){
		node *temp = (node*)malloc(sizeof(node));
		strcpy(temp->data, item);
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	int comp = strcmp(item, root->data);
	if(comp < 1)
		root->left = insert(root->left, item);
	else
		root->right = insert(root->right, item);
	return root;
}
void inorder(node *root){
	if(root->right!=NULL){
		inorder(root->left);
		printf("%s  ",root->data);
		inorder(root->right);
	}
}

int main(int argc, char const *argv[])
{
	node *root = NULL;
	char str[80], *ptr;
	fgets(str, 80, stdin);
	ptr = strtok (str," ");
	if(root == NULL)
		root = insert(root, ptr);
	while (ptr != NULL)
  	{
    	insert(root, ptr);
    	ptr = strtok (NULL, " ");
 	}
	inorder(root);
	return 0;
}