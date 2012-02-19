#include <stdio.h>
#include <string.h>

int assert_equals(char *actual, char *expected)
{
	int result = strcmp(actual, expected);
	if(result != 0){
		printf("FAIL! actual: '%s', expected: '%s'", actual, expected);
	} else {
		printf("PASS!");
	}
	return result == 0?1:0;
}
