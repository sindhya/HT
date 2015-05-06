
/*****************************
returns 1 if any of the triangle inequalities are not satisifed
returns 0 if all traingles are satisfied.
Steps: Start with edge with maximum weight say E(v1,v2)
	Check the condition of triangle inequality with E and two dummy edges. // one Type A edge and two Type B edges

	Check the condition of triangle inequality with E and another Type A edge and dummy edge. // two Type A edge and one Type B edges

	Check the condition of triangle inequality with E and two Type A edges. // three Type A edges
		return 1 at any step inequality doesnt satisfy
		
	To check for Type of edge - if the edge gets a hit in hash table then its a type A edge else Type B.
*********************************/ 

int checkTriangleInequality(struct edge *sortedEdgeList,struct edgeHashTable *edgeHash);
