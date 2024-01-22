#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <int_stack.h>

/**
 * Test program to test implementations of int_stack
*/


/**
 * Compares two values
*/
bool value_equal(int v1, int v2) {
	return v1 == v2;
}

void empty_is_empty_test() {
	fprintf(stderr, "Starting empty_is_empty_test()...");

	stack test = stack_empty();

	if (!stack_is_empty(test))
	{
		fprintf(stderr, "FAIL: Expected is_empty(empty()) == true, got false\n");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "Cleaning up..");
	stack_kill(test);
	fprintf(stderr, "DONE!\n");
}

int main(void)
{
	empty_is_empty_test();
	
	fprintf(stderr, "SUCCESS: Implementation passed all tests. Normal exit.\n");

	return 0;
}