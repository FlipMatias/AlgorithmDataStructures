#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "algorithms/util.h"
#include "data_structures/fixed_stack.h"


int main()
{
    ads::FixedStack<int> st;

    for (int i = 0; i < 10; ++i)
        st.push(i);

    printf("Peak: %d\n\n", st.peak());

    while (!st.isEmpty())
        printf("%d\n", st.pop());

    //printf("Peak: %d\n\n", st.peak());

    printf("\n\n");
    return 0;
}
