#include <vector>
#include <string>
#include <stdio.h>
using namespace std;


//example of tail recursion to sum numbers
static long summation(long n)
{
    if (n != 0) {
        return summation(n-1) + n;
        //nothing more here otherwise it woud be descending function
    }

    return n;
}


/*example of head recursive function to
 print elements of vector in inverse way*/
static void inverse(const vector<string>& consoles, size_t index = 0)
{
    if (index < consoles.size()) {
        inverse(consoles, index + 1);
        printf("%s\n", consoles[index].c_str()); //printf after recursive call to assure it's called in return time
    }
}



/*int main()
{
    //tests
    printf("%ld\n\n", summation(5));

    vector<string> consoles { "PS1", "SNES", "Xbox", "Genesis" };
    inverse(consoles);

    return 0;
}*/
