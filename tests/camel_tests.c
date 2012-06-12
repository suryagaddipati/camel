#include "minunit.h"
#include <camel.h>
#include <dbg.h>
char *test_scalars(){
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  YamlNode *yml = parse(strcat (cwd, "/tests/input.yml"));
  debug("Node 1: %s", yml->value);
  mu_assert(strcmp(yml->value ,"one") , "no dough");
  mu_assert((yml->next->value ,"two") , "no dough");
  return NULL;
}

char *all_tests() {
  mu_suite_start();
  mu_run_test(test_scalars); 
  return NULL;
}
int main(){
  mu_suite_start();
  mu_run_test(test_scalars); 
  return 0;
}
RUN_TESTS(all_tests);
