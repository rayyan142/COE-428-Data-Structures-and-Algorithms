#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int item);
extern int isEmpty();
extern void addHeap(int itemToAdd);

extern int heapDelete();
extern int getHeapSize();
extern void printXML(int idx, int indentLevel);

int main(int argc, char *argv[]) {
    int inputValue;

    while (scanf("%d", &inputValue) == 1) {
        addHeap(inputValue);
    }

    printf("\nXML Representation of Heap:\n");
    printXML(0, 0);

    printf("\nSorted Order (Heap Delete):\n");
    while (getHeapSize() > 0) {
        int topHeapValue = heapDelete();
        printf("%d\n", topHeapValue);
        push(topHeapValue);

    printf("\nReverse-Sorted Order (Pop from Stack):\n");
    while (!isEmpty()) {
        printf("%d\n", pop());
    }

    exit(0);
}
