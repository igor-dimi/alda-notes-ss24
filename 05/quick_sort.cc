#include <cstdlib>
#include <ctime>
#include <iostream>

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int partition(int* a, int from, int to)
{
    int pivot = a[from];
    int i = from - 1;
    int j = to + 1;
    // invariant: a[f .. i] <= pivot && a[j .. t] >= pivot
    while (i < j) {
        i++; while (a[i] < pivot) i++;
        j--; while (a[j] > pivot) j--;
        if (i < j) swap(a[i], a[j]);
    }
    return j;
}

void quicksort(int* a, int from, int to)
{
    if (from >= to) return;
    int p = partition(a, from, to);
    quicksort(a, from, p);
    quicksort(a, p + 1, to);
}


void print(int* a, int size)
{
    for (int i = 0; i < size; i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    
    // create a input array with 15 random integers
    std::srand(time(0));
    const int SIZE = 15;
    int values[SIZE];
    for (int i = 0; i < SIZE; i++) values[i] = std::rand() % 100;

    print(values, SIZE);
    quicksort(values, 0, SIZE - 1);
    print(values, SIZE);

    return 0;
}
