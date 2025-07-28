#include <iostream>
class Stack
{
    int top;
    int size;
    int* arr;
public:
    Stack(int s):top(-1),size(s)
    {
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == size-1;
    }
    void push(int data) 
    {
        if (isFull())
        {
            std::cout << "stack overflow" << std::endl;
            return;
        }
        arr[++top] = data;
    }
    int pop() 
    {
        if(isEmpty())
        {
            std::cout << "stack is empty" << std::endl;
            return -1;
        }
        int poppedValue = arr[top];
        arr[top--] = 0;
        return poppedValue;
    }
    int count()
    {
        return top + 1;
    }
    int peek(int position)
    {
        if (isEmpty())
        {
            std::cout << "stack is empty" << std::endl;
            return -1;
        }
        if (position < 1 || position > top + 1)
        {
            std::cout << "Invalid position" << std::endl;
            return -1;
        }
        return arr[position - 1];
    }
    void change(int position, int data)
    {
        if (isEmpty())
        {
            std::cout << "stack is empty" << std::endl;
            return;
        }
        if (position < 1 || position > top + 1)
        {
            std::cout << "Invalid position" << std::endl;
            return;
        }
        arr[position-1] = data;
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            std::cout << arr[i] << "   ";
        }
        std::cout << std::endl;
    }
    ~Stack()
    {
        delete[] arr;
    }
};
int main()
{
    int size;
    std::cin >> size;
    Stack stack(size);
    stack.push(5);
    stack.push(2);
    stack.push(77);
    stack.push(902);
    stack.pop();
    stack.change(2, -42);
    std::cout << stack.peek(2) << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    stack.display();
    std::cout << "-----------------------------------" << std::endl;
    std::cout<<stack.count()<<std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout<<stack.isEmpty()<<std::endl;
    std::cout<<stack.isFull()<<std::endl;
    std::cin.get();
}
