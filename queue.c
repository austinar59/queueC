#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

//TODO: maybe look at taking pointer input for error checking on the user end; implement a getSize function

//creates/returns a Queue pointer with a single member
Queue* createQueue(int v) {
  QNode* open = (QNode*) malloc(sizeof(QNode));
  //checks if node is NULL, if so returns NULL to avoid errors
  if(open == NULL)
    return NULL;
  open->val = v;
  
  //allocates space for Queue pointer and returns NULL on failure
  Queue* q = (Queue*) malloc(sizeof(Queue));
  if(q == NULL)
    return NULL;
  //sets ends to the first member
  q->top = open;
  q->end = open;
  
  //size, like that of arrays, reflects
  q->size = 1;
  return q;
}

int enqueue(Queue* q, int v) {
  //creates new int, returns 0 (false) on fail; this can be used with if statements and the like
  QNode* insert = (QNode*) malloc(sizeof(QNode));
  if(insert == NULL)
    return 0;
  //also returns failure and frees insert on q not existing
  if(q == NULL)
  {
    free(insert);
    return 0;
  }
  //sets node value, sets current end's next to the node, then sets the end to the node and
  //increments size, returns 1 (true)
  insert->val = v;
  q->end->next = insert;
  q->end = insert;
  q->size++;
  return 1;
}

//checks if q or its top null and if not then returns value
int peek(Queue* q) {
  if(q != NULL && q->top != NULL)
    return q->top->val;
  return 0;
}

int dequeue(Queue* q) {
  //q not null safety check
  if(q == NULL)
    return 0;
  //top not null safety check
  if(q->top == NULL)
    return 0;
  //grabs the node to use
  QNode* rNode = q->top;
  //grabs value of rNode
  int ret = rNode->val;
  //checks if there are any values after the current front; if so sets the top to it
  if(rNode->next != NULL) {
    q->top = rNode->next;
  } else {
    //handles case where queue becomes empty
    q->top = NULL;
    q->end = NULL;
  }
  
  free(rNode);
  rNode = NULL;
  return ret;
}

//handles destruction of queue even with elements
Queue* destroyQueue(Queue* q) {
  while(q != NULL && q->top != NULL) {
	dequeue(q);
  }
  free(q);
  return NULL;
}
