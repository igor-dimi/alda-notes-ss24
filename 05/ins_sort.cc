#include <cstdlib>
#include <ctime>
#include <iostream>

void ins_sort(int* a, int size)
{
    // invariant: sorted a[0 .. i - 1]
    for (int i = 1; i < size; i++) {
        int next = a[i]; // next element to be inserted
        // move all larger elements up
        int j = i;
        // invariant: moved a[j .. i -1]
        while (j > 0 && a[j - 1] > next) {
            a[j] = a[j - 1];
            j--;
        } // j == 0 || a[j - 1] <= next
        a[j] = next;
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
    for (int i = 1; i <= 8; i *= 2) {
        int size2 = size * i;
        int values[size2];
        for (int i = 0; i < size2; i++) values[i] = std::rand() % 100;
        int before = time(0);
        ins_sort(values, size2);
        int after = time(0);
        std::cout << size2 << " " << after - before << std::endl;
    }
    return 0;
}