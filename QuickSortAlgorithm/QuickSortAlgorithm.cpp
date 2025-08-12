#include <iostream>
#include <vector>
int partition(std::vector<int>& nums, int start, int end)
{
    int pivot = nums[end],i= start - 1;
    for (int j = start;j <= end - 1;j++)
    {
        if (nums[j] < pivot)
        {
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    i++;
    int temp = nums[i];
    nums[i] = nums[end];
    nums[end] = temp;
    return i;
}
void quickSort(std::vector<int>&nums, int start, int end)
{
    if (end <= start)return;
    int pivot = partition(nums, start, end);
    quickSort(nums, start, pivot - 1);
    quickSort(nums, pivot + 1, end);
}
int main()
{
    std::vector<int>unsorted = { 7,2,4,8,9,1,4,5 };
    for (int u : unsorted)
    {
        std::cout << u << " ";
    }
    std::cout << std::endl;
    quickSort(unsorted,0,7);
    for (int u : unsorted)
    {
        std::cout << u << " ";
    }
    std::cin.get();
}