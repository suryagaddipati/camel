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

 ScalarYamlNode *yamlNode , *currentNode;
  yamlNode = malloc(sizeof(ScalarYamlNode)); 
  currentNode = yamlNode;
  while(fgets(line, 80, input) != NULL)
  {
   if(line[0] == '-' && line[1] == ' '){
     assign_value(currentNode, line);
     currentNode->next = malloc(sizeof(ScalarYamlNode)); 
     currentNode = currentNode->next;
   }
  }
  return yamlNode;
error:
  if(input) fclose(input);
  return  NULL;
}

void assign_value(ScalarYamlNode *yamlNode, char *line){
  yamlNode->value = malloc(80 * sizeof(char));
  int i;
  for( i=2; line[i] != '\0' ; i ++){
    yamlNode->value[i-2] = line[i];
  }
    yamlNode->value[i-2] = '\0';
}
