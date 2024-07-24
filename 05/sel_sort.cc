#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * @param a array
 * @param from the beginning of the range
 * @param to the end of the range
 * @return the position of the smallest element in the range
 * a[from .. to]
 */

int min_position(int* a, int from, int to)
{
    int min_pos = from;
    for (int i = from + 1; i <= to; i++) {
        if (a[i] < a[min_pos]) {min_pos = i;}
    }
    return min_pos;
}

/**
 * Swaps to integers
 */
void swap(int& x, int& y) 
{
    int temp = x;
    x = y;
    y = temp;
}

void selection_sort(int* a, int size)
{
    int next;
    // invariant: sorted(a[0 .. next])
    for (next = 0; next < size - 1; next++) {
        int min_pos = min_position(a, next, size - 1);
        swap(a[next], a[min_pos]);
    }
}

void print(int* a, int size)
{
    for (int i = 0; i < size; i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::srand(time(0));
    // const int SIZE = 200000;
    // int values[SIZE];
    // for (int i = 0; i < SIZE; i++) values[i] = std::rand() % 100;
    // // print(values, SIZE);
    // int now = time(0);
    // int before = time(0);
    // selection_sort(values, SIZE);
    // int after = time(0);
    // // print(values, SIZE);



    // // std::cout << "before: " << before << std::endl;
    // // std::cout << "after: " << after << std::endl;
    // std::cout << "Elapsed time = " << after - before << " seconds" << std::endl;
    
    int size = 30000;
    for (int i = 1; i <= 32; i *= 2) {
        int size2 = size * i;
        int values[size2];
        for (int i = 0; i < size2; i++) values[i] = std::rand() % 100;
        int before = time(0);
        selection_sort(values, size2);
        int after = time(0);
        std::cout << size2 << " " << after - before << std::endl;
    }
    return 0;
}

