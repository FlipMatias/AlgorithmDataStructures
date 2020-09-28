#include <iostream>
#include <string>
using namespace std;

#include "algorithms/util.h"
#include "data_structures/array.h"
#include "data_structures/linked_list.h"



int main()
{
    ads::LinkedList<string> desserts;
    desserts.append("Chocolate Ice Cream");
    desserts.append("Brigadeiro");
    desserts.append("Tiramisu");
    desserts.append("Doce de leite");

    auto d = std::move(desserts);
    d.display();

    desserts.display();

    printf("\n\n");
    return 0;
}















