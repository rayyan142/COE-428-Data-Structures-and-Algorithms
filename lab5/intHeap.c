#include <stdio.h>
#include <string.h>

static int heapSize = 0;
static int intHeap[100];

void maxHeapify(int idx);
void siftUp(int idx);
void printXML(int idx, int depth);

int heapDelete() {
    if (heapSize == 0) {
        fprintf(stderr, "Error: The heap is empty.\n");
        return -1;
    }

    int rootValue = intHeap[0];
    intHeap[0] = intHeap[--heapSize];
    maxHeapify(0);
    return rootValue;
}

void addHeap(int item) {
    if (heapSize >= 100) {
        fprintf(stderr, "Error: The heap is at full capacity.\n");
        return;
    }

    intHeap[heapSize] = item;
    siftUp(heapSize);
    heapSize++;
}

int getHeapSize() {
    return heapSize;
}

void maxHeapify(int idx) {
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    int maxIdx = idx;
    if (leftChild < heapSize && intHeap[leftChild] > intHeap[maxIdx])
        maxIdx = leftChild;
    if (rightChild < heapSize && intHeap[rightChild] > intHeap[maxIdx])
        maxIdx = rightChild;

    if (maxIdx != idx) {
        int swap = intHeap[idx];
        intHeap[idx] = intHeap[maxIdx];
        intHeap[maxIdx] = swap;
        maxHeapify(maxIdx);
    }
}

void siftUp(int idx) {
    while (idx > 0) {
        int parentIdx = (idx - 1) / 2;
        if (intHeap[parentIdx] >= intHeap[idx])
            break;
        
        int swap = intHeap[idx];
        intHeap[idx] = intHeap[parentIdx];
        intHeap[parentIdx] = swap;
        
        idx = parentIdx;
    }
}

void printXML(int idx, int depth) {
    char indent[200];
    memset(indent, ' ', depth * 2);
    indent[depth * 2] = '\0';

    if (2 * idx + 1 >= heapSize) {
        printf("%s<node id=\"%d\" />\n", indent, intHeap[idx]);
        return;
    }

    printf("%s<node id=\"%d\">\n", indent, intHeap[idx]);
    if (2 * idx + 1 < heapSize) printXML(2 * idx + 1, depth + 1);
    if (2 * idx + 2 < heapSize) printXML(2 * idx + 2, depth + 1);
    printf("%s</node>\n", indent);
}