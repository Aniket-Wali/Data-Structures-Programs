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

node* searchTree(node *root, int key){
	if(root == NULL)
		return NULL;
	else if(key == root->data)
		return root;
	else if(key<root->data)
		return searchTree(root->left, key);
	else
		return searchTree(root->right, key);
}

node* tree_Successor(node* root){
	node* current = root; 

	
	while (current->left != NULL) 
		current = current->left; 

	return current; 
}

node* deleteroot(node *root, int key){
	node *temp = searchTree(root, key);
	if(temp==NULL)
		return NULL;
	else{
		if(temp->left == NULL){
			node *t1 = temp->right;
			free(temp);
			return t1;
		}
		else if(temp->right == NULL){
			node *t1 = temp->left;
			free(temp);
			return t1;
		}
		node *t1 = tree_Successor(temp->right);
		temp->data = t1->data;
		temp->right = deleteroot(temp->right, t1->data);
	}
	return temp;
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
	deleteroot(root,1);
	printf("\n");
	inorder(root);
	return 0;
}