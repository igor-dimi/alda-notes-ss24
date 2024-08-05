#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

#include "sort.hh"


void random_fill(int* a, int size)
{
    for (int i = 0; i < size; i++) a[i] = std::rand() % 100;
}

void print(int* a, int size)
{
    for (int i = 0; i < size; i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}

const int MAX_SIZE = 50000000;
int values[MAX_SIZE];

int main(int argc, char const *argv[])
{
    srand(time(0));
    int size = 20;
    random_fill(values, size);
    print(values, size);
    shell_sort(values, size);
    print(values, size);

    size = 200000;
    const int ITERATIONS = 1000;
    int before = time(0);
    for (int i = 0; i < ITERATIONS; i++) {
        random_fill(values, size);
        shell_sort(values, size);
    }
    int after = time(0);
    std::cout << "elapsed time wiht shell: " << (after - before) * 1.0 / ITERATIONS
              << " seconds" << std::endl;

    srand(before);
    before = time(0);
    for (int i = 0; i < ITERATIONS; i++) {
        random_fill(values, size);
        std::sort(values, values + size);
    }
    after = time(0);
    std::cout << "elapsed time wiht libsort: " << (after - before) * 1.0 / ITERATIONS
              << " seconds" << std::endl;
    
    random_fill(values, size);
    before = time(0);
    insertion_sort(values, size);
    after = time(0);
    std::cout << "elapsed time wiht insertion sort: " << (after - before) * 1.0 
              << " seconds" << std::endl;

    return 0;
}



