typedef struct YamlNode{
  char *value;
  struct YamlNode *next;
}YamlNode;

YamlNode *parse(char *file_name);

void assign_value(YamlNode *yamlNode, char *line);
