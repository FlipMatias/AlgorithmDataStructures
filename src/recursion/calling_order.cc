#include <stdio.h>


static void fun(int n)
{
    if (n > 0) {
        printf("fun called [%d]\n", n);
        fun(n - 1);
        printf("fun uncalled [%d]\n", n);
    }
}


/*int main()
{
    fun(5);

    return 0;
}*/
