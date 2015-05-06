
//structure for hash table for edges.
struct edgeHashTable
{
	struct llEdgeNode *buckets[MAXBUCKETS] ;
};


/*Allocate the memory and initialize the hash table.*/
void edgeHashInit(struct edgeHashTable *edgeHash);

/*Use your own hash function to calculate the hash value*/
int calcEdgeHash( char *vertex1,char *vertex2);

/*Insert the Type A edge in hash table. Return 0 on success and -1 on failure*/
int edgeHashInsert(struct edgeHashTable *edgeHash, struct edge *data);

/*Search the given edge. If it is found return a pointer to the edge. If not found return NULL*/
struct edge * edgeHashSearch(struct edgeHashTable *edgeHash,struct edge *key);


/*This function creates an array 'edges' of all the edge entries from the hash table. Return 0 on success and -1 on failure*/
int getArray(struct edgeHashTable *edgeHash,struct edge *edges);
