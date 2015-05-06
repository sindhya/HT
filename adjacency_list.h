
typedef struct adjacency_node
{
	int vertexId;
	int weight;
	int visited;
	struct adjacency_node *next;
}adj_node;
adj_node **adj_list;

void make_adjacency_list(adj_node **adj_list,struct edge* mstedges);
void print_adjacency_list(adj_node **adj_list);
