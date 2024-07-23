#include <iostream>
#include "sort.hh"

// helper function to find the index of the minimum element in an array a
int find_min_index(int* a, int i, int N) 
{
    int j = i;
    int min = a[i];
    int min_index = j;
    // invariant: min == min(a[i..j]) && min == a[min_index]
    while(j < N - 1) {
        if (a[j + 1] < min) {
            min = a[j + 1];
            min_index = j + 1;
        }
        j++;
    } // j == N
    return min_index;
}

void selection_sort(int* a, int N)
{
    int i = 0;
    // sorted a[0 .. i - 1] && a[0 .. i - 1] <= a[i .. N]
    while (i < N) {
        int j = find_min_index(a, i, N);
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
    } // i == N
}