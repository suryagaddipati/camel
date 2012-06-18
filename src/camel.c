#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include "camel.h"
void *parse(char *file_name){
  FILE *input = NULL; 
  debug("Parsing file %s", file_name);
  char line[80];
  input = fopen(file_name,"r"); 
  check(input, "Failed to open %s.", "input.yml");

 Node *rootNode =NULL , *currentNode = NULL;
  while(fgets(line, 80, input) != NULL)
  {
   if(line[0] == '-' && line[1] == ' '){
     if( rootNode == NULL){
       rootNode = malloc(sizeof(ScalarNode)); 
       currentNode = rootNode;
     }
     assign_value(currentNode, line);
     currentNode->next = malloc(sizeof(ScalarNode)); 
     currentNode = currentNode->next;
   }
  }
  return rootNode;
error:
  if(input) fclose(input);
  return  NULL;
}

void assign_value(ScalarNode *rootNode, char *line){
  rootNode->value = malloc(80 * sizeof(char));
  int i;
  for( i=2; line[i] != '\0' ; i ++){
    rootNode->value[i-2] = line[i];
  }
    rootNode->value[i-2] = '\0';
}
