#include "main.h"
/*Return the node of the linked list containing the key. If not fonud, return NULL*/
struct edge * llGetEdge(struct llEdgeNode *head,struct edge *key)
{
	struct llEdgeNode *temp;
	temp=head;
	if(!temp)
		return NULL;
	while(temp->next)
	{

		if((temp->edgeInfo->vertexId1==key->vertexId1||temp->edgeInfo->vertexId1==key->vertexId2)&&(temp->edgeInfo->vertexId2==key->vertexId2||temp->edgeInfo->vertexId2==key->vertexId1))
		{
				return temp->edgeInfo;
		}
		temp=temp->next;
	}
	
	if((temp->edgeInfo->vertexId1==key->vertexId1||temp->edgeInfo->vertexId1==key->vertexId2)&&(temp->edgeInfo->vertexId2==key->vertexId2||temp->edgeInfo->vertexId2==key->vertexId1))
		return temp->edgeInfo;
	return NULL;
}

/*Insert the Type A edge in linked list. Return 0 on success and -1 on failure*/
int llEdgeInsert(struct llEdgeNode **head,struct edge *edgeData)
{
	struct llEdgeNode *newEdgeNode=(struct llEdgeNode*)malloc(sizeof(struct llEdgeNode));
	struct edge *newEdge=(struct edge*)malloc(sizeof(struct edge));
	struct edge *temp;

	newEdge->vertexId1=edgeData->vertexId1;
	newEdge->vertexId2=edgeData->vertexId2;
	newEdge->weight=edgeData->weight;
	
	newEdgeNode->edgeInfo=newEdge;
	newEdgeNode->next=NULL;

	if((temp=llGetEdge(*head,edgeData)))
	{
		if(temp->weight!=edgeData->weight)
		{
			temp->weight=edgeData->weight;
		}
		return 0;
	}
	else
	{
		newEdgeNode->next=(*head);
		(*head)=newEdgeNode;
		numEdges++;
		return 0;
	}
	return -1;
}

/*Return the node of the linked list containing the key. If not fonud, return NULL*/
struct vertex * llGetVertex(struct llVertexNode *head,char *vertexName)
{
	struct llVertexNode *temp;
	temp=head;
	if(!temp)
		return NULL;
	while(temp->next)
	{
		if(strcmp(temp->vertexInfo->vertexName,vertexName)==0)
			return temp->vertexInfo;
		temp=temp->next;
	}
	if(strcmp(temp->vertexInfo->vertexName,vertexName)==0)
		return temp->vertexInfo;
	return NULL;
}

/*Insert the Type A edge in linked list. Return 0 on success and -1 on failure*/
int llVertexInsert(struct llVertexNode **head,struct vertex *vertexData)
{
	struct llVertexNode *newVertexNode,*tempNode;
	newVertexNode=(struct llVertexNode*)malloc(sizeof(struct llVertexNode));
	struct vertex *newVertex=(struct vertex*)malloc(sizeof(struct vertex));
	struct vertex *temp;

	strcpy(newVertex->vertexName,vertexData->vertexName);
	newVertexNode->vertexInfo=newVertex;
	newVertexNode->next=NULL;
	
	if((temp=llGetVertex(*head,vertexData->vertexName)))
	{
		return 0;
	}
	else
	{
		vertexId++;
		newVertex->vertexId=vertexId;
		strcpy(vertices[vertexId],newVertex->vertexName);
		if(!*head)
			(*head)=newVertexNode;
		else
		{
			tempNode=*head;
			while(tempNode->next)
			{
				tempNode=tempNode->next;
			}
			tempNode->next=newVertexNode;
		}
		return 0;
	}
	return -1;
}

