#include <stdio.h>
#include <stdint.h>


template <typename T = uint64_t>
static auto sum(T n, T min = 0)
{
    if (n == min) {
        return n;
    } else {
        return sum(n - 1, min) + n;
    }
}


int main()
{
    for (long i = 0; i <= 100; ++i)
        printf("%ld => %ld\n", i, sum(i));

    printf("\n\n");
    return 0;
}
