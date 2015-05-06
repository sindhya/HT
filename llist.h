//structure for linkedlist
struct llEdgeNode
{
	struct edge *edgeInfo;
	struct llEdgeNode *next;
};

//structure for linkedlist
struct llVertexNode
{
	struct vertex *vertexInfo;
	struct llVertexNode *next;
};

int numEdges;
int vertexId;
/*Insert the Type A edge in linked list. Return 0 on success and -1 on failure*/
int llEdgeInsert(struct llEdgeNode **head,struct edge *edgeData);

/*Return the node of the linked list containing the key. If not fonud, return NULL*/
struct edge * llGetEdge(struct llEdgeNode *head,struct edge *key);


/*Insert the Type A edge in linked list. Return 0 on success and -1 on failure*/
int llVertexInsert(struct llVertexNode **head,struct vertex *vertexData);

/*Return the node of the linked list containing the key. If not fonud, return NULL*/
struct vertex * llGetVertex(struct llVertexNode *head,char *vertexName);
