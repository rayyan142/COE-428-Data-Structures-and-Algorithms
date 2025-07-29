#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv) {
    int numberDisks;
    int fromID;
    int toID;

    if (argc == 1) {
        towers(3, 1, 2);

    } else if (argc == 2) {
        numberDisks = atoi(argv[1]);

        if (numberDisks <= 0) {  
            fprintf(stderr, "Invalid amount of disks\n");
            exit(1);
        }

        towers(numberDisks, 1, 2);

    } else if (argc == 4) {
        numberDisks = atoi(argv[1]);
        fromID = atoi(argv[2]);
        toID = atoi(argv[3]);
        int errorCode = 0;

        if (numberDisks <= 0) {
            errorCode = 1;
        } else if ((fromID < 1 || fromID > 3) || (toID < 1 || toID > 3)) {
            errorCode = 2;
        } else if (fromID == toID) {
            errorCode = 3;
        }

        switch (errorCode) {
            case 1:
                fprintf(stderr, "Invalid amount of disks\n");
                exit(1);
            case 2:
                fprintf(stderr, "Invalid tower numbers, the towers must be 1, 2 or 3\n");
                exit(1);
            case 3:
                fprintf(stderr, "Invalid tower numbers, the origin and destination cannot be the same\n");
                exit(1);
            default:
                towers(numberDisks, fromID, toID);
                break;
        }

    } else {
        fprintf(stderr, "Incorrect invocation\n");
        exit(1);
    }

    exit(0);
}

