#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack.h>

/**
 * Test program to test implementations of the datatype stack
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
 *  create_element() - Creates a dynamical element (integer)
 * 	@i: Integer to assign as value
 * 
 *  Returns: A pointer to a integer
*/
int *create_element(int i) {
	int *p = malloc(sizeof(p));
	*p = i;
	return p;
}

/**
 * empty_returns_non_null() - Tests that stack_empty() returns a pointer to a stack.
 * 
 * Returns: Nothing.
*/
void empty_returns_non_null() {
	fprintf(stderr, "Starting empty_returns_non_null()...");

	// Creates an empty stack
	stack *s = stack_empty(free);

	// Stack should not be null
	if (s == NULL)
	{
		//Fail with error message
		fprintf(stderr, "FAIL: Expected a non-null pointer, got NULL.\n");
		exit(EXIT_FAILURE);
	}
	

	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * empty_is_empty() - Tests that a newly created stack is empty.
 * 
 * Returns: Nothing.
*/
void empty_is_empty() {
	fprintf(stderr, "Starting empty_is_empty()...");

	//Create an empty stack
	stack *s = stack_empty(free);

	// Expecting is_empty() to be true
	if (!stack_is_empty(s))
	{
		// Fails with error message
		fprintf(stderr, "FAIL: Expected is_empty() == true, got false.\n");
		stack_kill(s);
		exit(EXIT_FAILURE);
	}

	// Everything went as expected, clean up
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");	
}

/**
 * one_element_is_non_empty() - Tests that is_empty returns false if stack has elements.
 * 
 * Returns: Nothing.
*/
void one_element_is_non_empty() {
	fprintf(stderr, "Starting one_element_is_non_empty()...");

	// Creating an empty stack
	stack *s = stack_empty(free);

	// Create dynamic element, pushes it to the stack
	int *val = create_element(42);
	s = stack_push(s, val);

	if (stack_is_empty(s))
	{
		// Fail with error message
		fprintf(stderr, "FAIL: Expected is_empty() == false, got true");
		stack_kill(s);
		exit(EXIT_FAILURE);
	}

	//Everything went as expected, clean up
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * inserted_element_has_correct_value() - Tests that pushed element has correct value.
 * 
 * Returns: Nothing.
*/
void inserted_element_has_correct_value() {
	fprintf(stderr, "Starting inserted_element_has_correct_value()...");

	// Create empty stack, adds value to stack
	stack *s = stack_empty(free);
	int *val = create_element(42);
	s = stack_push(s, val);

	int *read_val = stack_top(s);

	if (*read_val != *val)
	{
		// Fail with error message

	}
	

}

/**
 * main() - Runs all the tests.
*/
int main(void)
{
	empty_returns_non_null();
	empty_is_empty();
	one_element_is_non_empty();

	return 0;
}
