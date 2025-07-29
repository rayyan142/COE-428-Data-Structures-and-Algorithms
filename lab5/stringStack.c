#include <stdio.h>
/**
 *  The functions in this module implement a Stack data structure
 *  of char pointers (aka "strings").
 *
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 strings can be pushed onto
 *  the Stack at any given time.
 */

// Implementation hints:
//   The 3 functions--push, pop and isEmpty--share information
//   about the array used to implement the stack and the index
//   of the "top" of the stack.
//
//   You may want to make these variables global...
//   ...but that would
//   be a mistake (because anyone using the module would have
//   to ensure that they did not use global variables with the
//   same names).
//
//   An alternative in C is a "static global".
//   If a global variable is qualified as "static", it is global only
//   within the source code file where it is declared.
//   In parituclar, it cannot conflict with any other global variable.
//
//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!
//static int top = 0;
//static char * stack[100];

/**
 * pop() removes the top string on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value NULL ((char *) 0) is returned.
 */

// Define maximum stack size
#define maxStackSize 100

// Static global variables for stack implementation
// These are accessible only within this source file.
static int top = 0; // Index to the top of the stack
static char* stack [maxStackSize]; // Stack array to store strings

// Function prototypes
int isEmpty();

/**
 * Pops the top string from the stack and returns it.
 * If the stack is empty, prints an error and returns NULL.
 * @return The top string from the stack, or NULL if empty.
 */
char* pop() {
    if (isEmpty()) {
        fprintf(stderr, "Error: Stack underflow. Cannot pop from an empty stack.\n");
        return NULL; // Return NULL if the stack is empty
    } else {
        char* temp = stack[--top]; // Retrieve the top string and decrement the top index
        return temp;
    }
}

/**
 * Pushes a string onto the stack.
 * If the stack is full, prints an error message.
 * @param thing2push The string to be pushed onto the stack.
 */
void push(char* thing2push) {
    if (top >= maxStackSize) {
        fprintf(stderr, "Error: Stack overflow. Cannot push onto a full stack.\n");
    } else {
        stack[top++] = thing2push; // Place the string on the stack and increment the top index
    }
}

/**
 * Checks if the stack is empty.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty() {
    return top == 0; // Returns 1 (true) if the stack is empty, 0 (false) otherwise
}