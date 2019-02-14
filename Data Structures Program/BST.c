#include<stdio.h>
#include<stdlib.h>
typedef struct BST node;
struct BST
{
	int data;
	node *left;
	node *right;
};

node* insert(node *root, int item){
	if(root==NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = item;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	if(item < root->data)
		root->left = insert(root->left, item);
	else
		root->right = insert(root->right, item);
	return root;
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
	}
}

int searchTree(node *root, int key){
	if(root == NULL)
		return 0;
	else if(key == root->data)
		return 1;
	else if(key<root->data)
		return searchTree(root->left, key);
	else
		return searchTree(root->right, key);
}

int main(int argc, char const *argv[])
{
	int key;
	node *root = NULL;
	root = insert(root, 10);
	insert(root, 5);
	insert(root, 1);
	insert(root, 7);
	insert(root, 40);
	insert(root, 50);
	inorder(root);
	/*printf("\n");
	scanf("%d", &key);
	if(searchTree(root, key))
		printf("Search Successful\n");
	else
		printf("Search Unsuccessful\n");*/
	return 0;
}