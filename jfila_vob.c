#include <stdio.h>
#include <stdlib.h>

struct queueinfo {
  struct item* first;
  struct item* last;
  int size;
};

struct item {
  int id;
  struct item* next;
};

void print_queue(struct item* curr) {
  while (curr) {
    printf("%d ",curr->id);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  int qleft; // initial number of items on queue , num of items leaving
  struct queueinfo queueinfo;
  scanf("%d",&queueinfo.size);
  struct item * queue = (struct item*)malloc(queueinfo.size*sizeof(struct item));
  for (int i=0; i<queueinfo.size; i++) {
    scanf("%d",&(queue+i)->id); //id for the i-th item on queue
    (queue+i-1)->next = NULL;
    queueinfo.last = queue+i;
    if (i) {
      (queue+i-1)->next = queue+i;
    }
    else {
      queueinfo.first = queue;
    }
  }

  scanf("%d",&qleft);
  int * ids = (int *)malloc(qleft*sizeof(int));
  for (int i=0; i<qleft; i++) {
    scanf("%d",ids+i);
  }

  for (int i=0; i<qleft; i++) {
    int takeid = *(ids+i);
    struct item* curr = (struct item*)malloc(sizeof(struct item));
    curr = queueinfo.first;
    if (curr->id == takeid) {
      queueinfo.first = curr->next;
    }
    else {
      while (curr->next->id != takeid) {
        curr = curr->next;
      }
      struct item* next = (struct item*)malloc(sizeof(struct item));
      next = curr->next;
      curr->next = next->next;
    }
  }
  print_queue(queueinfo.first);
  return 0;
}