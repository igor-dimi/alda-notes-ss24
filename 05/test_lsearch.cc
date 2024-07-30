#include <cstdlib>
#include <ctime>
#include <iostream>

int linear_search(int* a, int size, int value)
{
    for (int i = 0; i < size; i++)
        if (a[i] == value) return i;
    return -1;
}

int main(int argc, char const *argv[])
{
    std::srand(time(0));
    const int SIZE = 20;
    int values[SIZE];
    for (int i = 0; i < SIZE; i++) {
        values[i] = rand() % 100;
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Enter a number to search for: ";
    int target;
    std::cin >> target;
    int pos = linear_search(values, SIZE, target);
    std::cout << "found " << values[pos] << " in position " << pos << std::endl;
    return 0;
}
