typedef struct ScalarNode{
  char *value;
  void *next;
}ScalarNode;

typedef struct KeyValueNode{
  char *key;
  void *value;
  void *next;
}KeyValueNode;


void *parse(char *file_name);

void assign_value(ScalarNode *yamlNode, char *line);
