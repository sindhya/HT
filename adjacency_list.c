#include "main.h"

void add_to_list(adj_node** head,int vertexId,int weight)
{
	adj_node *newNode=(adj_node*)malloc(sizeof(adj_node));
	newNode->vertexId=vertexId;
	newNode->weight=weight;
	newNode->next=(*head);
	(*head)=newNode;
}

void make_adjacency_list(adj_node **adj_list,struct edge* mstedges)
{
	int i,j,other_id;
	for(i=1;i<=vertexId;i++)
	{
		for(j=0;j<mstEdges;j++)
		{
			if(((i==mstedges[j].vertexId1) && (other_id=mstedges[j].vertexId2))||((i==mstedges[j].vertexId2)&& (other_id=mstedges[j].vertexId1)))
			{
				add_to_list(&adj_list[i],other_id,mstedges[j].weight);
			}		
		}
	}
}
void print_adjacency_list(adj_node **adj_list)
{
	int i;
	for(i=1;i<=vertexId;i++)
	{
		adj_node *temp=adj_list[i];
		printf("\nAdjacency list of %s ",vertices[i]);
		while(temp)
		{
			printf(" %s:%d ",vertices[temp->vertexId],temp->weight);
			temp=temp->next;
		}		
	}
}
