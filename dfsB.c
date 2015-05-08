#include"main.h"
void initialise_all_vertices(int *all_vertices)		// for initializing the array visited/not visited.
{
	//int *all_vertices;
	
	int i;
	for(i=1;i<=numVertices;i++)
	{
		all_vertices[i]=0;		
	}
}

void set_array_visited(int *all_vertices,int ver)						// Setting tag Visited/not visited.
{
	all_vertices[ver]=1;
}

int dfs_typeB(struct edgeHashTable *edgeHash)
{
	int i=0,j,ver,k;	
	int v=1; 							// store vertex id of parent node.
	int v_adjacent=-1; 						// store vertex id of adjacent node to v.
	struct edge* edgeformed,*found;
	int *all_vertices;				// for creating edge from two vertices.
	
	
	
	all_vertices=(int *)malloc(sizeof(int)*(numVertices+1));
	edgeformed=(struct edge*)malloc(sizeof(struct edge));

	SNode *head=(SNode *)malloc(sizeof(SNode));
	head = NULL ;
	struct edge *dfsEdges;
	dfsEdges=(struct edge *)malloc(sizeof(struct edge)*(numVertices+1));			//Dummy edge for type B
	struct tourVertex* tourver;

	tourver=(struct tourVertex*)malloc(sizeof(struct tourVertex)*(numVertices+1));	
        found=(struct edge *)malloc(sizeof(struct edge));
        edgeformed=(struct edge *)malloc(sizeof(struct edge));
    	
        initialise_all_vertices(all_vertices);
	int *dfs_typeB_list ;
	//int dfs_typeB_list[numVertices+1];
	dfs_typeB_list=(int *)malloc(sizeof(int)*(numVertices+1));

	if(dfs_typeB_list==NULL) 
	{
		printf("Unable to Allocate Memory in dfs_typeB...!\n");
		exit(1);
	}
	else
	{

		set_array_visited(all_vertices,v);		
		push(&head,v);
		printf ("\nPushing %d ",v) ;
        do
		{
            if(v_adjacent==-1)
			{
				v=pop(&head);
				printf ("\nv = %d", v ) ;
            }
            for(j=1;j<=numVertices;j++)
			{
            	edgeformed->vertexId1 = v;
	        	edgeformed->vertexId2 = j;
        
        	    if(edgeHashSearch(edgeHash,edgeformed) == NULL) 
				{
					v_adjacent=j;
			       	if(all_vertices[v_adjacent]==0)
					{
		                set_array_visited(all_vertices,v_adjacent);		
						push(&head,v_adjacent);
						printf ("\nPushing %d ",v_adjacent) ;	
						dfs_typeB_list[i]=v;
						v=v_adjacent;
						i++;
					}    
				}
				
				if(i==numVertices-1)
				{
					dfs_typeB_list[i]=v;
					i++;
				}
			}
			v_adjacent=-1;		

		}while(!isEmpty(head));
	}
	
	// Creating an structure array of size ver(total number of type B vertices)
	ver=i;
	tourver=(struct tourVertex *)malloc(sizeof(struct tourVertex)* (ver + 1));

	for(j=0;j<ver;j++)
	{
		if(j==0)
			tourver[dfs_typeB_list[j]].neighbor_id1=dfs_typeB_list[ver-1];
		else
			tourver[dfs_typeB_list[j]].neighbor_id1=dfs_typeB_list[j-1];
		
		if(j==ver-1)
			tourver[dfs_typeB_list[j]].neighbor_id2=dfs_typeB_list[0];
		else
			tourver[dfs_typeB_list[j]].neighbor_id2=dfs_typeB_list[j+1];	
		
	}

	k=0;
	if(numVertices!=(i))
		return 0;		// Graph is disconnected.
	else
	{
		for(j=0;j<i-1;j++)
		{
			dfsEdges[k].vertexId1=dfs_typeB_list[j];
			dfsEdges[k].vertexId2=dfs_typeB_list[j+1];
			edgeformed->vertexId1=dfsEdges[k].vertexId1;
			edgeformed->vertexId2=dfsEdges[k].vertexId2;
			if((found=edgeHashSearch(edgeHash,edgeformed))==NULL)
			{
				dfsEdges[k].weight=typeBWeight;
				dfsEdges[k].type=1;
			}
			else
			{
				dfsEdges[k].weight=found->weight;
				dfsEdges[k].type=0;
			}
			k++;
		}
		
		dfsEdges[k].vertexId1=dfs_typeB_list[i-1];
		dfsEdges[k].vertexId2=dfs_typeB_list[0];
		
		edgeformed->vertexId1=dfsEdges[k].vertexId1;
		edgeformed->vertexId2=dfsEdges[k].vertexId2;
		if((found=edgeHashSearch(edgeHash,edgeformed))==NULL)
		{
			dfsEdges[k].weight=typeBWeight;
			dfsEdges[k].type=1;
		}
		else
		{
			dfsEdges[k].weight=found->weight;
			dfsEdges[k].type=0;
		}
		printf("\nDFS Type B tour:");
		printf("\n****************");
		for(i=0;i<=k;i++)
			printf("\n%s %s %d %d",vertices[dfsEdges[i].vertexId1],vertices[dfsEdges[i].vertexId2],dfsEdges[i].weight,dfsEdges[i].type);

	}	
	free(all_vertices) ;
	free(edgeformed) ;
	free(head) ;
	free(dfsEdges) ;
	free(tourver) ;
	free(dfs_typeB_list) ;
	free(found) ;

	
	return 1;
}


