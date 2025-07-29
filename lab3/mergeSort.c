#include "mySort.h"

void merge(int data[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int leftSubarray[leftSize], rightSubarray[rightSize];

    for (int i = 0; i < leftSize; i++)
        myCopy(&data[left + i], &leftSubarray[i]);
    for (int j = 0; j < rightSize; j++)
        myCopy(&data[middle + 1 + j], &rightSubarray[j]);

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (myCompare(leftSubarray[i], rightSubarray[j]) <= 0) {
            myCopy(&leftSubarray[i], &data[k]);
            i++;
        } else {
            myCopy(&rightSubarray[j], &data[k]);
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        myCopy(&leftSubarray[i], &data[k]);
        i++;
        k++;
    }

    while (j < rightSize) {
        myCopy(&rightSubarray[j], &data[k]);
        j++;
        k++;
    }
}

void mySort(int data[], unsigned int first, unsigned int last) {
    if (first < last) {
        int middle = first + (last - first) / 2;

        mySort(data, first, middle);
        mySort(data, middle + 1, last);

        merge(data, first, middle, last);
    }
}




