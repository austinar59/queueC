#include "queue.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
 	printf("test\n");
 	Queue* q = createQueue(7);
 	int g = q->top->val;
 	printf("%d\n", g);
  if(enqueue(q, 19)) {
    printf("%d\n", q->end->val);
  }
  int b = dequeue(q);
  printf("%d\n", b);
  b = dequeue(q);
  printf("%d\n", b);
  b = dequeue(q);
  printf("%d\n", b);
  if(destroyQueue(q) == NULL) {
 	return 0;
  } else return 1;
}
