#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reverse.h"

typedef int (*Test)();

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
int test_string_reversal()
{
	char input[32];
	strcpy( input, "tell The Truth");
	reverse(input);
	return assert_equals(input, "hturT ehT llet");
}

void run(Test *tests)
{
	int i;
	for (i = 0; i < sizeof(tests); i++) {
		Test test = tests[i];
		if(NULL == test) break;
		test();
	}
}

int main(int argc, const char *argv[])
{
	Test tests[10] = {
		&test_string_reversal
	};

	run(tests);

	return 0;
}
