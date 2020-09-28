#include <iostream>
#include <string>
using namespace std;

#include "algorithms/util.h"
#include "data_structures/array.h"
#include "data_structures/linked_list.h"


int main()
{
    ads::LinkedList<string> names;

    names.prepend("C++");
    names.prepend("Java");
    names.prepend("C#");
    names.prepend("Python");
    names.prepend("C");
    names.prepend("Javascript");

    while (!names.isEmpty())
    {
        cout << names.popFront() << "\n";
    }

    printf("\n\n");
    return 0;
}















