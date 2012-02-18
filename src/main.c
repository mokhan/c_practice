#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* input){
  char *start = input, *end, tmp;

  end = &input[strlen(input)-1];

  while(start != end){
    tmp = *end;
    *end = *start;
    *start = tmp;
    ++start;
    if(start == end) break;
    --end;
  }
}

int main(int argc, const char *argv[])
{
  char input[128];

  printf("enter a string to reverse: ");
  gets(input);
  reverse(input);
  printf("%s", input);

  return 0;
}
