#include <stdio.h>
#include <stdint.h>


template <typename T = uint64_t>
static T factorial(T num)
{
    if (num == 0) return 1;

    if (num > 1) {
        return factorial(num - 1) * num;
    } else {
        return num;
    }
}


//compile-time recursive
template <uint64_t num>
static uint64_t cfactorial()
{
    if constexpr (num == 0) return 1;

    if constexpr (num > 1) {
        return factorial<num - 1>() * num;
    } else {
        return num;
    }
}


/*int main()
{
    for (long i=0; i <= 10; ++i)
        printf("%ld => %ld\n", i, factorial(i));

    printf("\n\nCompile time:\n");
    printf("%d => %ld\n", 0, cfactorial<0>());
    printf("%d => %ld\n", 3, cfactorial<3>());
    printf("%d => %ld\n", 5, cfactorial<5>());

    printf("\n\n");
    return 0;
}*/
