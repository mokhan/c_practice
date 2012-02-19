#include <stdio.h>
#include <string.h>
#include "reverse.h"
#include "assertions.h"

typedef int (*Test)();

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

void run_tests()
{
	Test tests[10] = {
		&test_string_reversal
	};

	run(tests);
}
