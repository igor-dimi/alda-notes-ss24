#include "search.hh"

int bsearch_it(int* a, int size, int val)
{
    int lo = 0;
    int hi = size - 1;
    int mid = (lo + hi) / 2;
    // val possibly in a[lo .. hi]
    while (lo < hi && val != a[mid]) {
        if (val > a[mid]) lo = mid + 1;
        else hi = mid - 1;
        mid = (lo + hi) / 2;
    } //lo >= hi || val == a[(lo + hi)/2]
    if (lo > hi) return -1;
    if (val == a[mid]) return mid;
    // if (lo == hi && val == a[lo]) return lo;
    return -1;
} 