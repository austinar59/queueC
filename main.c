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
 	return 0;
}
