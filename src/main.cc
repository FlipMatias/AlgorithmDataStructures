#include <iostream>
#include <string>
using namespace std;

#include "algorithms/util.h"
#include "data_structures/array.h"
#include "data_structures/linked_list.h"


int main()
{
    ads::LinkedList<string> names;

    names.append("C++");
    names.append("Java");
    names.append("C#");
    names.append("Python");
    names.append("C");
    names.append("Javascript");

    while (!names.isEmpty())
    {
        cout << names.popBack() << "\n";
    }

    printf("\n\n");
    return 0;
}















