#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int main() {
  struct operator *W = heapStruct("W", "Splash Sniper", 26);
  struct operator *Ines = insert_front(W,"Ines", "Reaper", 21);
  struct operator *Rosmontis = insert_front(Ines,"Rosmontis", "Bombardier", 23);

  print_list(Rosmontis);
  free_list(Rosmontis);
  return 0;
}
