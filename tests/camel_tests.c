#include "minunit.h"
#include <unistd.h>
#include <camel.h>
#include <dbg.h>
char *test_scalars()
{
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  ScalarNode *yml = parse(strcat (cwd, "/tests/fixtures/scalar.yml"));
  mu_assert(strcmp(yml->value ,"one") , "no dough");
  mu_assert((((ScalarNode*)yml->next)->value ,"two") , "no dough");
  return NULL;
}

char *test_scalar_to_scalar_mapping()
{
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  /* KeyValueNode *yml = parse(strcat (cwd, "/tests/fixtures/scalar_map.yml")); */
  /* mu_assert(strcmp(yml->key ,"hr") , "no dough"); */
  return NULL;
}

char *all_tests() 
{
  mu_suite_start();
  mu_run_test(test_scalars); 
  mu_run_test(test_scalar_to_scalar_mapping); 
  return NULL;
}
int main(){
  mu_suite_start();
  all_tests();
  return 0;
}
RUN_TESTS(all_tests);
