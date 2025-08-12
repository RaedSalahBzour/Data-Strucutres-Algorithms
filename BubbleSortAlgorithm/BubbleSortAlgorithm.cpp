#include <iostream>
#include <vector>
void bubbleSort(std::vector<int>& nums)
{
    for (int i{};i < nums.size()-1;i++)
    {
        for (int j{};j < nums.size()-i-1;j++)
        {
            if (nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
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
    bubbleSort(unsorted);
    for (int u : unsorted)
    {
        std::cout << u << " ";
    }
    std::cin.get();
}