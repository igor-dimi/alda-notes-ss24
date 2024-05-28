#include <iostream>
void print_arr(int* arr, int N)
{
    int i = 0;
    while (i++ < N - 1) {
        std::cout << arr[i] << " ";
    } // i == N - 1
    std::cout << arr[i] << std::endl;
}
void insertion_sort(int* arr, int N)
{
    // i == 1
    // sorted a[0..i-1]
    for (int i = 1; i < N; i++){
        // insert a[i]
        int el = arr[i];
        int j = i - 1;
        while (el < arr[j] && j > 0) {
            arr[j + 1] = arr[j];
            j--;
        } // el >= arr[j] || j == 0
        if (el < arr[j]) { // j == 0
            arr[1] = arr[0];
            arr[0] = el;
        } else  // el >= arr[j]
            arr[j + 1] = el;    
    }
}

int main(int argc, char const *argv[])
{
    int a[10] = {1, -3, 4, 5, -10, 50, 100, 99, -3};
    print_arr(a, 10);
    insertion_sort(a, 10);
    print_arr(a, 10);
    return 0;
}
