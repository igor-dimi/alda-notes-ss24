#include <cstdlib>
#include <ctime>
#include <iostream>
#include "sort.hh"
#include "search.hh"

void print(int* a, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}


int main(int argc, char const *argv[])
{
    std::srand(time(0));
    const int SIZE = 2;
    int values[SIZE];
    for (int i = 0; i < SIZE; i++) {
        values[i] = rand() % 100;
    }
    print(values, SIZE);
    qSort(values, 0, SIZE - 1);
    print(values, SIZE);
    std::cout << "Enter a number to search for: ";
    int target;
    std::cin >> target;
    int pos = bsearch_it(values, SIZE, target);
    // int pos2 = bsearch_rec(values, SIZE, target);
    if (pos == -1) std::cout << target << " not found" << std::endl;
    else
        std::cout << target << " found in position " << pos << std::endl;
    // if (pos2 == -1) std::cout << target << " not found" << std::endl;
    // else
    //     std::cout << target << " found in position " << pos2 << std::endl;
    
    return 0;
}
