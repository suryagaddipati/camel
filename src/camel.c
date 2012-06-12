#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include "camel.h"
YamlNode *parse(char *file_name){
  FILE *input = NULL; 
  YamlNode *yamlNode , *currentNode;
  debug("Parsing file %s", file_name);
  char line[80];
  input = fopen(file_name,"r"); 
  check(input, "Failed to open %s.", "input.yml");
  yamlNode = malloc(sizeof(YamlNode)); 
  currentNode = yamlNode;
  while(fgets(line, 80, input) != NULL)
  {
   if(line[0] == '-'){
     assign_value(currentNode, line);
     currentNode->next = malloc(sizeof(YamlNode)); 
     currentNode = currentNode->next;
   }
  }
  return yamlNode;
error:
  if(input) fclose(input);
  return  NULL;
}

void assign_value(YamlNode *yamlNode, char *line){
  yamlNode->value = malloc(80 * sizeof(char));
  int i;
  for( i=2; line[i] != '\0' ; i ++){
    yamlNode->value[i-2] = line[i];
  }
    yamlNode->value[i-2] = '\0';
}
