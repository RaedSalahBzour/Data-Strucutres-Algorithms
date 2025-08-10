#include <iostream>
#include <vector>
int binarySearch(std::vector<int> arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            left = mid + 1; 
        }
        else {
            right = mid - 1; 
        }
    }
    return -1; 
}

int main() {
    std::vector<int> numbers = { 5, 8, 12, 15, 23, 32, 42 };
    int target = 23;

    int index = binarySearch(numbers, target);

    if (index != -1)
        std::cout << "Found at index " << index << std::endl;
    else
        std::cout << "Not found" << std::endl;

    return 0;
}
