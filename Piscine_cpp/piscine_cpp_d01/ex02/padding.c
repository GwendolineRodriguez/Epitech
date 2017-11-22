#include <stdlib.h>
#include <stdio.h>

struct foobar
{
  char foo[2];
  int bar;
};

int main(void)
{
 printf(‘‘%zu\n’’, 2 * sizeof(char) + sizeof(int));
 printf(‘‘%zu\n’’, sizeof(struct foobar));
 return EXIT_SUCCESS;
}
