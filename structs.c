#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hello {
  char * s;
  int i;
};

void returnStruct(struct hello *f) {
  printf("%s costs %d\n", f->s, f->i);
}

struct hello * heapStruct(char *a, int b) {

  struct hello *n = malloc(sizeof(struct hello));

  n->s = a;
  n->i = b;

  return n;
}

int main() {
  struct hello * hi1 = heapStruct("Tear of the Goddess", 400);
  returnStruct(hi1);

  struct hello * hi2 = heapStruct("Long Sword", 350);
  returnStruct(hi2);
}
