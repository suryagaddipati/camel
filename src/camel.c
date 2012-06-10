#include "dbg.h"
#include <stdio.h>
#include "camel.h"
int *hello(){
  FILE *input = NULL; 
  char line[80];
  /* input = fopen("input.yml","r"); */ 
  /* check(input, "Failed to open %s.", "input.yml"); */
  /* while(fgets(line, 80, input) != NULL) */
  /* { */
  /*   debug("Line: %s", line); */
  /* } */
  return 0;
error:
  if(input) fclose(input);
  return -1;
}
