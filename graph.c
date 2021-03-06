#include "main.h"
int parseInputDescription(char *inputFileName,struct vertexHashTable *vertexHash,struct edgeHashTable *edgeHash)
{
	
	char *buffer=(char*)malloc(50);
	char vertex1[30],vertex2[30],temp[30],ch;
	int weight,vertexId1,vertexId2,length,i;
	int verticesCount=0;

	struct edge *edgeData=(struct edge*)malloc(sizeof(struct edge));
	struct vertex *vertexData=(struct vertex*)malloc(sizeof(struct vertex));

	FILE *fp=fopen(inputFileName,"r");
	if(fp==NULL)
	{
		printf("\nFile doesn't exists!");
		return -1;
	}
	if(fscanf(fp,"%s %c %d",buffer,&ch,&numVertices)==EOF )
	{
		printf("\nEmpty File");
		return -1;
	}
	if(toupper(buffer[0])!='N')
	{
		printf("\nNumber of vertices line not specified");
		return -1;
	}
	if(numVertices==0)
	{
		printf("\nNumber missing in num vertices field:");
		return -1;
	}
 	vertices=(char**)malloc((numVertices+1)*sizeof(char*));
        for(i=0;i<=numVertices;i++)
        {   
                vertices[i]=(char*)malloc(sizeof(char)*30);
        } 

	while(!feof(fp))
	{
		fscanf(fp,"%s",temp);
		if(temp[0]!='(')
			break;
		strcpy(vertex1,temp+1);
		length=strlen(temp);
		vertex1[length]='\0';
		if(fscanf(fp,"%s %d",temp,&weight)==1)
		{
			printf("\nEdge weight not given!");
			return -1;
		}
		if(weight<0)
		{
			printf("\nNegative weight entered!");
			return -1;
		}
		length=strlen(temp);
		strncpy(vertex2,temp,length-1);
		vertex2[length-1]='\0';
		if(strlen(vertex1)<1||strlen(vertex2)<1)
		{
			printf("\nVertex name not present!");
			return -1;
		}
		strcpy(vertexData->vertexName,vertex1);
		if(vertexHashSearch(vertexHash,vertexData->vertexName)==0)
			verticesCount++;
		if(verticesCount>numVertices)
		{
			printf("\nInvalid input file!");
			return -1;
		}
		if(vertexHashInsert(vertexHash,vertexData)==-1)
		{
			printf("\nError in Insertion!");
			return -1;
		}
		strcpy(vertexData->vertexName,vertex2);

		if(vertexHashSearch(vertexHash,vertexData->vertexName)==0)
			verticesCount++;
		if(verticesCount>numVertices)
		{
			printf("\nInvalid input file!");
			return -1;
		}
		if(vertexHashInsert(vertexHash,vertexData)==-1)
		{
			printf("\nError in Insertion!");
			return -1;
		}
		vertexId1=getVertexId(vertexHash,vertex1);
		vertexId2=getVertexId(vertexHash,vertex2);
		if(vertexId1!=-1&&vertexId2!=-1)
		{
			edgeData->vertexId1=vertexId1;
			edgeData->vertexId2=vertexId2;
			edgeData->weight=weight;
			if(edgeHashInsert(edgeHash,edgeData)==-1)
			{
				printf("\nError in Edge-Insertion");
				return -1;
			}
		}
	}/*
	if(numEdges==0)
	{
		printf("\nNo Type A edges!!");
		return -1;
	}*/
	if(fscanf(fp,"%s %d",temp,&typeBWeight)==EOF)
	{
		printf("\nTypeB weight missing!");
		return -1;
	}
	if(typeBWeight==0)
	{
		printf("\nWeight missing in typeB field!");
		return -1;
	}
	createBVertices(vertices);
	return 0;
}


