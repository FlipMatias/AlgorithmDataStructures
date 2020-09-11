#include <stdio.h>


static int count(int n)
{
    if (n != 0) {
        printf("%d ", n);
        return count(count(n-1));
    }

    return n;
}


int main()
{
    int res = count(200);
    printf("%d ", res);

    printf("\n\n");
    return 0;
}
