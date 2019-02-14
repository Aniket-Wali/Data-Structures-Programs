#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct BST node;
struct BST
{
	char data;
	node *left;
	node *right;
};

int compare(char s1, char s2){
	if(s1 > s2)
		return 1;
	else if(s1 < s2)
		return -1;
	else
		return 0;
}

node* insert(node *root, char item){
	if(root==NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = item;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	int comp = compare(item, root->data);
	if(comp < 1)
		root->left = insert(root->left, item);
	else
		root->right = insert(root->right, item);
	return root;
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%c  ",root->data);
		inorder(root->right);
	}
}



int main(int argc, char const *argv[])
{
	node *root = NULL;
	char str[80], *ptr;
	scanf("%s", str);
 	for (int i = 0; i < strlen(str); i++)
 	{
 		if(root == NULL)
 			root = insert(root, str[i]);
 		else
 			insert(root, str[i]);
 	}
	inorder(root);
	return 0;
}