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

void read_top_test() {
	fprintf(stderr, "Starting read_top_test()...");
	
	int val = 74;
	int val2 = 47;
	stack s = stack_empty();
	s = stack_push(s, val);
	s = stack_push(s, val2);

	if (value_equal(stack_top(s), val))
	{
		fprintf(stderr, "FAIL: Expected top() to return element at top but bottom element");
		stack_kill(s);
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

void top_is_constant() {
	fprintf(stderr, "Starting top_is_constant()...");

	int values[] = {1, 2};
	int read_values[2];
	stack s = stack_empty();

	for (int i = 0; i < 2; i++)
	{
		s = stack_push(s, values[i]);
		values[i] = stack_top(s);
	}

	if (value_equal(read_values[0], read_values[2]))
	{
		fprintf(stderr, "FAIL: top() returns constant value.");
		stack_kill(s);
		exit(EXIT_FAILURE);
	}
	
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

void inserted_elements_at_correct_place() {
	fprintf(stderr, "Starting inserted_elements_at_correct_place()...");

	int n = 5;
	int values[] = {321, 21, 42, 6, 13};
	stack s = stack_empty();

	// Writes values to stack
	for (int i = 0; i < n; i++)
	{
		s = stack_push(s, values[i]);
	}
	
	// read values from stack and compares them
	for (int i = 0; i < n; i++)
	{
		if (!value_equal(values[(n - 1) - i], stack_top(s)))
		{
			fprintf(stderr, "FAIL: Expected top() element nr.%d to be %d, got %d", i+1, values[i], stack_top(s));
			stack_kill(s);
			exit(EXIT_FAILURE);
		}
		s = stack_pop(s);
	}

	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

void inserted_too_many_values() {
	fprintf(stderr, "Starting inserted_too_many_values()...");
	
	int val = 74;
	stack s = stack_empty();
	s = stack_push(s, val);

	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

int main(void)
{
	empty_is_empty_test();
	one_element_in_stack_is_nonempty();
	inserted_element_has_the_right_value();
	read_top_test();
	top_is_constant();
	inserted_elements_at_correct_place();
	inserted_too_many_values();
	
	fprintf(stderr, "SUCCESS: Implementation passed all tests. Normal exit.\n");

	return 0;
}