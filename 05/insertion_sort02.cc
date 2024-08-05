#include <iostream>

void insertion_sort(int* a, int size)
{
    int i = 1;
    // invariant sorted a[0 .. i - 1]
    while (i < size) {
        // insert i to the correct position in a[0 .. i - 1]
        int j = i; 
        int el = a[j]; // element to be inserted
        // invariant shifted a[j .. i - 1]
        while (j > 0 && a[j - 1] > el) {
            a[j] = a[j - 1];
            j--;
        } // j == 0 || a[j - 1] <= el
        a[j] = el;
        i++;
    } // i == size
}

void print(int* a, int size)
{
    for (int i = 0; i < size; i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    const int size = 5;
    int a[size] = {0, 5, 2, 3, -1};

    print(a, size);
    insertion_sort(a, size);
    print(a, size);

    return 0;
}
