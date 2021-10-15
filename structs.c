#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char * s;
  int i;
  struct node *next;
};

void returnStruct(struct node *f) {
  printf("%s costs %d\n", f->s, f->i);
}

struct node * heapStruct(char *a, int b) {

  struct node *n = malloc(sizeof(struct node));

  n->s = a;
  n->i = b;

  return n;
}

void print_list(struct node *) {

}

struct node * insert_front(struct node *, int) {
}

struct node * free_list(struct node *) {

}

int main() {
  struct node * hi1 = heapStruct("Tear of the Goddess", 400);
  returnStruct(hi1);

  struct node * hi2 = heapStruct("Long Sword", 350);
  returnStruct(hi2);
}
