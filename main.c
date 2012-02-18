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
void test_string_reversal()
{
	char input[32];
	strcpy( input, "tell The Truth");
	reverse(input);
	assert_equals(input, "hturT ehT llet");
}

int main(int argc, const char *argv[])
{
	test_string_reversal();
	return 0;
}
