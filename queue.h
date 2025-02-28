#ifndef QUEUE_H
#define QUEUE_H
typedef struct QNode {
	int val;
	struct QNode* next;
} QNode;
typedef struct Queue {
	QNode* top;
	int size;
	QNode* end;
} Queue;
Queue* createQueue(int);
int enqueue(Queue*, int);
int dequeue(Queue*);
int peek(Queue*);	
 Queue* destroyQueue(Queue*);
#endif
