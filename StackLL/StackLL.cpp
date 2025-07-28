#include <iostream>
class Node
{
public:
    int value;
    Node* next;
    Node(int v):value(v),next(nullptr){}
};
class Stack
{
    Node* top;
public:
    Stack() : top(nullptr){}

    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(int data)
    {
        Node* node=new Node(data);
        node->next = top;
        top = node;
    }
    void pop() 
    {
        if (isEmpty())
        {
            std::cout << "stack is empty" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete top;
    }
    int peek()
    {
        if (isEmpty())
        {
            std::cout << "stack is empty" << std::endl;
            return -1;
        }
        return top->value;
    }
    void display()
    {
        Node* currentNode = top;
        while (currentNode != nullptr)
        {
            std::cout << currentNode->value << "   ";
            currentNode = currentNode->next;
        }std::cout << std::endl;
    }
    ~Stack()
    {
        Node* currentNode = top;
        while (currentNode!=nullptr)
        {
            Node* temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
    }
};
int main()
{
    Stack stack;
    stack.push(4);
    stack.push(-7);
    stack.push(92);
    stack.display();
    std::cout << "---------------------------------------" << std::endl;
    std::cout << stack.isEmpty() << std::endl; 
    std::cout << stack.peek() << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    stack.pop();
    stack.display();
    std::cin.get();
}
