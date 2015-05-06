/*Function prototypes for minimum spanning tree*/


/* Get the array of edges using getArray() function of hash.h
   Sort the array using functions in heapsort.h
   This function should create the minimum spanning tree using Kruskal's algorithm over the sorted list of type A 
   edges and populate it in minSpanningTreeEdges. Return 0 on success and -1 on failure*/

int mstEdges;
struct list
{
        int data;
        struct list *next;

}**components;
struct node
{
        int data;
        int rank;
        struct node *parent;
}**set,*newnode;

void makeSet(int);
void unionSet(int,int);
struct node* findSet(int);

int checkIfSorted(struct edge *sortedEdgeList);
int buildMinSpanningTree(struct edge *sortedEdgeList,struct edge *minSpanningTreeEdges);


