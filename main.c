#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reverse.h"

int assert_equals(char *actual, char *expected)
{
	int ret;
	ret = strcmp(actual, expected);
	if(ret != 0){
		printf("FAIL! actual: '%s', expected: '%s'", actual, expected);
	} else {
		printf("PASS! actual: '%s', expected: '%s'", actual, expected);
	}

	return ret == 0?1:0;
}
int test_string_reversal()
{
	char input[32];
	strcpy( input, "tell The Truth");
	reverse(input);
	return assert_equals(input, "hturT ehT llet");
}

typedef int (*Test)();

int main(int argc, const char *argv[])
{
	int i;
	Test tests[10] = {NULL};
	tests[0] = &test_string_reversal;

	for (i = 0; i < sizeof(tests); i++) {
		Test test;
		int result;
		test = tests[i];
		if(NULL == test) break;
		result = test();
		printf("%s \n",result == 1?"PASS":"FAIL");
	}

	return 0;
}
