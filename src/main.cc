#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
#include <map>
using namespace std;

#include "algorithms/util.h"
#include "data_structures/array.h"



int main()
{
    ads::Array<int> arr { 1, 2, 3, 4, 5 };
    arr += ads::Array<int>({6, 7 ,8});
    alg::print(arr);

    printf("\n\n");
    return 0;
}















