#include <iostream>
struct minHeap
{
    int *heapArr;
    int capacity;
    int heap_size;
    minHeap(int cap):capacity(cap), heap_size(0),heapArr(new int [cap]) {}

    void linearSearch(int val)
    {
        for (size_t i = 0; i < heap_size; i++)
        {
            if (heapArr[i] == val)
            {
                std::cout << "value founded";
                return;
            }
        }
        std::cout<<"value was not founded";
    }
    void printHeap()
    {
        for (size_t i = 0; i < heap_size; i++)
        {
            std::cout <<heapArr[i]<< "  ";
        }
    }
    int height()
    {
        return ceil(log2(heap_size + 1)-1);
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return (2 * i) + 1;
    }
    int right(int i)
    {
        return (2 * i) + 2;
    }
    void swap(int& first, int& second)
    {
        int temp = first;
        first = second;
        second = temp;
    }
    void insert(int val)
    {
        if (heap_size == capacity)
        {
            std::cout << "overflow";
            return;
        }
        heap_size++;
        int i = heap_size-1;
        heapArr[i] = val;
        while (i != 0 && parent(i) > heapArr[i])
        {
            swap(heapArr[parent(i)], heapArr[i]);
            i = parent(i);
        }
    }
    int extractMin()
    {
        if(heap_size<0)
        {
            return INT_MAX;
        }
        if (heap_size == 1)
        {
            heap_size--;
            return heapArr[0];
        }
        int root = heapArr[0];
        heapArr[0] = heapArr[heap_size - 1];
        heap_size--;
        minHeapify(0);
        return root;
    }
    void minHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && heapArr[l] < heapArr[smallest])
            smallest = l;
        if (r < heap_size && heapArr[r] < heapArr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(heapArr[i], heapArr[smallest]);
            minHeapify(smallest);
        }
    }
};
int main()
{
    std::cin.get();
}