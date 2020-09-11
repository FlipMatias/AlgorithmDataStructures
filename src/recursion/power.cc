#include <stdio.h>
#include <stdint.h>


static int power(int num, int exp)
{
    if (num == 0) return 1;

    if (exp > 1) {
        return power(num, exp - 1) * num;
    } else {
        return num;
    }
}


int main()
{
    for (int i=1; i <= 10; ++i)
        printf("%d^%d => %d\n", i, 2, power(i, 2));

    printf("\n\n");
    return 0;
}
