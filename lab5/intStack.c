/**
 *  The functions in this module implement a Stack data structure
 *  of integers.  (Note that chars are also integers so this
 *  integer Stack can be used for chars as well.)
 *
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 integers can be pushed onto
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

#include <stdio.h>

//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!

static int stackTop = 0; // Index of the next available slot, acts as the "top" of the stack.
static int intStack[100];


/**
 * pop() removes the top integer on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value -1 (minus one) is returned.
 */

int pop() {
    if (stackTop == 0) { // Check if the stack is empty
        fprintf(stderr, "Error: Cannot pop from an empty stack.\n");
        return -1; // Indicate failure to pop from an empty stack
    }

    // Decrement stackTop before accessing the array to get the last pushed item
    return intStack[--stackTop];
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(int item) {
    if (stackTop == 100) { // Ensure the stack doesn't overflow
        fprintf(stderr, "Error: Stack is full. Unable to push new item.\n");
        return; // Early return to avoid pushing onto a full stack
    }

    // Add item to the stack and increment stackTop
    intStack[stackTop++] = item;
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty() {
    return stackTop == 0; // Return 1 (true) if empty, 0 (false) otherwise
}
