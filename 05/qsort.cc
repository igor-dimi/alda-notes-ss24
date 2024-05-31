#include <iostream>

void qSort(int* a, int l, int r)
{
    if (r <= l) return;
    int p = a[0]; // first element is pivot
    int i = l;
    int j = r;
    do {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {// partitioning is not complete 
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    // i > j
    qSort(a, l, j);
    qSort(a, i, r);
}

int main(int argc, const char** argv) {
    int a[] = {3, 6, 8, 1, 0, 7, 2, 4, 5, 9};
    for (int i = 0; i < 9; i++)
        std::cout << a[i] << ", "; 
    std::cout << a[9] << std::endl;
    return 0;
}