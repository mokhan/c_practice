#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* input){
  char *begin, *end;
  char tmp;
  int i;

  begin = &input[0];
  end = &input[strlen(input)-1];
  for (i = 0; i < strlen(input)-1; i++) {
    if(begin == end) break;
    tmp = *end;
    *end = *begin;
    *begin = tmp;
    begin++;
    end--;
  }
}

int main(int argc, const char *argv[])
{
  unsigned char input[128];

  /*printf("what is your name: ");*/
  /*scanf("%s", input);*/

  printf("enter a string to reverse: ");
  scanf("%s", input);

  reverse(input);
  printf("%s", input);

  /*printf("goodbye %s", input);*/
  return 0;
}
