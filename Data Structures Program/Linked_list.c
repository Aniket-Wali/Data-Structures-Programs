#include<stdio.h>
#include<stdlib.h>
struct my_node
{
	int data;
	struct my_node *next;
};
typedef struct my_node node;
/******************************************************

initialize function will initialize the start pointer to NULL which implies that list is Empty.

*******************************************************/
void initialize(node *start){
	start = NULL;
}
/******************************************************

Now here comes the insert function.
first it will insert the very first node to the Linked List.
initially we create a node pointer and put the data to that node pointer.
Make n1->next to NULL and then point the address of n1(i.e first node) to start->next pointer.

*start pointer          *n1 node
-----------          --------------
|    |*next| -------->| data | *next |-------> NULL  
-----------          --------------

*******************************************************/
void insert(node *start, int item){
	node *n1 = (node*)malloc(sizeof(node)); 	// Creating the node.
	n1->data = item;		// Inserting data into node.
	n1->next = NULL;		// Making node next pointer to NULL.
	start->next = n1;		//Visualise the upper diagram.
}
/******************************************************

Here comes the insertAtLast function which will insert the data after the last node of Linked List.
first we will traverse(move) through each node of list until we find that node which is pointing the NULL(i.e last node).
when we find the last node we begin to insert the node at last.
we create the temp pointer to store the start->next(i.e address of first node of list) and then traverse through all node 
using while loop.

*start pointer           										         *n1 pointer(insert after previous node)
-----------          ----------------          ---------------           ----------------
|    |*next| -------->| data | *next |------->| data | *next |---------->| data | *next  |-----------> NULL      
-----------          ----------------          ---------------           ----------------

Here *temp will move until it find the node which is pointing to NULL. 

*******************************************************/
void insertAtLast(node *start, int item){
	node* temp = start->next;	// making temp pointer for storing the start of list so that original start won't affect.
	while(temp->next!=NULL){	// Loop run until it found the node which is pointing the NULL which will be last node of list.
		temp = temp->next;	
	}
	node* n1 = (node*)malloc(sizeof(node)); // creating another node which will join the last node of previous list.
	temp->next = n1;		// Joining the n1 node to the list.
	n1->data = item;		// inserting the data to n1 node.
	n1->next = NULL;		// pointing n1->next to NULL 
}
/******************************************************

insertAfteri function will insert  after the i'th node.
It is very much similar to insertAtLast function but the difference is that here the *temp pointer will traverse the list
upto where it find the i'th element node by using temp->data!=i in while loop.

*start pointer           										         
-----------         --------------                    ---------------           ----------------
|    |*next| ----->| data | *next |----*	       	 | data | *next |---------->| data | *next  |-----------> NULL      
-----------         --------------     |              ---------------           ----------------
					                  \|/             /|\
                                  ---------------      |
                                 | data | *next  |-----*
                                  ---------------
								    *n1 pointer

*******************************************************/
void insertAfteri(node *start, int item, int i){
	node *temp = start->next;
	while(temp->data!=i){	// Traverse upto that node where it find the i'th element.
		temp = temp->next;
	}
	node *n1 = (node*)malloc(sizeof(node));
	n1->data = item;
	n1->next = temp->next;
	temp->next = n1;
}
/******************************************************

DeleteFirstNode function will delete the first node of the linked list.
for eg we have a list like :  start--->10--->20--->30---->40--->NULL.
then this function will store the start->next into temp pointer. 
Then pointing start to second node i.e 20 by start->next = start->next->next.
Then we will free(temp) and list becomes : start--->20--->30---->40--->NULL.

*******************************************************/
void DeleteFirstNode(node *start){
	if(start!=NULL){
		node *temp = start->next;	// temp will point the very first node of the list by assiging temp = start->next.
		start->next = start->next->next; // start points to second node of the list.
		free(temp); 
	}
}
/******************************************************

Twinkle comments likne me bht time lg rha hai. itna sb upr k comments lkhne m mjh 1hr lg gya.
mne baaki sb functions to smjha diye h nd ye wala jo hai tm ek baar smjo nd mjh call krke pch lena ki kse chal rha h ye.
vse tmko smjh aa jaayega i know.😅😅😅

*******************************************************/
void DeleteAti(node *start, int i){
	node *temp = start->next;
	while(temp->next->data!=i){
		temp = temp->next;
	}
	node *ref = temp->next;
	temp->next = temp->next->next;
	free(ref);
}

void printList(node* start){
	node* temp = start->next;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next;
		/*if(temp==NULL)
			printf("NULL");*/
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	node start;
	initialize(&start);
	insert(&start, 11);
	for (int i = 2; i <=10; ++i)
	{
		insertAtLast(&start, i);
	}
	printList(&start);
	insertAfteri(&start, 12, 4);
	printList(&start);
	DeleteFirstNode(&start);
	printList(&start);
	DeleteAti(&start, 12);
	printList(&start);
	return 0;
}