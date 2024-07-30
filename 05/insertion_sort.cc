#include "sort.hh"

void insertion_sort(int* a, int N)
{
    int i = 1;
    // invariant: sorted(a[0 .. i - 1])
    while (i < N) {
        int e = a[i];
        int j = i;
        if (e < a[0]) { // insert e to first position
            // invariant: shifted a[j..i-1] to a[j+1..i]
            while (j > 0) {
                a[j] = a[j - 1];
                j--;
            } // j == 0
            a[j] = e;
        }
        else { // insert e to appropriate position
            while (a[j - 1] > e) {
                a[j] = a[j - 1];
                j--;
            } //a[j - 1] <= e
            a[j] = e;
        }
        i++;
    } // i == N
}