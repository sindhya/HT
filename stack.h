#include <stdlib.h>
typedef struct stack_node
{
        int vertexId;
        struct stack_node *next;
}SNode;

void push(SNode** head,int data);
int pop(SNode** head);
int isEmpty(SNode *head);
int peek(SNode *head);
