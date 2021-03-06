#include "main.h"
/*Allocate the memory and initialize the hash table.*/
void vertexHashInit(struct vertexHashTable *vertexHash)
{
	int i;
	for(i=0;i<MAXBUCKETS;i++)
	{
		vertexHash->buckets[i]=NULL;
	}
}

/*Use your own hash function to calculate the hash value*/
int calcVertexHash(char *vertexName)
{
	char *temp=vertexName;
	int hash=7;
	while(*temp)
	{
		hash+=((*temp)*7);
		temp++;
	}
	return hash%97;
}

/*Insert the Type A edge in hash table. Return 0 on success and -1 on failure*/
int vertexHashInsert(struct vertexHashTable *vertexHash, struct vertex *vertex)
{
	int vHash;
	vHash=calcVertexHash(vertex->vertexName);
	
	return llVertexInsert(&vertexHash->buckets[vHash],vertex);
}

/*For the given vertex name calculate the hash value and return the corresponding vertex id from hashtable. Return -1 if vertex name not found*/
int getVertexId(struct vertexHashTable *vertexHash,char *vertexName)
{
	int vHash;
	struct llVertexNode *temp;
	
	vHash=calcVertexHash(vertexName);
	temp=vertexHash->buckets[vHash];
	while(temp)
	{
		if(strcmp(temp->vertexInfo->vertexName,vertexName)==0)
			return temp->vertexInfo->vertexId;
		temp=temp->next;
	}
	return -1;
}

/*For the given vertex id return vertexname from array. Return NULL if vertex id is invalid*/
char * getVertexName(char **vertices,int vertexId)
{
	return vertices[vertexId];

}
/*Creating typeB vertices name*/
void createBVertices(char **vertices)
{
        int i;
        char name[30],buffer[30];
        for(i=vertexId+1;i<=numVertices;i++)
        {   
                sprintf(name,"%d",i);
                strcpy(buffer,"VertexB:");
                strcat(buffer,name);
                strcpy(vertices[i],buffer);
        }    
}
int vertexHashSearch(struct vertexHashTable *vertexHash,char *vertexName)
{
        int vHash;
        struct llVertexNode *temp;

        vHash=calcVertexHash(vertexName);
        temp=vertexHash->buckets[vHash];

	if(!temp)
                return 0;
        while(temp->next)
        {   
                if(strcmp(temp->vertexInfo->vertexName,vertexName)==0)
                        return 1;
                temp=temp->next;
        }   
        if(strcmp(temp->vertexInfo->vertexName,vertexName)==0)
                return 1;
        return 0;
}

