typedef struct ScalarYamlNode{
  char *value;
  void *next;
}ScalarYamlNode;

typedef struct KeyValueYamlNode{
  char *key;
  void *value;
  void *next;
}KeyValueYamlNode;


void *parse(char *file_name);

void assign_value(ScalarYamlNode *yamlNode, char *line);
