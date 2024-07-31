#include <iostream>
#include <vector>

template <typename T>
int freq(std::vector<T> vec, T val)
{
    int count = 0;
    for (auto el : vec) 
        if (el == val) count++;
    return count;
}

template <typename T>
void print(std::vector<T> vec)
{
    for (auto el : vec) std::cout << el << " ";
    std::cout << std::endl;
}

template <typename T>
T max(std::vector<T> vec)
{
    T max = *vec.begin();
    auto it = ++vec.begin();
    while (it != vec.end()) {
        if (*it > max) max = *it;
        ++it;
    }
    return max;
}

template <typename T>
int max_index(std::vector<T> vec)
{
    int max_index = 0;
    T max = vec[max_index];
    int i = 1;
    while (i < vec.size()) {
        if (vec[i] > max) {
            max_index = i;
            max = vec[max_index];
        }
        i++;
    }
    return max_index;
}

int max_index(int* a, int size)
{
    int max_index = 0;
    int max = a[max_index];
    int i = 1;
    // invariant: a[max_index] == max(a[0..i-1])
    while (i < size) {
        if (a[i] > max) {
            max = a[i];
            max_index = i;
        }
        i++;
    }
    return max_index;
}

int main(int argc, char const *argv[])
{
    std::vector<int> a = {8, 7, 5, 7, 7, 5, 4, 5, 5, 5, 5};
    std::vector<int> counts;
    for (int i = 0; i < a.size(); i++) {
        int count = freq(a, a[i]);
        counts.push_back(count);
    }
    std::cout << freq(a, 8) << std::endl;
    std::cout << freq(a, 7) << std::endl;
    std::cout << freq(a, 3) << std::endl;

    print(a);
    print(counts);

    std::cout << max(a) << std::endl;
    std::cout << max(counts) << std::endl;


    std::cout << max_index(a) << std::endl;
    std::cout << max_index(counts) << std::endl;

    int val = a[max_index(counts)];
    std::cout << "most frequent element in a: " << val << std::endl;

    
    return 0;
}
