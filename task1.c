#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("\n");
        return 0;
    } else if (argc > 2) {
        printf("Too many arguments\n");
        return 1;
    }

    char *token = strtok(argv[1], " ");

    /* save the first word */
    char *first_word;
    if (token != NULL) {
        first_word = (char*)malloc(strlen(token));
        strcpy(first_word, token);
        token = strtok(NULL, " ");
    }

    /* print words of the string*/
    while (token != NULL) {
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("%s\n", first_word);

    free(first_word);

    return 0;
}