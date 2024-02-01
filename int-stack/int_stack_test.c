#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <int_stack.h>

/**
 * Test program to test implementations of the datatype int_stack
 * 
 * Author: Felix Vallström (c23fvm)
 * 
 * Hand in date: 
 * 
 * Version:
 *   2024-01-XX: v1.0. First hand in
*/

/**
 * value_equal() - Compares two values stored in the stack.
 * @v1: value (integer) 1
 * @v2: value (integer) 2
 * 
 * Returns: True if the values are the same, otherwise false.
*/
bool value_equal(int v1, int v2) {
	return v1 == v2;
}

/**
 * empty_is_empty() - Test that stack_empty is empty.
 * 
 * Returns: Nothing.
*/
void empty_is_empty() {
	fprintf(stderr, "Starting empty_is_empty()...");

	// Creates empty stack.
	stack s = stack_empty();

	// Stack should be empty.
	if (!stack_is_empty(s))
	{
		// Fails with error message
		fprintf(stderr, "FAIL: Expected is_empty(empty()) == true, got false\n");
		exit(EXIT_FAILURE);
	}

	// Everything went as planned, clean up
	fprintf(stderr, "Cleaning up..");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * one_element_in_stack_is_nonempty() - Test that is_empty returns false if the stack has items.
 * 
 * Returns: Nothing.
*/
void one_element_in_stack_is_nonempty() {
	fprintf(stderr, "Starting one_element_in_stack_is_nonempty()...");

	// Creates empty stack and pushes a value to it
	stack s = stack_empty();
	s = stack_push(s, 5);

	// stack_is_empty() should return false
	if (stack_is_empty(s))
	{
		// Fail with error message
		fprintf(stderr, "FAIL: Expected is_empty() == false, got true\n");
		stack_kill(s);
		exit(EXIT_FAILURE);
	}
	
	// Everything went as planned, clean up
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * inserted_element_has_the_right_value() - Tests that inserted element gets inserted to the stack
 * 		with the correct value.
 * 
 * Returns: Nothing
*/
void inserted_element_has_the_right_value() {
	fprintf(stderr, "Starting inserted_element_has_the_right_value()...");

	// Creates a stack and adds a specific to the stack
	int val = 13;
	stack s = stack_empty();
	s = stack_push(s, val);

	// Reads the top value of the stack 
	int read_value = stack_top(s);

	// read_value should be the same as val
	if (read_value != val)
	{
		// Fails with error message
		fprintf(stderr, "FAIL: Expected top() == %d, got %d.\n", val, read_value);
		stack_kill(s);
		exit(EXIT_FAILURE);
	}
	
	// Everything went as planned, clean up
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * read_top_test() - Tests that stack_top() reads the correct element.
 * 
 * Returns: Nothing.
*/
void read_top_test() {
	fprintf(stderr, "Starting read_top_test()...");
	
	// Creates empty stack and pushes two valus to it
	int val = 74;
	int val2 = 47;
	stack s = stack_empty();
	s = stack_push(s, val);
	s = stack_push(s, val2);

	int read_val = stack_top(s);

	// Expects value_equal to be false.
	if (!value_equal(read_val, val2))
	{
		// Fails with error message
		fprintf(stderr, "FAIL: Expected top() to return %d, got %d.\n", val2, read_val);
		stack_kill(s);
		exit(EXIT_FAILURE);
	}

	// Everything went as planned, clean up
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * top_is_constant() - Tests wether the value that top() reads is constant.
 * 
 * Returns: Nothing
*/
void top_is_constant() {
	fprintf(stderr, "Starting top_is_constant()...");

	// Creates empty stack, array of values to write and an empty array to fill with read values.
	int values[] = {1, 2};
	int read_values[2];
	stack s = stack_empty();

	// Pushes the values to the stack and reads top().
	for (int i = 0; i < 2; i++)
	{
		s = stack_push(s, values[i]);
		read_values[i] = stack_top(s);
	}

	// value_equal should be false here
	if (value_equal(read_values[0], read_values[1]))
	{
		// Fails with error message
		fprintf(stderr, "FAIL: top() returns constant value.\n");
		stack_kill(s);
		exit(EXIT_FAILURE);
	}
	
	// Everything went as planned, clean up
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * inserted_elements_at_correct_place() - Tests wether stack_push() adds elements att wrong places.
 * 		Also tests if pop removes more than one element, removes wrong element, does nothing.
 * 
 * Returns: Nothing.
*/
void inserted_elements_at_correct_place() {
	fprintf(stderr, "Starting inserted_elements_at_correct_place()...");

	// Creates empty stack and an array of values to push to the stack
	int n = 5;
	int values[] = {321, 21, 42, 6, 13};
	stack s = stack_empty();

	// Pushes values to stack
	for (int i = 0; i < n; i++)
	{
		s = stack_push(s, values[i]);
	}
	
	// Loops through the stack
	for (int i = 0; i < n; i++)
	{
		// read values from stack and compares them
		if (!value_equal(values[(n - 1) - i], stack_top(s)))
		{
			// Fail with error message
			fprintf(stderr, "FAIL: Expected top() element nr.%d to be %d, got %d.\n", i+1, values[(n - 1) - i], stack_top(s));
			stack_kill(s);
			exit(EXIT_FAILURE);
		}

		// Removes top element from stack.
		s = stack_pop(s);
	}

	// Everything went as planned
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * inserted_too_many_values() - Test if stack_push adds to many values to the stack.
 * 		Also catches if pop does not remove the last/only element in the stack.
 * 
 * Returns: nothing
*/
void inserted_too_many_values() {
	fprintf(stderr, "Starting inserted_too_many_values()...");
	
	// Creates empty stack and pushes a value to it and removes that value
	int val = 74;
	stack s = stack_empty();
	s = stack_pop(stack_push(s, val));

	// stack_is_empty() should return true
	if (!stack_is_empty(s))
	{
		// Fail with error message
		fprintf(stderr, "FAIL: Expected stack_is_empty() == true, got false. Too many elements added.\n");
		stack_kill(s);
		exit(EXIT_FAILURE);
	}
	
	// Everything went as planned, clean up.
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * main() - Runs all the tests and outputs it all tests passed.
*/
int main(void)
{
	empty_is_empty();
	one_element_in_stack_is_nonempty();
	inserted_element_has_the_right_value();
	read_top_test();
	top_is_constant();
	inserted_elements_at_correct_place();
	inserted_too_many_values();
	
	fprintf(stderr, "SUCCESS: Implementation passed all tests. Normal exit.\n");

	return 0;
}