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
bool value_equal(int *v1, int *v2) {
	return *v1 == *v2;
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

void print_f(void* a) {
	printf("%d", *((int*)a));
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
		fprintf(stderr, "FAIL: Expected is_empty() == false, got true.\n");
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

	// Read top element
	int *read_val = stack_top(s);

	// Expecting read_val == val
	if (*read_val != *val)
	{
		// Fail with error message
		fprintf(stderr, "FAIL: Expected top() == %d, got %d.\n", *val, *read_val);
		stack_kill(s);
		exit(EXIT_FAILURE);
	}
	
	// Everything went as expected, clean up
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

	// Create empty stack, values and pushes them to the stack
	stack *s = stack_empty(free);
	int *val1 = create_element(42);
	int *val2 = create_element(24);
	s = stack_push(s, val1);
	s = stack_push(s, val2);

	if (stack_top(s) != val2)
	{
		// Fails with error message
		fprintf(stderr, "FAIL: Expected top() == %d, got %d.\n", *val2, *(int*)stack_top(s));
	}
	
	// Everything went as expected, clean up
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * top_is_constant() - Tests if top returns constant values
*/
void top_is_constant() {
	fprintf(stderr, "Starting top_is_constant()...");

	// Create empty stack, values and pushes them to the stack
	stack *s = stack_empty(free);
	int *values[] = {create_element(42), create_element(24)};
	int *read_values[2];

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
	
	// Everything went as expected, clean up
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
	int *values[] = {
		create_element(321), 
		create_element(21), 
		create_element(42), 
		create_element(6), 
		create_element(13)
	};
	stack *s = stack_empty(free);

	// Pushes values to stack
	for (int i = 0; i < n; i++)
	{
		s = stack_push(s, values[i]);
	}
	
	// Loops through the stack
	for (int i = 0; i < n; i++)
	{
		// read values from stack and compares them
		if (!value_equal(values[(n - 1) - i], (int*)stack_top(s)))
		{
			// Fail with error message
			fprintf(stderr, "FAIL: Expected top() element nr.%d to be %d, got %d.\n", i+1, 
				*(values[(n - 1) - i]), *(int*)stack_top(s));
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
	int *val = create_element(42);
	stack *s = stack_empty(free);
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
 * main() - Runs all the tests.
*/
int main(void)
{
	empty_returns_non_null();
	empty_is_empty();
	one_element_is_non_empty();
	inserted_element_has_correct_value();
	read_top_test();
	top_is_constant();
	inserted_elements_at_correct_place();
	inserted_too_many_values();

	return 0;
}
