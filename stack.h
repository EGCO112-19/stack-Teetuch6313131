
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value)
{
  Node *new_node =(Node *)malloc(sizeof(Node));
  if(new_node){
  new_node->data=value;
  new_node-> nextPtr= s->top;
  s->top =new_node;
  s->size=s->size+1;
}
}
char pop(StackPtr s)
{
  NodePtr t =s->top;
  int value;
  t=s->top;
  value=t->data;
  s->top=t->nextPtr;
  free(t);
  s->size=s->size-1;
  return value;
}
void pop_all(StackPtr s)
{
  NodePtr t ;
  while(s->top!=NULL)
  {
    t=s->top;
    printf("popping %c\n",t->data);
    s->top=t->nextPtr;
    free(t);
    s->size--;
  }
  
}
#endif
