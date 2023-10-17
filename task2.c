#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("\n");
        return 0;
    }

    int number = strtol(argv[1], NULL, 10);

    if (number == 1 || number == 0) {
        printf("%d\n", number);
        return 0;
    }

    /* divide the number by 2 as long as possible */
    while (number % 2 == 0) {
        printf("2");
        number /= 2;
        if (number != 1)
            printf("*");
    }

    /* find the remaining factors*/
    while (number != 1) {
        for (int i = 3; i <= number; i += 2) {
            if (number % i == 0) {
                printf("%d", i);
                number /= i;
                if (number != 1)
                    printf("*");
                break;
            }
        }
    }
    puts("");

    return 0;
}