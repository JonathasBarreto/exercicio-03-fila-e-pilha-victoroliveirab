#include <stdio.h>
#include <stdlib.h>

// Solucao temporaria utilizando arrays porque a de listas nao funciona no spoj --'

//10 99 10 23 55 1024 37 68 12 1 96 6 1024 10 99 96 1 37

void print_queue(int queue[], int size) {
  for (int i=0; i < size; i++) {
    if (queue[i] != 0) {
      printf("%d ",queue[i]);
    }
  }
  printf("\n");
}

int main() {
  int q0, qleft; // initial number of items on queue , num of items leaving
  scanf("%d",&q0);
  int queue[q0];
  for (int i=0; i<q0; i++) {
    scanf("%d",&queue[i]); //id for the i-th item on queue
  }
  //print_queue(queue,q0);
  scanf("%d",&qleft);
  for (int i=0; i<qleft; i++) {
    int id;
    scanf("%d",&id);
    for (int j=0; j<q0; j++) {
      if (queue[j] == id) {
        queue[j] = 0;
        break;
      }
    }
  }
  print_queue(queue,q0);
  return 0;
}