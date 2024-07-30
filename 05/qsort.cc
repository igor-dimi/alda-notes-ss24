#include <iostream>
#include "sort.hh"

void qSort(int* a, int l, int r)
{
    if (r <= l) return;
    
    int p = a[l]; //p is first element
    int i = l;
    int j = r;
    do {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        // i < j : partitioning is not yet complete            
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j) ;
    // i > j
    qSort(a, l, j);
    qSort(a, i, r);
}