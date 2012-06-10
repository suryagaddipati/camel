#include "minunit.h"
#include <camel.h>
char *test_scalars(){
  debug("here");
  printf("here");
  return hello();
}

char *all_tests() {
  mu_suite_start();
  mu_run_test(test_scalars); 
  return NULL;
}
int main(){
  debug("hello");
  return 0;
}
RUN_TESTS(all_tests);
