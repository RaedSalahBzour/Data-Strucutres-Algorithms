#include <iostream>
#include <vector>
void merge(std::vector<int>& leftArray, std::vector<int>& rightArray, std::vector<int>& nums)
{
    int leftSize = nums.size() / 2;
    int rightSize = nums.size() - leftSize;
    int i = 0, l = 0, r = 0;
    while (l < leftSize && r < rightSize)
    {
        if (leftArray[l] < rightArray[r])
        {
            nums[i++] = leftArray[l++];
        }
        else
        {
            nums[i++] = rightArray[r++];
        }
    }
    while (l < leftSize)
    {
        nums[i++] = leftArray[l++];
    }
    while (r < rightSize)
    {
        nums[i++] = rightArray[r++];
    }
}
void mergeSort(std::vector<int>& nums)
{
    int size = nums.size();
    if (size <= 1)return;
    int middle = size / 2;
    std::vector<int>leftArray(middle);
    std::vector<int>rightArray(size - middle);
    int i = 0;
    int j = 0;
    for (;i < size;i++)
    {
        if (i < middle)
        {
            leftArray[i] = nums[i];
        }
        else
        {
            rightArray[j++] = nums[i];
        }
    }
    mergeSort(leftArray);
    mergeSort(rightArray);
    merge(leftArray, rightArray, nums);
}
int main()
{
    std::vector<int>unsorted = { 7, 2, 4, 8, 9, 1, 4, 5 };
    for (int u : unsorted)
    {
        std::cout << u << " ";
    }
    std::cout << std::endl;
    mergeSort(unsorted);
    for (int u : unsorted)
    {
        std::cout << u << " ";
    }
    std::cin.get();
}