#include "main.h"
/*Allocate the memory and initialize the hash table.*/
void edgeHashInit(struct edgeHashTable *edgeHash)
{
	int i;
	for(i=0;i<MAXBUCKETS;i++)
	{	
		edgeHash->buckets[i]=NULL;
	}
}

/*Use your own hash function to calculate the hash value*/
int calcEdgeHash( char* vertex1,char* vertex2)
{
	int hash=7;
	char *temp1;
	char *temp2;
	temp1=vertex1;
	temp2=vertex2;


	while(*temp1)
	{
		hash+=((*temp1)*7);
		temp1++;
	}
	hash=hash%97;
	while(*temp2)
	{
		hash+=((*temp2)*7);
		temp2++;
	}
	return hash%97;
}

/*Insert the Type A edge in hash table. Return 0 on success and -1 on failure*/
int edgeHashInsert(struct edgeHashTable *edgeHash, struct edge *data)
{
	int eHash;
	eHash=calcEdgeHash(vertices[data->vertexId1],vertices[data->vertexId2]);

	return llEdgeInsert(&edgeHash->buckets[eHash],data);
}

/*Search the given edge. If it is found return a pointer to the edge. If not found return NULL*/
struct edge * edgeHashSearch(struct edgeHashTable *edgeHash,struct edge *key)
{
	int eHash;
	struct llEdgeNode *temp;

	eHash=calcEdgeHash(vertices[key->vertexId1],vertices[key->vertexId2]);
	temp=edgeHash->buckets[eHash];
	if(!temp)
		return NULL;
	while(temp->next)
	{
		if((temp->edgeInfo->vertexId1==key->vertexId1||temp->edgeInfo->vertexId1==key->vertexId2)&&(temp->edgeInfo->vertexId2==key->vertexId2||temp->edgeInfo->vertexId2==key->vertexId1))
			return temp->edgeInfo;
		temp=temp->next;
	}
	if((temp->edgeInfo->vertexId1==key->vertexId1&&temp->edgeInfo->vertexId2==key->vertexId2)||(temp->edgeInfo->vertexId1==key->vertexId2&&temp->edgeInfo->vertexId2==key->vertexId1))
		return temp->edgeInfo;
	return NULL;
}


/*This function creates an array 'edges' of all the edge entries from the hash table. Return 0 on success and -1 on failure*/
int getArray(struct edgeHashTable *edgeHash,struct edge *edges)
{
	int i,j=0;
	struct llEdgeNode *temp;
	for(i=0;i<MAXBUCKETS;i++)
	{
		temp=edgeHash->buckets[i];
		while(temp)
		{
			edges[j].vertexId1=temp->edgeInfo->vertexId1;
			edges[j].vertexId2=temp->edgeInfo->vertexId2;
			edges[j].weight=temp->edgeInfo->weight;
			j++;
			temp=temp->next;
		}
	}
	return 0;
}

