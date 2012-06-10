#include "dbg.h"
#include <stdio.h>
#include "camel.h"
int main1(){
  return 0;
}

char *hello(){
  debug("here************");
  FILE *input = NULL; 
  char line[80];
  input = fopen("input.yml","r"); 
  check(input, "Failed to open %s.", "input.yml");
  while(fgets(line, 80, input) != NULL)
  {
    debug("Line: %s", line);
  }
  return "hello";
error:
  if(input) fclose(input);
  return -1;
}
