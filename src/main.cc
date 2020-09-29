#include <iostream>
#include <string>
using namespace std;

#include "algorithms/util.h"
#include "data_structures/array.h"
#include "data_structures/linked_list.h"
#include "data_structures/stack.h"


int main()
{
    ads::Stack<string> juices;
    juices.push("Apple");
    juices.push("Orange");
    juices.push("Pineapple");
    juices.push("Lemon");
    juices.push("Mango");

    while (!juices.isEmpty()) {
        auto n = juices.pop();
        cout << n.value() << "\n";
    }

    printf("\n\n");
    return 0;
}















