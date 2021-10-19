#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct operator;

struct operator {
  char *name;
  char *class;
  int cost;
  struct operator *next;
};

struct operator * heapStruct(char *a, char *b, int c) {

  struct operator *n = malloc(sizeof(struct operator));

  n->name =  malloc(strlen(a) + 1);
  strcpy(n->name,a);
  n->class = malloc(strlen(b) + 1);
  strcpy(n->class,b);
  n->cost = c;
  n->next = NULL;
  return n;
}

void returnStruct(struct operator *o) {
  printf("%s is a %s that costs %d deployment points\n", o->name, o->class, o->cost);
}

void print_list(struct operator *o) {
  while(o) {
    returnStruct(o);
    o = o->next;
  }
}

struct operator * insert_front(struct operator *front, char *a, char *b, int c) {
  struct operator *newop = heapStruct(a,b,c);
  newop->next = front;
  return newop;
}

struct operator * free_list(struct operator *o) {
  if(o->next) {
    free_list(o->next);
  }
  free(o->name);
  free(o->class);
  free(o);
}

struct operator * remove_node(struct operator *front, int data) {
  struct operator *temp = front;
  struct operator *next;
  if(front->cost == data) {
    temp = front->next;
    free(front);
    return temp;
  }
  while(front->next) {
    next = front->next;
    if(next->cost == data) {
      front->next = next->next;
      free(next);
      return front;
    } else {
    front = front->next; 
    }
  }
  return front;
}

