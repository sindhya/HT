#define MAXBUCKETS 1000

//structure for hash table for vertices.
struct vertexHashTable
{
	struct llVertexNode *buckets[MAXBUCKETS] ;
};

//Array of vertices - index of every vertex name will be vertex id.
//char **vertices;

/*Allocate the memory and initialize the hash table.*/
void vertexHashInit(struct vertexHashTable *vertexHash);

/*Use your own hash function to calculate the hash value*/
int calcVertexHash(char *vertexName);

/*Insert the Type A edge in hash table. Return 0 on success and -1 on failure*/
int vertexHashInsert(struct vertexHashTable *vertexHash, struct vertex *vertex);

/*For the given vertex name calculate the hash value and return the corresponding vertex id from hashtable. Return -1 if vertex name not found*/
int getVertexId(struct vertexHashTable *vertexHash,char *vertexName);

/*Searching vertex Hash table*/
int vertexHashSearch(struct vertexHashTable *vertexHash,char *vertexName);

/*For the given vertex id return vertexname from array. Return NULL if vertex id is invalid*/
char * getVertexName(char **vertices,int vertexId);

/*Creating typeB vertices names*/
void createBVertices(char **vertices);
