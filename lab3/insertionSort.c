#include "mySort.h"

void mySort(int data[], unsigned int first, unsigned int last) {
    for (unsigned int i = first + 1; i <= last; i++) {
        int current = data[i];
        int j = i - 1;

        while (j >= (int)first && myCompare(data[j], current) > 0) {
            myCopy(&data[j], &data[j + 1]);
            j--;
        }
		if (j != i -1){
        myCopy(&current, &data[j + 1]);
		}
    }
}






