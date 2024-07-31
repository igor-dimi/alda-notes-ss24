#include <iostream>
#include <algorithm>

void print(int* a, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    
    int a[8] = {8, 7, 5, 8, 6, 5, 5, 9};
    print(a, 8);
    std::sort(a, a + 8);
    print(a, 8);

    int freq[8];
    
    int count = 1;
    int i = 0;
    freq[i] = count;
    while (i < 7) {
        if (a[i] == a[i + 1]) count++;
        else count = 1;
        i++;
        freq[i] = count;
    } // i >= 6;
    
    print(freq, 8);

    // for(int i = 0; i < 8; i++) {
    //     if (i < 7) {
    //         if (freq[i + 1] == 1) {
    //             std::cout << a[i] << ": " << freq[i] << std::endl;
    //         } 
    //         i++;
    //     }
    //     std::cout << a[i] << ": " << freq[i] << std::endl;
    // }
    std::cout << "frequencies: " << std::endl;
    for (int i = 0; i < 7; i++) {
        if (freq[i + 1] == 1)
            std::cout << a[i] << ": " << freq[i] << std::endl;
    }
    std::cout << a[7] << ": " << freq[7] << std::endl;

    return 0;
}
