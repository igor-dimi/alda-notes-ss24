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
    const int SIZE = 9;
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
    std::cout << "found " << target << " in position " << pos << std::endl;
    return 0;
}
