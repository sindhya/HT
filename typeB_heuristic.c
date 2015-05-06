#include"main.h"


int isAdjacentB(struct tourVertex *vertex1,int i)
{
	if(vertex1->neighbor_id1==i||vertex1->neighbor_id2==i)
		return 1;
	else
		return 0;
}

void form_tourB(struct edgeHashTable *edgeHash,struct tourVertex *tourVertices,struct edge *tourEdges)
{
	//Forming Tour
	int curVertex,temp,i;
	struct edge *first_edge=(struct edge*)malloc(sizeof(struct edge));
	struct edge *found1=(struct edge*)malloc(sizeof(struct edge));
        curVertex=1;
        temp=curVertex;
        i=0;
        printf("\nOptimized tour...:");
        while(tourVertices[curVertex].neighbor_id2!=temp)
        {
                first_edge->vertexId1=curVertex;
                first_edge->vertexId2=tourVertices[curVertex].neighbor_id2;
                if((found1=edgeHashSearch(edgeHash,first_edge))==NULL)
                {   
                        tourEdges[i].weight=typeBWeight;
                        tourEdges[i].type=1;
                }   
                else
                {   
                        tourEdges[i].weight=found1->weight;
                        tourEdges[i].type=0;
                }   
                tourEdges[i].vertexId1=first_edge->vertexId1;
                tourEdges[i].vertexId2=first_edge->vertexId2;
                curVertex=first_edge->vertexId2;
                printf("\n%s %s %d %d\n",vertices[tourEdges[i].vertexId1],vertices[tourEdges[i].vertexId2],tourEdges[i].weight,tourEdges[i].type);
                i++;
        }   
//For the last edge which completes the tour
        first_edge->vertexId1=tourEdges[i-1].vertexId2;
        first_edge->vertexId2=temp;
   if((found1=edgeHashSearch(edgeHash,first_edge))==NULL)
        {
                tourEdges[i].weight=typeBWeight;
                tourEdges[i].type=1;
        }
        else
        {
                tourEdges[i].weight=found1->weight;
                tourEdges[i].type=0;
        }

        tourEdges[i].vertexId1=first_edge->vertexId1;
        tourEdges[i].vertexId2=first_edge->vertexId2;
        printf("\n");
        printf("%s %s %d %d\n",vertices[tourEdges[i].vertexId1],vertices[tourEdges[i].vertexId2],tourEdges[i].weight,tourEdges[i].type);
   
}   
void optimize_weightB(struct edgeHashTable *edgeHash,struct edge* tourEdges,struct tourVertex* tourVertices)
{
	//struct edge* first_edge,second_edge,cross_edge1,cross_edge2;/*
	struct edge* first_edge=(struct edge*)malloc(sizeof(struct edge));
	struct edge* second_edge=(struct edge*)malloc(sizeof(struct edge));
	struct edge* cross_edge1=(struct edge*)malloc(sizeof(struct edge));
	struct edge* cross_edge2=(struct edge*)malloc(sizeof(struct edge));
	struct edge* found1=(struct edge*)malloc(sizeof(struct edge));
	struct edge* found2=(struct edge*)malloc(sizeof(struct edge));
	
	struct edge* foundcross1=(struct edge*)malloc(sizeof(struct edge));
	struct edge* foundcross2=(struct edge*)malloc(sizeof(struct edge));
	
	int i,j,k,swapped=0,curVertex,index;
	int temp;

	int prev_i_n2,prev_j_n2;	
	int weight1,weight2;
/*	printf("\nIn optimize weight:");
	printf("\ntour vertices,,,:");
        for(i=1;i<=vertexId;i++)
        {
                printf("\n%s - %s -  %s",vertices[tourVertices[i].neighbor_id1],vertices[i],vertices[tourVertices[i].neighbor_id2]);
        }*/
	for(i=1;i<=numVertices;i++)
	{
		j=tourVertices[i].neighbor_id2;
		while(j!=1)
		{
			if(!isAdjacentB(&tourVertices[i],j))
			{
				first_edge->vertexId1=i;
				first_edge->vertexId2=tourVertices[i].neighbor_id2;
				second_edge->vertexId1=j;
				second_edge->vertexId2=tourVertices[j].neighbor_id2;
				
				found1=edgeHashSearch(edgeHash,first_edge);
				found2=edgeHashSearch(edgeHash,second_edge);

				cross_edge1->vertexId1=i;
				cross_edge1->vertexId2=j;
				cross_edge2->vertexId1=tourVertices[i].neighbor_id2;
				cross_edge2->vertexId2=tourVertices[j].neighbor_id2;

				foundcross1=edgeHashSearch(edgeHash,cross_edge1);
				foundcross2=edgeHashSearch(edgeHash,cross_edge2);
				
				if((found1&&!found2)||(!found1&&found2))
				{
					if((foundcross1&&!foundcross2)||(!foundcross1&&foundcross2))
					{
						
						if(!found1)
						{
							weight1=typeBWeight;
							weight1+=found2->weight;
						}
						else
						{
							weight1=found1->weight;
							weight1+=typeBWeight;
						}

						if(!foundcross1)
						{
							weight2=typeBWeight;
							weight2+=foundcross2->weight;
						}
						else
						{
							weight2=foundcross1->weight;
							weight2+=typeBWeight;
						}
						
						if(weight2<weight1)
						{
							prev_i_n2=tourVertices[i].neighbor_id2;
							prev_j_n2=tourVertices[j].neighbor_id2;
							tourVertices[i].neighbor_id2=j;
							k=tourVertices[i].neighbor_id2;
							while(k!=prev_i_n2)
							{
								temp=tourVertices[k].neighbor_id1;
								tourVertices[k].neighbor_id1=tourVertices[k].neighbor_id2;
								tourVertices[k].neighbor_id2=temp;
								if(k==j)
								{
									tourVertices[k].neighbor_id1=i;			
								}
								k=tourVertices[k].neighbor_id2;	
							}
							if(k==(prev_i_n2))
							{	
								temp=tourVertices[k].neighbor_id1;
								tourVertices[k].neighbor_id1=tourVertices[k].neighbor_id2;
								tourVertices[k].neighbor_id2=temp;
								tourVertices[k].neighbor_id2=prev_j_n2;
							}

							tourVertices[prev_j_n2].neighbor_id1=k;
							/*printf("\nInside opt:tour vertices,,,:");
						        for(index=1;index<=vertexId;index++)
						       	 {
							                printf("\n%s - %s -  %s",vertices[tourVertices[index].neighbor_id1],vertices[index],vertices[tourVertices[index].neighbor_id2]);
       							 }*/
						}
					}
				}
			}
			j=tourVertices[j].neighbor_id2;
		}
	}
	form_tourB(edgeHash,tourVertices,tourEdges);
}

void optimize_tourB(struct edgeHashTable *edgeHash,struct edge* tourEdges,struct tourVertex* tourVertices)
{

	struct edge* first_edge=(struct edge*) malloc(sizeof(struct edge));
	struct edge* second_edge=(struct edge*) malloc(sizeof(struct edge));
	struct edge* cross_edge1=(struct edge*) malloc(sizeof(struct edge));
	struct edge* cross_edge2=(struct edge*) malloc(sizeof(struct edge));
	
	struct edge* found1=(struct edge*)malloc(sizeof(struct edge));
	struct edge* found2=(struct edge*)malloc(sizeof(struct edge));
	
	struct edge* foundcross1=(struct edge*)malloc(sizeof(struct edge));
	struct edge* foundcross2=(struct edge*)malloc(sizeof(struct edge));
	
	int i,j,k,swapped=0,curVertex,index;
	int temp;

	int prev_i_n2,prev_j_n2;	
	int weight1,weight2;
/*
	printf("\ntour vertices,,,:");
        for(i=1;i<=vertexId;i++)
        {
                printf("\n%s - %s -  %s",vertices[tourVertices[i].neighbor_id1],vertices[i],vertices[tourVertices[i].neighbor_id2]);
        }*/
	for(i=1;i<=numVertices;i++)
	{
		j=tourVertices[i].neighbor_id2;
		while(j!=1)
		{
			if(!isAdjacentB(&tourVertices[i],j))
			{
				first_edge->vertexId1=i;
				first_edge->vertexId2=tourVertices[i].neighbor_id2;
				second_edge->vertexId1=j;
				second_edge->vertexId2=tourVertices[j].neighbor_id2;
				
				found1=edgeHashSearch(edgeHash,first_edge);
				found2=edgeHashSearch(edgeHash,second_edge);

				cross_edge1->vertexId1=i;
				cross_edge1->vertexId2=j;
				cross_edge2->vertexId1=tourVertices[i].neighbor_id2;
				cross_edge2->vertexId2=tourVertices[j].neighbor_id2;

				foundcross1=edgeHashSearch(edgeHash,cross_edge1);
				foundcross2=edgeHashSearch(edgeHash,cross_edge2);
				
				if(found1&&found2)
				{
					if((foundcross1&&!foundcross2)||(!foundcross1&&foundcross2)||(!foundcross1&&!foundcross2))
					{
						prev_i_n2=tourVertices[i].neighbor_id2;
						prev_j_n2=tourVertices[j].neighbor_id2;
						tourVertices[i].neighbor_id2=j;
						k=tourVertices[i].neighbor_id2;

						while(k!=prev_i_n2)
						{
							temp=tourVertices[k].neighbor_id1;
							tourVertices[k].neighbor_id1=tourVertices[k].neighbor_id2;
							tourVertices[k].neighbor_id2=temp;
							if(k==j)
							{
								tourVertices[k].neighbor_id1=i;			
							}
							k=tourVertices[k].neighbor_id2;	
						}
						if(k==(prev_i_n2))
						{	

							temp=tourVertices[k].neighbor_id1;
							tourVertices[k].neighbor_id1=tourVertices[k].neighbor_id2;
							tourVertices[k].neighbor_id2=temp;
							tourVertices[k].neighbor_id2=prev_j_n2;
						}

						tourVertices[prev_j_n2].neighbor_id1=k;
					/*	printf("\nInside opt:tour vertices,,,:");
					        for(index=1;index<=vertexId;index++)
					       	 {
						                printf("\n%s - %s -  %s",vertices[tourVertices[index].neighbor_id1],vertices[index],vertices[tourVertices[index].neighbor_id2]);
       						 }*/
					}
				}
				else if((!found1&&found2)||(found1&&!found2))
				{
					if(!foundcross1&&!foundcross2)
					{
						prev_i_n2=tourVertices[i].neighbor_id2;
						prev_j_n2=tourVertices[j].neighbor_id2;
						tourVertices[i].neighbor_id2=j;
						k=tourVertices[i].neighbor_id2;
	

						while(k!=prev_i_n2)
						{
							temp=tourVertices[k].neighbor_id1;
							tourVertices[k].neighbor_id1=tourVertices[k].neighbor_id2;
							tourVertices[k].neighbor_id2=temp;
							if(k==j)
							{
								tourVertices[k].neighbor_id1=i;			
							}
							k=tourVertices[k].neighbor_id2;	
						}
						if(k==(prev_i_n2))
						{	
							temp=tourVertices[k].neighbor_id1;
							tourVertices[k].neighbor_id1=tourVertices[k].neighbor_id2;
							tourVertices[k].neighbor_id2=temp;
							tourVertices[k].neighbor_id2=prev_j_n2;
						}
						tourVertices[prev_j_n2].neighbor_id1=k;
						/*printf("\nInside opt:tour vertices,,,:");
					        for(index=1;index<=vertexId;index++)
					        {
					                printf("\n%s - %s -  %s",vertices[tourVertices[index].neighbor_id1],vertices[index],vertices[tourVertices[index].neighbor_id2]);
        					}*/
					}
				}
			}
			j=tourVertices[j].neighbor_id2;
		}
	}
	printf("\nFirst level optimization:");
	printf("\n*************************");
	form_tourB(edgeHash,tourVertices,tourEdges);
	printf("\nSecond level optimization:");
	printf("\n**************************");
	optimize_weightB(edgeHash,tourEdges,tourVertices);
}


