#include <iostream>
#include <string>
using namespace std;

#include "algorithms/util.h"
#include "data_structures/array.h"
#include "data_structures/linked_list.h"


int main()
{
    ads::LinkedList<string> names;

    names.prepend("Brainfuck");
    names.prepend("Bongosort");
    names.prepend("Brainfuck");
    names.prepend("Bongosort");
    names.prepend("Brainfuck");
    names.prepend("Bongosort");
    names.prepend("Brainfuck");
    names.prepend("Bongosort");
    names.prepend("Brainfuck");
    names.prepend("Bongosort");

    names.traverse([](const string& s) {
        cout << s << "\n";
    });

    printf("\n\n");
    return 0;
}















