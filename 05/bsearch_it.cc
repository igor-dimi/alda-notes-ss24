#include "search.hh"

int bsearch_it(int* a, int size, int val)
{
    int lo = 0;
    int hi = size - 1;
    // val possibly in a[lo .. hi]
    while (lo != hi) {
        if (val == a[(lo + hi)/2]) return (lo + hi) / 2;
        if (val > a[(lo + hi)/2]) lo = (lo + hi)/2 + 1;
        else hi = (lo + hi)/2 - 1;
    } //lo == hi
    if (val == a[lo]) return lo;
    return -1;
}