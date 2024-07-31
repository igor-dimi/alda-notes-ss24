#include "search.hh"

int bsearch_rec(int* a, int from, int to, int val)
{
    if (from > to) return -1;
    int mid = (from + to) / 2;
    if (a[mid] == val) return mid;
    if (a[mid] < val) return bsearch_rec(a, mid + 1, to, val);
    return bsearch_rec(a, from, mid - 1, val);
}