#include "minunit.h"
#include <unistd.h>
#include <camel.h>
#include <dbg.h>
char *test_scalars()
{
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  ScalarYamlNode *yml = parse(strcat (cwd, "/tests/fixtures/scalar.yml"));
  mu_assert(strcmp(yml->value ,"one") , "no dough");
  mu_assert((((ScalarYamlNode*)yml->next)->value ,"two") , "no dough");
  return NULL;
}

char *test_scalar_to_scalar_mapping()
{
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  ScalarYamlNode *yml = parse(strcat (cwd, "/tests/fixtures/scalar_map.yml"));
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
  mu_run_test(test_scalars); 
  return 0;
}
RUN_TESTS(all_tests);
