/*Function prototypes for minimum spanning tree*/


/* Get the array of edges using getArray() function of hash.h
   Sort the array using functions in heapsort.h
   This function should create the minimum spanning tree using Kruskal's algorithm over the sorted list of type A 
   edges and populate it in minSpanningTreeEdges. Return 0 on success and -1 on failure*/

#include"main.h"


void makeSet(int i)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=i;
	newnode->rank=0;
	set[i]=newnode;
	set[i]->parent=set[i];
}

struct node* findSet(int i)
{
	if(set[i]->parent==set[i])
		return set[i];
	else 
		findSet(set[i]->parent->data);
}
void unionSet(int p,int q)
{
	struct node *xroot,*yroot;
	xroot=findSet(p);
	yroot=findSet(q);
	if(xroot==yroot)
		return;
	if(xroot->rank<yroot->rank)
		xroot->parent=yroot;
	else if(xroot->rank>yroot->rank)
		yroot->parent=xroot;
	else
		yroot->parent=xroot;
		xroot->rank=xroot->rank+1;
}
int checkIfSorted(struct edge *sortedEdgeList)
{
	int i;
	for(i=0;i<numEdges-1;i++)
	{
		if(sortedEdgeList[i].weight>sortedEdgeList[i+1].weight)
			return -1;
	}
	return 0;
}
int buildMinSpanningTree(struct edge *sortedEdgeList,struct edge *minSpanningTreeEdges)
{
	
	int stIndex=0,i,excludedIndex=0;
	int noComponents=0;
	int flag=0;
	int index=0,j;
	struct node* found;
	struct list *temp,*newnode;
	struct edge* excludedEdges;
	int compWeight[50];
	if(numEdges!=0)
	{
		if(checkIfSorted(sortedEdgeList)==-1)
		{
			printf("\nEdge list not sorted!");
			return -1;
		}
		printf("\nEdge List is sorted!");
	}
	for(i=0;i<50;i++)
		compWeight[i]=0;
	excludedEdges=(struct edge*)malloc(numEdges*sizeof(struct edge));
	components=(struct list**)malloc((numVertices+1)*sizeof(struct list*));
	for(i=0;i<numVertices;i++)
		components[i]=(struct list*)malloc(sizeof(struct list));	


	set=(struct node**)malloc(numVertices*sizeof(struct node*));
	for(i=0;i<numVertices;i++)
		set[i]=(struct node*)malloc(sizeof(struct node));	

	for(i=1;i<=vertexId;i++)
	{
		components[i]=NULL;
	}
	for(i=1;i<=vertexId;i++)
		makeSet(i);

	for(i=0;i<numEdges;i++)
	{
		
		if(findSet(sortedEdgeList[i].vertexId1)!=findSet(sortedEdgeList[i].vertexId2))
		{
			minSpanningTreeEdges[stIndex].vertexId1=sortedEdgeList[i].vertexId1;
			minSpanningTreeEdges[stIndex].vertexId2=sortedEdgeList[i].vertexId2;
			minSpanningTreeEdges[stIndex].weight=sortedEdgeList[i].weight;
			
			unionSet(sortedEdgeList[i].vertexId1,sortedEdgeList[i].vertexId2);
			stIndex++;
			mstEdges++;
			
		}
		else
		{
			excludedEdges[excludedIndex]=sortedEdgeList[i];
			excludedIndex++;
		}
	}
	for(i=1;i<=vertexId;i++)
	{
		found=findSet(i);
		newnode=(struct list*)malloc(sizeof(struct list));
		newnode->data=i;
		newnode->next=NULL;
		if(!components[found->data])
		{
			components[found->data]=newnode;
			flag++;
		}
		else
		{
			newnode->next=components[found->data];
			components[found->data]=newnode;
		}
	}
	for(i=0;i<mstEdges;i++)
	{
		found=findSet(minSpanningTreeEdges[i].vertexId1);
		compWeight[found->data]+=minSpanningTreeEdges[i].weight;	
	}
	/*
	//Flag will contain the no. of components, 1 means the graph is connected with typeA vertices
	if(vertexId!=numVertices && flag==1)
	{
		printf("\nMinimum Spanning Tree cannot be constructed.\nGraph has %d components",flag+1);
		for(i=1;i<=vertexId;i++)
		{
			temp=components[i];
			if(!temp)
				continue;
			else
			{
				noComponents++;
				printf("\nVertices in component %d :",noComponents);
				while(temp)
				{
					printf(" %s ",vertices[temp->data]);
					temp=temp->next;
				}
			
			}
		}
		noComponents++;
		printf("\nVertices in component %d:",noComponents);
		for(i=vertexId+1;i<=numVertices;i++)
		{
			printf(" %s ",vertices[i]);
		}
		return -1;
			
	}*/

	if(numVertices!=vertexId&&flag==1)
	{
		printf("\nGlobal Mininum Spanning Tree cannot be constructed.\n");
		i=0;
		printf("\nVertices in component :%d",i++);
		for(j=1;j<=vertexId;j++)
                {   
                    printf("\n%s",vertices[j]);
                }
		j=vertexId+1;
		while(j<=numVertices)
		{
			printf("\nVertices in component :%d",i++);
			printf("\n%s",vertices[j]);
			j++;
		} 
	}
	else if(flag>1)
	{
		printf("\nMinimum Spanning Tree cannot be constructed.\nGraph has %d components",flag);
		for(i=1;i<=vertexId;i++)
		{
			temp=components[i];
			if(!temp)
				continue;
			else
			{
				noComponents++;
				printf("\n\nVertices in component %d :",noComponents);
				while(temp)
				{
					printf(" %s ",vertices[temp->data]);
					temp=temp->next;
				}
				found=findSet(components[i]->data);
				printf("\nWeight of component%d",compWeight[found->data]);
			
			}
		}
		noComponents++;
		if(vertexId!=numVertices)
		{
			j=vertexId;
			while(j<=numVertices)
			{
				printf("\nVertices in component %d:",noComponents++);
				printf("\n%s",vertices[j]);
			}
		}
	}
	if(excludedIndex==0)
		printf("\nNo edges are excluded");
	else
	{
		printf("\nExcluded edges are:");
		for(i=0;i<excludedIndex;i++)
			printf("\n %s %s %d",vertices[excludedEdges[i].vertexId1],vertices[excludedEdges[i].vertexId2],excludedEdges[i].weight);
	}
	if((flag==1)&&(numVertices==vertexId))
		return 0;
	else return -1;

}


