#include "sort.hh"
#include <iostream>


int main(int argc, char const *argv[])
{
    int a[6] = {1, 3, -3, -100, 10, -400};
    // std::cout << find_min_index(a, 1, 6) << std::endl;
    selection_sort(a, 6);
    for (int i = 0; i < 6; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    int b[6] = {1, 3, -3, -100, 10, -400};
    insertion_sort(b, 6);
    for (int i = 0; i < 6; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    return 0;

}
