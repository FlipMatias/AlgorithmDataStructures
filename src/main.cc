#include <iostream>
#include <string>
using namespace std;

#include "algorithms/util.h"

int main()
{
    cout << alg::max(999, 1);
    string name;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Welcome aboard, " << name << "!\n\n";

    return 0;
}
