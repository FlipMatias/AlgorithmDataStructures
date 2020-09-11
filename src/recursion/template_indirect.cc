#include <iostream>


template <typename T>
static void print(const T& args) {
    std::cout << args;
}


template <typename T, typename... Args>
static void print(const T& item, Args&&... args) {
    print(item);
    print(args...);
}


/*int main()
{
    const char* name = "Charles";
    print("My name is ", name, " and i'm ", 33, '\n');

    printf("\n\n");
    return 0;
}*/
