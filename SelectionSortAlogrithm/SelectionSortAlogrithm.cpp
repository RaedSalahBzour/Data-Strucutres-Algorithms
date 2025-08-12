#include <iostream>
#include <vector>
void selectionSort(std::vector<int>&nums)
{
    for (int i{};i<nums.size();i++)
    {
        int min = i;
        for (int j = i + 1;j < nums.size();j++)
        {
            if (nums[min] > nums[j])
                min = j;
        }
        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
}
int main()
{
    std::vector<int>unsorted = { 7,2,4,8,4,72,1,4,5 };
    for (int u : unsorted)
    {
        std::cout << u << " ";
    }
    std::cout << std::endl;
    selectionSort(unsorted);
    for (int u : unsorted)
    {
        std::cout << u << " ";
    }
    std::cin.get();
}