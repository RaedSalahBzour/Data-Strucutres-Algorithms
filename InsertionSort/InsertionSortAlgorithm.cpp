#include <iostream>
#include <vector>
void insertionSort(std::vector<int>& nums)
{
    for (int i = 1;i < nums.size();i++)
    {
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > temp)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }
}
int main()
{
    std::vector<int>unsorted = { 7,2,4,8,9,1,4,5 };
    for (int u : unsorted)
    {
        std::cout << u << " ";
    }
    std::cout << std::endl;
    insertionSort(unsorted);
    for (int u : unsorted)
    {
        std::cout << u << " ";
    }
    std::cin.get();
}