#include "stack.h"


void push(SNode** head,int data)
{
        SNode *newnode=(SNode*)malloc(sizeof(SNode));
        newnode->vertexId=data;
        newnode->next=(*head);
        (*head)=newnode;
}

int pop(SNode** head)
{
	int data;
        SNode *temp;
        temp=(*head);
        data=temp->vertexId;
        (*head)=(*head)->next;
        free(temp);
        return data;
}
int isEmpty(SNode *head)
{
	if(!head)
		return 1;
	else
		return 0;
}
int peek(SNode *head)
{
	return head->vertexId;
}
