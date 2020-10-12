#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "algorithms/util.h"
#include "algorithms/slow_sorting.h"
#include "data_structures/array.h"


int main()
{
    ads::Array<string> n { "fu", "fo", "fi", "fe", "fa"};
    alg::selectionSort(n);

    for (string i: n)
        cout << i << " ";

    printf("\n\n");
    return 0;
}
