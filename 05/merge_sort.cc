#include <cstdlib>
#include <ctime>
#include <iostream>

void merge(int* a, int from, int mid, int to)
{
    int n = to - from + 1; // size of the range to be merged
    // merge two halves into a temporary array b
    int* b = new int[n];
    int i1 = from; // next element to consider in the first half
    int i2 = mid + 1; // next element to consider in the first half
    int j = 0; // next open position in b

    // as long sa neither i1 nor i2 is past the end
    // move the smaller element into b
    while (i1 <= mid && i2 <= to) {
        if (a[i1] < a[i2]) {
            b[j] = a[i1];
            i1++;
        }
        else {
            b[j] = a[i2];
            i2++;
        }
        j++;
    } // i1 > mid || i2 > to

    // copy the remaining entries of the first half
    while (i1 <= mid) {
        b[j] = a[i1];
        i1++;
        j++;
    }
    
    // copy the remaining entries of the second half
    while (i2 <= to) {
        b[j] = a[i2];
        i2++;
        j++;
    }

    // copy back from the temporary array
    // back to a;
    for (j = 0; j < n; j++) a[from + j] = b[j];
    
    delete[] b;
}

void merge_sort(int* a, int from, int to)
{
    if (from == to) return;

    int mid = (from + to) / 2;
    merge_sort(a, from, mid);
    merge_sort(a, mid + 1, to);
    merge(a, from, mid, to);
}


void print(int* a, int size)
{
    for (int i = 0; i < size; i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::srand(time(0));
    const int SIZE = 15;
    int values[SIZE];
    for (int i = 0; i < SIZE; i++) values[i] = std::rand() % 100;
    print(values, SIZE);

    int now = time(0);
    int before = time(0);
    merge_sort(values, 0, SIZE - 1);
    int after = time(0);
    print(values, SIZE);
    std::cout << "Elapsed time = " << after - before << " seconds" << std::endl;

    int size = 20000;
    int rep = 500;
    for (int i = 1; i <= 32; i *= 2) {
        int size2 = size * i;
        int values[size2];
        for (int i = 0; i < size2; i++) values[i] = std::rand() % 100;
        int before = time(0);
        for (int i = 0; i < rep; i++)
            merge_sort(values, 0, size2 - 1);
        int after = time(0);
        double interval = after - before;
        std::cout << size2 << " " << interval / rep << std::endl;
    }




    // std::cout << "before: " << before << std::endl;
    // std::cout << "after: " << after << std::endl;
    return 0;
}
