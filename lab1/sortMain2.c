#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"
int main(int argc, char * argv[]) {
	int data[100000]; /* Array of ints to sort */
	int nDataItems; /* number of actual items in the array */
	int i;
	
	/* Test data */
	
	if (argc > 1){
		nDataItems = argc - 1;
		for (i = 1; i < argc; i++){
			data[i-1] = atoi(argv[i]);
		}
		
		mySort(data, nDataItems);
		
		for (i = 0; i < nDataItems; i++){
			printf("%d\n", data[i]);
		}
		
	} else {
		nDataItems = 4;
		data[0] = 10;
		data[1] = 20;
		data[2] = 30;
		data[3] = 40;
		mySort(data, nDataItems);
			
	for (i = 0; i < nDataItems; i++) {
		printf("%d\n", data[i]);
	}
	}
	exit(0);
}
