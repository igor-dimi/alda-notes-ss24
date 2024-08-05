#include "sort.hh"
#include <vector>

void shell_insert(int* a, int size, int k, int c)
{
    for (int i = k + c; i < size; i += c) {
        int el = a[i];
        // move larger elements up
        int j = i;
        while (j >= c && a[j - c] > el) {
            a[j] = a[j - c];
            j = j - c;
        }
        // insert the element
        a[j] = el;
    }
}

void shell_sort(int* a, int size)
{
    // Generate the sequence values;
    std::vector<int> columns;
    int c = 1;
    while (c < size) {
        columns.push_back(c);
        c = 3 * c + 1;
    }

    // for each column count, sort all columns;
    for (int s = columns.size() - 1; s >= 0; s--) {
        c = columns[s];
        for (int k = 0; k < c; k++) shell_insert(a, size, k, c);
    }
}

