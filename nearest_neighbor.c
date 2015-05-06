#include "main.h"
void setvisited(int *visited)
{
	int i;
	for(i=1;i<=vertexId;i++)
	{
		visited[i]=0;
	}
}

void nearest_neighbor(struct edge *edges,struct edgeHashTable *edgeHash)
{
	int visited[vertexId+1];
	int i=0;
	struct edge *neighborEdges=(struct edge*)malloc((numVertices+1)*sizeof(struct edge));
	struct tourVertex *tourVertices=(struct tourVertex*)malloc(sizeof(struct tourVertex)*(vertexId+1));

	int neighborVer[vertexId+1];
	int numberVisited=0;
	int first,second;
	int curVertex=1,minV1,minV2,minWeight,index;

	int numTypeA,numTypeB,weight;
	struct edge *found;
	struct edge *currentEdge=(struct edge*)malloc(sizeof(struct edge));
	setvisited(visited);


	first=curVertex;
	index=0;
	printf("\nEdges:");
	for(i=0;i<numEdges;i++)
	{
		   printf("\n%s \t%s \t%d",vertices[edges[i].vertexId1],vertices[edges[i].vertexId2],edges[i].weight);
	}

	while(numberVisited+1<vertexId)
	{
		visited[first]=1;
		neighborVer[index]=first;
		numberVisited++;		
		minWeight=edges[numEdges-1].weight;
		minV1=first;
		minV2=0;
		for(i=1;i<=vertexId;i++)
		{
			second=i;
			if(visited[second])
				continue;
			currentEdge->vertexId1=first;
			currentEdge->vertexId2=second;
			found=edgeHashSearch(edgeHash,currentEdge);
			if(found!=NULL)
			{
				if(found->weight<=minWeight)
				{
					minWeight=found->weight;
					minV2=second;
				}
			}
		}
		neighborEdges[index].type=0;
		if(minV2==0)
		{
			for(i=1;i<=vertexId;i++)
			{
				if(!visited[i])
				{
					minWeight=typeBWeight;
					minV2=i;
				}
			}	
			neighborEdges[index].type=1;
		}
		neighborEdges[index].vertexId1=minV1;
		neighborEdges[index].vertexId2=minV2;
		neighborEdges[index].weight=minWeight;
		index++;
		first=minV2;
	}

	//For last edge which completes the cycle..
	currentEdge->vertexId1=neighborEdges[index-1].vertexId2;
	currentEdge->vertexId2=1;
	found=edgeHashSearch(edgeHash,currentEdge);

	

	if(found!=NULL)
	{
		neighborEdges[index].weight=found->weight;
		neighborEdges[index].type=0;
	}
	else
	{
		neighborEdges[index].weight=typeBWeight;
		neighborEdges[index].type=1;
	}

	neighborVer[index]=neighborEdges[index-1].vertexId2;

	neighborEdges[index].vertexId1=neighborEdges[index-1].vertexId2;
	neighborEdges[index].vertexId2=1;

	//Populating the neighbor IDs
	for(i=0;i<vertexId;i++)
	{
		if(i==0)
                        tourVertices[neighborVer[i]].neighbor_id1=neighborVer[vertexId-1];
                else
                        tourVertices[neighborVer[i]].neighbor_id1=neighborVer[i-1];
                if(i==vertexId-1)
                        tourVertices[neighborVer[i]].neighbor_id2=neighborVer[0];
                else
                        tourVertices[neighborVer[i]].neighbor_id2=neighborVer[i+1];  
		
	}/*
	printf("\ntour vertices,,,:");
        for(i=1;i<=vertexId;i++)
        {   
                printf("\n%d - %d -  %d",tourVertices[i].neighbor_id1,i,tourVertices[i].neighbor_id2);
        }  */
	printf("\nNearest neighbour edges:");
	printf("\n************************");
	for(i=0;i<=index;i++)
	{
		printf("\n%s %s %d %d",vertices[neighborEdges[i].vertexId1],vertices[neighborEdges[i].vertexId2],neighborEdges[i].weight,neighborEdges[i].type);
	}
	weight=numTypeB=numTypeA=0;
        for(i=0;i<=index;i++)
        {   
                weight+=neighborEdges[i].weight;
                if(neighborEdges[i].type)
                        numTypeB++;
                else
                        numTypeA++;
        }   
        printf("\nWeight of the path:%d\nNumber of typeB:%d\nNumber of typeA:%d",weight,numTypeB,numTypeA);

	printf("\nOptimizing tour:");
	printf("\n----------------");
	optimize_tour(edgeHash,neighborEdges,tourVertices);
	printf("\nTYpeB Optimization:");
	optimize_tourB(edgeHash,neighborEdges,tourVertices);
}
