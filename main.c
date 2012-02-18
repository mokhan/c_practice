#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reverse.h"

int main(int argc, const char *argv[])
{
  char input[128];

  printf("enter a string to reverse: ");
  gets(input);
  reverse(input);
  printf("%s", input);

  return 0;
}
