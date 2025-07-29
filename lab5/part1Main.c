
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern void push(char*);
extern char* pop();
extern int isEmpty();

#define maxTagLength 100

int main() {
    char currentChar, lastChar = ' ';
    char tagBuffer[maxTagLength];  
    int tagLength = 0;           


    while ((currentChar = getchar()) != EOF) {
        if (lastChar == '<' && currentChar != '/') {
            tagLength = 0;

            while (isalpha(currentChar)) {
                if (tagLength < maxTagLength - 1) {
                    tagBuffer[tagLength++] = currentChar;
                }
                currentChar = getchar();
            }
            tagBuffer[tagLength] = '\0';

            if (currentChar != '>') {
                fprintf(stderr, "Error: invalid start tag\n");
                exit(EXIT_FAILURE);
            }

            push(strdup(tagBuffer));
        } 

        else if (lastChar == '<' && currentChar == '/') {
            tagLength = 0;

            currentChar = getchar();
            while (isalpha(currentChar)) {
                if (tagLength < maxTagLength - 1) {
                    tagBuffer[tagLength++] = currentChar;
                }
                currentChar = getchar();
            }
            tagBuffer[tagLength] = '\0';


            if (currentChar != '>') {
                fprintf(stderr, "Error: invalid end tag\n");
                exit(EXIT_FAILURE);
            }


            char *startTag = pop();
            if (startTag == NULL) {
                fprintf(stderr, "Error: empty stack\n");
                exit(EXIT_FAILURE);
            }
            if (strcmp(startTag, tagBuffer) != 0) {
                fprintf(stderr, "Error: mismatched tags\n");
                exit(EXIT_FAILURE);
            }
            free(startTag);
        }
        lastChar = currentChar;
    }

    if (!isEmpty()) {
        fprintf(stderr, "Error: unclosed tag(s)\n");
        exit(EXIT_FAILURE);
    }

    printf("XML expression is valid\n");
    return 0;
}
