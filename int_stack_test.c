#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <int_stack.h>

/**
 * Test program to test implementations of int_stack
 * 
 * Author: Felix Vallström (c23fvm)
 * 
 * Hand in date: 
 * 
 * Version:
 *   2024-01-XX: v1.0. First hand in
*/

/**
 * Compares two values stored in the stack
*/
bool value_equal(int v1, int v2) {
	return v1 == v2;
}

void empty_is_empty_test() {
	fprintf(stderr, "Starting empty_is_empty_test()...");

	stack s = stack_empty();

	if (!stack_is_empty(s))
	{
		fprintf(stderr, "FAIL: Expected is_empty(empty()) == true, got false\n");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "Cleaning up..");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

void one_element_in_stack_is_nonempty() {
	fprintf(stderr, "Starting one_element_in_nonempty()...");

	stack s = stack_empty();
	s = stack_push(s, 5);

	if (stack_is_empty(s))
	{
		fprintf(stderr, "FAIL: Expected is_empty() == false, got true\n");
		stack_kill(s);
		exit(EXIT_FAILURE);
	}
	

	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

void inserted_element_has_the_right_value() {
	fprintf(stderr, "Starting inserted_element_has_the_right_value()...");

	int val = 13;
	stack s = stack_empty();
	s = stack_push(s, val);

	int read_value = stack_top(s);

	if (read_value != val)
	{
		fprintf(stderr, "FAIL: Expected top() == %d, got %d\n", val, read_value);
		stack_kill(s);
		exit(EXIT_FAILURE);
	}
	
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

int main(void)
{
	empty_is_empty_test();
	one_element_in_nonempty();
	inserted_element_has_the_right_value();
	
	fprintf(stderr, "SUCCESS: Implementation passed all tests. Normal exit.\n");

	return 0;
}