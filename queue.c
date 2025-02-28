#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* createQueue(int v) {
  QNode* open = (QNode*) malloc(sizeof(QNode));
  if(open == NULL)
    return NULL;
  open->val = v;
  Queue* q = (Queue*) malloc(sizeof(Queue));
  if(q == NULL)
    return NULL;
  q->top = open;
  q->end = open;
  q->size = 1;
  return q;
}
int enqueue(Queue* q, int v) {
  QNode* insert = (QNode*) malloc(sizeof(QNode));
  if(insert == NULL)
    return 0;
  if(q == NULL)
    return 0;
  insert->val = v;
  q->end->next = insert;
  q->end = insert;
  q->size++;
  return 1;
}
int peek(Queue* q) {
  if(q != NULL && q->top != NULL)
    return q->top->val;
  return 0;
}
int dequeue(Queue* q) {
  if(q == NULL)
    return 0;
  if(q->top == NULL)
    return 0;
  QNode* rNode = q->top;
  int ret = rNode->val;
  if(rNode->next != NULL) {
    q->top = rNode->next;
  } else {
    q->top = NULL;
  }
  free(rNode);
  rNode = NULL;
  return ret;
}
Queue* destroyQueue(Queue* q) {
  free(q);
  q = NULL;
  return q;
}
