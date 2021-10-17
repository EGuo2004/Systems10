#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct operator;

struct operator {
  char * name;
  char * class;
  int cost;
  struct operator *next;
};

void returnStruct(struct operator *o) {
  printf("%s is a %s that costs %d deployment points\n", o->name, o->class, o->cost);
}

void print_list(struct operator *o) {
  while(o) {
    returnStruct(o);
    o = o->next;
  }
}

struct operator * heapStruct(char *a, char *b, int c) {

  struct operator *n = malloc(sizeof(struct operator));

  n->name = a;
  n->class = b;
  n->cost = c;
  n->next = NULL;
  return n;
}

struct operator * insert_front(struct operator *front, char *a, char *b, int c) {
  struct operator *newop = heapStruct(a,b,c);
  newop->next = front;
  return newop;
}

struct operator * free_list(struct operator *o) {
  while(o->next) {
    free_list(o->next);
  }
  free(o->name);
  free(o->class);
  free(o-> cost);
}

int main() {
  struct operator *W = heapStruct("W", "Splash Sniper", 26);
  struct operator *Ines = insert_front(W,"Ines", "Reaper", 21);
  struct operator *Rosmontis = insert_front(Ines,"Rosmontis", "Bombardier", 23);

  print_list(Rosmontis);
  free_list(Rosmontis);
  return 0;
}
