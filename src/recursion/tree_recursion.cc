#include <stdio.h>


static void treeFunction(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        treeFunction(n - 1);
        treeFunction(n - 1);
    }
}


int main()
{
    treeFunction(3);

    printf("\n\n");
    return 0;
}
