CC=gcc
CFLAGS=-Wall
COMPILE=-c -g
project:main.o hash.o graph.o llist.o vertices.o heapsort.o minimumSpanningTree.o checkTriangleInequality.o adjacency_list.o dfs.o stack.o nearest_neighbor.o dfsB.o two_opt_heuristic.o typeB_heuristic.o
	$(CC) -o project main.o llist.o hash.o vertices.o graph.o heapsort.o checkTriangleInequality.o minimumSpanningTree.o adjacency_list.o dfs.o stack.o dfsB.o nearest_neighbor.o two_opt_heuristic.o typeB_heuristic.o

main.o:main.c hash.o graph.o vertices.o main.h
	$(CC) $(COMPILE) $(CLAGS) main.c

hash.o:hash.c hash.h main.h
	$(CC) $(COMPILE) $(CFLAGS) hash.c

graph.o:graph.c graph.h main.h
	$(CC) $(COMPILE) $(CFLAGS) graph.c

llist.o:llist.c llist.h main.h
	$(CC) $(COMPILE) $(CFLAGS) llist.c

vertices.o:vertices.c vertices.h main.h
	$(CC) $(COMPILE) $(CFLAGS) vertices.c

heapsort.o:heapsort.c heapsort.h main.h
	$(CC) $(COMPILE) $(CFLAGS) heapsort.c

minimumSpanningTree.o:minimumSpanningTree.c minimumSpanningTree.h main.h
	$(CC) $(COMPILE)  minimumSpanningTree.c

checkTriangleInequality.o:checkTriangleInequality.c checkTriangleInequality.h main.h
	$(CC) $(COMPILE) $(CFLAGS) checkTriangleInequality.c

adjacency_list.o:adjacency_list.c adjacency_list.h main.h
	$(CC) $(COMPILE) $(CFLAGS) adjacency_list.c

dfs.o:dfs.c dfs.h main.h
	$(CC) $(COMPILE) $(CFLAGS) dfs.c

dfsB.o:dfsB.c dfsB.h main.h
	$(CC) $(COMPILE) $(CFLAGS) dfsB.c

stack.o:stack.c stack.h
	$(CC) $(COMPILE) $(CFLAGS) stack.c

nearest_neighbor.o:nearest_neighbor.c nearest_neighbor.h main.h
	$(CC) $(COMPILE) $(CFLAGS) nearest_neighbor.c

two_opt_heuristic.o:two_opt_heuristic.c two_opt_heuristic.h main.h
	$(CC) $(COMPILE) $(CFLAGS) two_opt_heuristic.c

typeB_heuristic.o:typeB_heuristic.c typeB_heuristic.h main.h
	$(CC) $(COMPILE) $(CFLAGS) typeB_heuristic.c


clean:
	rm -rf *.o project
