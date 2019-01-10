// 'Hello World!' program

#include <stdio.h>
#include <string.h>

void concatCharArray(char *result, const char *a, const char *b, const char *c);

int main()
{
    printf("Hello World!\n");

    char concatString[200];
    concatCharArray(concatString, "I am ", "testing ", "llvm!\n");
    printf("%s", concatString);

    return 0;
}

void concatCharArray(char *result, const char *a, const char *b, const char *c)
{
    strcpy(result, a);
    strcat(result, b);
    strcat(result, c);
}
