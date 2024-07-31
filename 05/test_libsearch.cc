#include <algorithm>
#include <iostream>
#include <vector>

void print(int* a, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void print(std::vector<T> vec)
{
    for (auto el : vec) std::cout << el << " ";
    std::cout << std::endl;    
}

int main(int argc, char const *argv[])
{
    int a[5] = {60, 47, 70, 39, 6};
    print(a, 5);
    std::sort(a, a + 5);
    print(a, 5);


    std::cout << std::binary_search(a, a + 5, 61) << std::endl;
    std::cout << std::binary_search(a, a + 5, 39) << std::endl;

    std::vector<int> vec = {60, 47, 70, 39, 6};
    print(vec);
    std::sort(vec.begin(), vec.end());
    print(vec);

    std::cout << std::binary_search(vec.begin(), vec.end(), 61) 
        << std::endl;
    std::cout << std::binary_search(vec.begin(), vec.end(), 39)
        << std::endl;
    


    return 0;
}
