#include <stdio.h>

static void printA(int);
static void printB(int);


static void printA(int n)
{
    if (n > 0) {
        printB(n - 1);
        printf("%d\n", n);
    }
}


static void printB(int n)
{
    if (n > 0) {
        printA(n - 1);
        printf("%d\n", n);
    }
}


/*int main()
{
    printA(5);

    printf("\n\n");
    return 0;
}*/
