#include <iostream>
#include <vector>
int linearSearch(std::vector<int> arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    std::vector<int> numbers = { 4, 2, 7, 1, 9 };
    int target = 7;

    int index = linearSearch(numbers, target);

    if (index != -1)
        std::cout << "Found at index " << index << std::endl;
    else
        std::cout << "Not found" << std::endl;

    return 0;
}
