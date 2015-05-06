#include"main.h"
int main(int argc,char* argv[])
{
	int choice,flag,dfsBFlag,i,mstWeight,heapFlag,mstFlag,continueFlag=1;
	struct vertexHashTable *vertexHash;
	struct edgeHashTable *edgeHash;

	struct llVertexNode *tempVertex;
	struct llEdgeNode *tempEdge;
	struct edge *edges;
	struct edge *mstedges;

	if(argc!=2)
	{
		printf("\nFormat is : (executable) <input_file_name>\n");
		exit(0);
	}
	
	vertexHash=(struct vertexHashTable*)malloc(sizeof(struct vertexHashTable));
	edgeHash=(struct edgeHashTable*)malloc(sizeof(struct edgeHashTable));

	
	vertexHashInit(vertexHash);
	edgeHashInit(edgeHash);

	if(parseInputDescription(argv[1],vertexHash,edgeHash)==-1)
	{
		printf("\nError in parsing...!\n");
		exit(1);
	}
	printf("\nNumber of explicitly Specified Vertices:%d \nTotal number of vertices is %d \nNumber of TypeA edges is %d",numVertices,vertexId,numEdges);
	
	edges=(struct edge*)malloc(sizeof(struct edge)*numEdges);
	mstedges=(struct edge*)malloc(sizeof(struct edge)*numEdges);

	getArray(edgeHash,edges);
	heapFlag=heapsort(edges,numEdges);

	do
	{
		printf("\nMENU:");
		printf("\n-----");
		printf("\n1.Print Vertex Hash Table");
		printf("\n2.Print Edge Hash Table");
		printf("\n3.Names of vertices");
		printf("\n4.Check for Triangle Inequality");
		printf("\n5.Print Sorted Edge list(heap sort)");
		printf("\n6.Print the edges in MST(if any) and Euler tour(2-opt) for DFSTypeA");
		printf("\n7.Nearest Neighbour Heuristic and its optimized tour");
		printf("\n8.DFS for TypeB and its optimized tour");
		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nTraversing vertex Hash table:");
				printf("\n-----------------------------");
				for(i=0;i<MAXBUCKETS;i++)
				{
					tempVertex=vertexHash->buckets[i];
					while(tempVertex)
					{
						printf("\n%s \t%d",tempVertex->vertexInfo->vertexName,tempVertex->vertexInfo->vertexId);
						tempVertex=tempVertex->next;
					}
				}
				break;
			case 2:
				printf("\nTraversing edge hash Table:");
				printf("\n---------------------------");
				for(i=0;i<MAXBUCKETS;i++)
				{
					tempEdge=edgeHash->buckets[i];
					while(tempEdge)
					{
						printf("\n%s\t%s\t%d",vertices[tempEdge->edgeInfo->vertexId1],vertices[tempEdge->edgeInfo->vertexId2],tempEdge->edgeInfo->weight);
						tempEdge=tempEdge->next;
					}
				}
				break;	
			case 3:
				printf("\nNames of vertices:");
				printf("\n------------------");
				for(i=1;i<=numVertices;i++)
					printf("\n %d : %s ",i,vertices[i]);
				break;
			case 4:
				if(numVertices>2)
				{
					printf("\nChecking for Triangle inequality!");		
					printf("\n---------------------------------");
					flag=checkTriangleInequality(edges,edgeHash);
					if(flag==0)
						printf("\nAll triangle inequalities satisfied!");
					else if(flag==2)
						printf("\nNo TypeA edges! Triangle inequalities of TypeB vertices satisfied!");
					else
						printf("\nTriangle inequality not satisfied!");
				}
				else
				{
					printf("\nTriangle not possible with less than 3 vertices!");
				}
				break;
			
			case 5:
				printf("\nSorted Edge list");
				printf("\n----------------");
				if(heapFlag==0)
				{
					printf("\nTraversing edge array after heap sort");
					for(i=0;i<numEdges;i++)
					{
						printf("\n%s \t%s \t%d",vertices[edges[i].vertexId1],vertices[edges[i].vertexId2],edges[i].weight);
					}
				}
				break;
			case 6:
				printf("\nMinimum Spanning Tree(Kruskal's algorithm)");
				printf("\n------------------------------------------");
				mstFlag=buildMinSpanningTree(edges,mstedges);
				
				if(numEdges>=1)
				{
					if(mstFlag==-1)
					{
						printf("\nGraph is disconnected.\nCannot build minimum spanning tree!!");
					}
					else
					{
						printf("\nGraph is connected");
						printf("\nNumber of edges in minimum spanning tree:%d",mstEdges);
						printf("\nEdges in Minimum Spanning tree:");
						mstWeight=0;
						for(i=0;i<mstEdges;i++)
						{
							printf("\n%s %s %d",vertices[mstedges[i].vertexId1],vertices[mstedges[i].vertexId2],mstedges[i].weight);
							mstWeight+=mstedges[i].weight;
						}
						printf("\nWeight of mst:%d",mstWeight);
						
	 					adj_list=(adj_node**)malloc((vertexId+1)*sizeof(adj_node*));
	     					for(i=0;i<=vertexId;i++)
       		 				{   
                					adj_list[i]=(adj_node*)malloc(sizeof(adj_node));
							adj_list[i]=NULL;
        					} 
		
						make_adjacency_list(adj_list,mstedges);
						//print_adjacency_list(adj_list);
						dfs(adj_list,edgeHash);
					}
				}
				break;
			case 7:
				nearest_neighbor(edges,edgeHash);
				break;
			case 8:
				printf("\nType B DFS:");
				printf("\n***********");
				dfsBFlag=dfs_typeB(edgeHash);
				if(!dfsBFlag)
					printf("\nDisconnected Graph!");
				break;				
			default:
				printf("\nEnter a number between 1 to 6");
		}
		printf("\nDo you want to continue? (0 or 1) :");
		scanf("%d",&continueFlag);
	}while(continueFlag);
	return 0;
}
