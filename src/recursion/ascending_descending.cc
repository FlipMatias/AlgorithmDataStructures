#include <stdio.h>


//recursive print
static void ascendingPrint(unsigned int n)
{
    if (n == 0) {
        return;
    } else {
        printf("%d ", n);
        ascendingPrint1(n - 1);
    }
}


//print on returning phase
static void descendingPrint(unsigned int n)
{
    if (n == 0) {
        return;
    } else {
        descendingPrint(n - 1);
        printf("%d ", n); //return phase
    }
}


int main()
{
    ascendingPrint(5);
    printf("\n");
    descendingPrint((5);

    return 0;
}
