#include <iostream>
#include <string>
using namespace std;

#include "algorithms/util.h"
#include "data_structures/array.h"
#include "data_structures/linked_list.h"
#include "data_structures/stack.h"
#include "data_structures/queue.h"


int main()
{
    ads::Queue<string> juices;
    juices.enqueue("Apple");
    juices.enqueue("Orange");
    juices.enqueue("Pineapple");
    juices.enqueue("Lemon");
    juices.enqueue("Mango");

    while (!juices.isEmpty()) {
        cout << juices.dequeue() << "\n";
    }

    printf("\n\n");
    return 0;
}















