#include"main.h"

void set_visited_flag(int *visited)
{
	int i;
	for(i=1;i<=vertexId;i++)
	{
		visited[i]=0;
	}
}
void dfs(adj_node **adj_list,struct edgeHashTable *edgeHash)
{
	SNode *head=(SNode*)malloc(sizeof(SNode));
	int first,second;
	int weight,numTypeA,numTypeB;
	struct edge *found;
	struct edge *dfsedge=(struct edge*)malloc(sizeof(struct edge));
	head=NULL;


	struct edge* dfsEdges;
	dfsEdges=(struct edge*)malloc(sizeof(struct edge)*(vertexId+1));


	int dfsVer[vertexId+1];
	struct tourVertex *tourVertices=(struct tourVertex*)malloc(sizeof(struct tourVertex)*(vertexId+1));

	int curVertex,temp;
	int index=0,i=0;
	int visited[vertexId+1];
	set_visited_flag(visited);
	push(&head,1);
	while(!isEmpty(head))
	{
		curVertex=pop(&head);	
		if(!visited[curVertex])
		{
			dfsVer[index++]=curVertex;
			visited[curVertex]=1;	
		}
		adj_node *temp=adj_list[curVertex];
		while(temp)
		{	
			if(!visited[temp->vertexId])
				push(&head,temp->vertexId);
			temp=temp->next;
		}
	}
	//populating neighbor ids
	for(i=0;i<vertexId;i++)
	{
		if(i==0)
			tourVertices[dfsVer[i]].neighbor_id1=dfsVer[vertexId-1];
		else
			tourVertices[dfsVer[i]].neighbor_id1=dfsVer[i-1];
		if(i==vertexId-1)
			tourVertices[dfsVer[i]].neighbor_id2=dfsVer[0];
		else
			tourVertices[dfsVer[i]].neighbor_id2=dfsVer[i+1];	
		
	}
/*	printf("\ntour vertices,,,:");
	for(i=1;i<=vertexId;i++)
	{
		printf("\n%s - %s -  %s",vertices[tourVertices[i].neighbor_id1],vertices[i],vertices[tourVertices[i].neighbor_id2]);
	}
*/

//Forming Tour
	curVertex=1;
	temp=curVertex;
	i=0;
	printf("\nDFS tour:");
	printf("\n---------");
	while(tourVertices[curVertex].neighbor_id2!=temp)
	{
		dfsedge->vertexId1=curVertex;
		dfsedge->vertexId2=tourVertices[curVertex].neighbor_id2;
		if((found=edgeHashSearch(edgeHash,dfsedge))==NULL)
		{
			dfsEdges[i].weight=typeBWeight;
			dfsEdges[i].type=1;
		}
		else
		{
			dfsEdges[i].weight=found->weight;
			dfsEdges[i].type=0;
		}
		dfsEdges[i].vertexId1=dfsedge->vertexId1;
		dfsEdges[i].vertexId2=dfsedge->vertexId2;
		curVertex=dfsedge->vertexId2;
		printf("\n%s %s %d %d\n",vertices[dfsEdges[i].vertexId1],vertices[dfsEdges[i].vertexId2],dfsEdges[i].weight,dfsEdges[i].type);
		i++;
	}
//For the last edge which completes the tour
	dfsedge->vertexId1=dfsEdges[i-1].vertexId2;
	dfsedge->vertexId2=temp;
	
	if((found=edgeHashSearch(edgeHash,dfsedge))==NULL)
	{
		dfsEdges[i].weight=typeBWeight;
		dfsEdges[i].type=1;
	}
	else
	{
		dfsEdges[i].weight=found->weight;
		dfsEdges[i].type=0;
	}
	
	dfsEdges[i].vertexId1=dfsedge->vertexId1;
	dfsEdges[i].vertexId2=dfsedge->vertexId2;
	printf("\n");
	printf("%s %s %d %d\n",vertices[dfsEdges[i].vertexId1],vertices[dfsEdges[i].vertexId2],dfsEdges[i].weight,dfsEdges[i].type);
	weight=numTypeB=numTypeA=0;
	for(index=0;index<=i;index++)
	{
		weight+=dfsEdges[index].weight;
		if(dfsEdges[index].type)
			numTypeB++;
		else
			numTypeA++;
	}
	printf("\nWeight of the path:%d\nNumber of typeB:%d\nNumber of typeA:%d",weight,numTypeB,numTypeA);
	printf("\n\n\nOptimizing tour");
	printf("\n*********************");
	optimize_tour(edgeHash,dfsEdges,tourVertices);
}
