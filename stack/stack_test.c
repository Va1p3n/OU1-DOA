#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack.h>

/**
 * Test program to test implementations of the datatype stack
 * 
 * Author: Felix Vallström (c23fvm)
 * 
 * Date: 2024-02-12
 * 
 * Version:
 *   2024-02-01: v1.0. First hand in
 * 	 2024-02-12: v2.0. Changes to create_stack_with_elements parameter label.
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

/**
 * create_stack_with_elements() - Creates a empty stack and fills it with elements.
 * @values: An array of values to add to the stack.
 * @lenght: How long the array of values is.
 * 
 * Returns: A stack pointer
*/
stack* create_stack_with_elements(int values[], int length) {
	stack *s = stack_empty(free);

	for (int i = 0; i < length; i++)
	{
		s = stack_push(s, create_element(values[i]));
	}
	
	return s;
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

	// Create stack with element from value
	int value[] = {42};
	stack *s = create_stack_with_elements(value, 1);

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
 * element_add_remove_empty() - Tests if pop() does nothing.
 * 
 * Returns: Nothing
*/
void element_add_remove_empty() {
	fprintf(stderr, "Starting element_add_remove_empty()...");

	// Create stack with value from value
	int value[] = {42};
	stack *s = create_stack_with_elements(value, 1);
	
	// Removes value from stack
	s = stack_pop(s);

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
 * inserted_too_many_values() - Test if stack_push adds to many values to the stack.
 * 
 * Returns: Nothing
*/
void inserted_too_many_values() {
	fprintf(stderr, "Starting inserted_too_many_values()...");
	
	// Create stack with element from value
	int value[] = {42, 24};
	stack *s = create_stack_with_elements(value, 2);
	
	//Removes the two added elements
	s = stack_pop(stack_pop(s));

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
 * removed_correct_element() - Tests if pop removes the correct element.
 * 
 * Returns: Nothing.
*/
void removed_correct_element() {
		fprintf(stderr, "Starting removed_correct_element()...");

	// Create stack with value from value
	int value[] = {42, 24};
	stack *s = create_stack_with_elements(value, 2);
	
	// Removes value from stack and reads the top
	s = stack_pop(s);
	int read_value = *((int*)stack_top(s));

	if (read_value != value[0])
	{
		// Fails with error message
		fprintf(stderr, "FAIL: Expected top() == %d, got %d.\n", value[0], read_value);
		stack_kill(s);
		exit(EXIT_FAILURE);
	}
	
	// Everything went as expected, clean up
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

	// Create stack with element from value
	int value[] = {42};
	stack *s = create_stack_with_elements(value, 1);

	// Read top element
	int *read_val = stack_top(s);

	// Expecting read_val == val
	if (*read_val != value[0])
	{
		// Fail with error message
		fprintf(stderr, "FAIL: Expected top() == %d, got %d.\n", value[0], *read_val);
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

	// Create stack with element from values
	int values[] = {42, 24};
	stack *s = create_stack_with_elements(values, 2);

	// Read top
	int read_val = *((int*)stack_top(s));

	if (read_val != values[1])
	{
		// Fails with error message
		fprintf(stderr, "FAIL: Expected top() == %d, got %d.\n", values[2], read_val);
	}
	
	// Everything went as expected, clean up
	fprintf(stderr, "Cleaning up...");
	stack_kill(s);
	fprintf(stderr, "DONE!\n");
}

/**
 * top_is_constant() - Tests if top returns constant values
 * 
 * Returns: Nothing.
*/
void top_is_constant() {
	fprintf(stderr, "Starting top_is_constant()...");

	// Create stack with element from values
	int values[] = {42, 24, 64};
	stack *s = create_stack_with_elements(values, 3);

	//Read values from stack
	int read_val1 = *(int*)stack_top(s);
	s = stack_pop(s);
	int read_val2 = *(int*)stack_top(s);

	// value_equal should be false here
	if (value_equal(&read_val1, &read_val2))
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

	// Create stack with element from values
	int n = 5;
	int values[] = {321, 21, 42, 6, 13};
	stack *s = create_stack_with_elements(values, n);
	
	// Loops through the stack
	for (int i = 0; i < n; i++)
	{
		// Read top
		int *read_val = ((int*)stack_top(s));

		// read values from stack and compares them
		if (!value_equal(&values[(n - 1) - i], read_val))
		{
			// Fail with error message
			fprintf(stderr, "FAIL: Expected top() element nr.%d to be %d, got %d.\n", i+1, 
				values[(n - 1) - i], *read_val);
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
 * main() - Runs all the tests.
*/
int main(void)
{
	empty_returns_non_null();
	empty_is_empty();
	one_element_is_non_empty();
	element_add_remove_empty();
	inserted_too_many_values();
	removed_correct_element();
	inserted_element_has_correct_value();
	read_top_test();
	top_is_constant();
	inserted_elements_at_correct_place();

	fprintf(stderr, "SUCCESS: Implementation passed all tests. Normal exit.\n");

	return 0;
}
