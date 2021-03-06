#include "main.h"
/* Function to create max / descending heap as required
   edges - pointer to array of edges
*/
static int heapSize;
void max_heapify(struct edge *edges , int index)
{
	struct edge temp;
	int left,right,largest;


	left=2*index+1;
	right=2*index+2;

	largest=index;
	
	if(left<heapSize&&edges[left].weight>edges[index].weight)
		largest=left;
	if(right<heapSize&&edges[right].weight>edges[largest].weight)
		largest=right;
	if(largest!=index)
	{
		temp=edges[largest];
		edges[largest]=edges[index];
		edges[index]=temp;
		max_heapify(edges,largest);
	}
}
/* Function to build the  heap*/ 
void build_heap(struct edge *edges , int numEdges)
{
	int index;
	heapSize=numEdges;
	for(index=numEdges/2-1;index>=0;index--)
		max_heapify(edges,index);
}

/*Function to perform heap sort i.e call heapify and recreate_heap from here . 
   edges - pointer to array of edges
Return 0 on success and -1 on failure*/
int heapsort(struct edge *edges , int numEdges)
{
	int index;
	struct edge temp;
	if(numEdges>=0)
	{
		build_heap(edges,numEdges);
		for(index=numEdges-1;index>=1;index--)
		{
			temp=edges[0];
			edges[0]=edges[index];
			edges[index]=temp;
			heapSize--;
			max_heapify(edges,0);
		}
		return 0;
	}
	return -1;

			
}
