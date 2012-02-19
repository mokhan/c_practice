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
