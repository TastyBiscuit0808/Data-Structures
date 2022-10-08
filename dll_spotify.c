#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t *temp;
	temp=(node_t*)malloc(sizeof(node_t));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	if(list->head==NULL)
	{
		list->head = temp;
		list->tail = temp;
	}
	else
	{
		list->head->prev=temp;
		temp->next=list->head;
		list->head=temp;
	}
	list->size+= 1;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t *temp,*cur=list->head;
	temp=(node_t*)malloc(sizeof(node_t));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	if(list->head==NULL)
	{
		list->head=temp;
		list->tail = temp;
	}
	else
	{
		(list->tail)->next = temp;
		temp->prev = list->tail;
		list->tail = temp;
		// while(cur->next!=NULL)
		// {
        //     cur=cur->next;
        // }
        // cur->next=temp;
        // temp->prev=cur;
	}
		list->size+=1;

}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
    node_t *item=list->head;
    node_t *p=NULL;
    node_t *temp;
    temp=(node_t*)malloc(sizeof(node_t));
	temp->data=data;

	while(item!=NULL && item->data!=prev)
	{
		p=item;
		item=item->next;
	}
	temp->next=item->next;
	item->next=temp;
	temp->prev=item;
	if(temp->next!=NULL)
	{ 
		temp->next->prev=temp;
	}
	list->size+=1;  
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
    node_t *temp;
    if((list->head)->next==NULL)
	{
        free(list->head);
        list->head=NULL;
		free(list->tail);
		list->tail=NULL;
    }
    else
	{
        temp=list->head;
        list->head->next->prev=NULL;
        list->head=(list->head)->next;
        free(temp);
    }
    if(list->size>0)
	{
		list->size-=1;
	}
	// return(temp);

}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
    
    // node_t *temp,*cur=list->head;
    if(list->head->next==NULL)
    {
        free(list->head);
        list->head=NULL;
		free(list->tail);
		list->tail = NULL;
    }
    else
	{
		node_t *temp = list->tail;
		(list->tail) = (list->tail)->prev;
		free(temp);
    }
	if(list->size>0)
	{
		list->size-=1;
	}

}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	node_t *item=list->head;
    node_t *p=NULL;
    node_t *temp;
    temp=(node_t*)malloc(sizeof(node_t));
	temp->data=data;
 
	if(item->data == data){
		delete_front(list);
	}
	else
	{
		while(item!=NULL && item->data!=data)
		{
		p = item;
		item = item->next;
		}
		item->prev->next = item->next;
		item->next->prev = item->prev;
		free(item);
	}
	if(list->size>0)
	{
		list->size-=1;
	}

}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{	
	node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
	temp = list->head;
	while(temp!=NULL)
	{
		if(temp->data == data)
		{
			return temp;
		}
		temp = temp->next;
	}
	if(temp == NULL){
		return NULL;
	}
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
   
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

// int main(){
//     //printf("HI" );
//     list_t *l1=create_list();
// 	node_t *k;
//     insert_front(l1,10);
//     insert_front(l1,222);
//     insert_front(l1,22);
//     insert_back(l1,110);
// 	// printf("\n SIze is %d\n",size(l1));
//     insert_back(l1,8);
// 	printf("\n SIze is %d\n",size(l1));
//     insert_front(l1,99999);

// 	insert_after(l1,3,10);
// 	// display_list(l1);
// 	// printf("\n SIze is %d\n",size(l1));
// 	// //k=search(l1,110);
// 	// //printf("pointer k data is %d\n",search(l1,11011)->data);

// 	// delete_node(l1,22);
// 	// delete_front(l1);
// 	delete_back(l1);
// 	printf("tail is %d\n",l1->tail->data);

// 	// delete_back(l1);
//     // display_list(l1);
// 	// if(is_empty(l1)){
// 	// 	printf("Empty list");
// 	// }
// 	// printf("\n SIze is %d\n",size(l1));
// }
