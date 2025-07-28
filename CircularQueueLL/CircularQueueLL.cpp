#include <iostream>
class Node
{
public :
    int value;
    Node* next;

    Node(int v) :value(v),next(nullptr){}
};

class Queue
{
public:
    Node* front;
    Node* rear;
    Queue():front(nullptr),rear(nullptr){}

    bool isEmpty()
    {
        return front == nullptr;
    }
    void enqueue(int v)
    {
        Node* node = new Node(v);
        if (isEmpty())
        {
            
            front = rear = node;
            rear->next = front;
            return;
        }
        rear->next = node;
        rear = node;
        rear->next = front;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "queue is empty" << std::endl;
            return;
        }
        if (rear == front)
        {
            delete front;
            rear = front = nullptr;
        }
        else
        {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            std::cout << "queue is empty" << std::endl;
            return -1;
        }
        return front->value;
    }
    void display()
    {
        if (isEmpty())
        {
            std::cout<<"queue is empty"<<std::endl;
            return;
        }
        Node* currentNode = front;
        do 
        {
            std::cout << currentNode->value << "  ";
            currentNode = currentNode->next;
        } while (currentNode != front);
        std::cout << std::endl;
    }
};
int main()
{
    Queue queue;
    queue.enqueue(4);
    queue.enqueue(26);
    queue.enqueue(-5);
    queue.display();
    std::cout << "-------------------------" << std::endl;
    std::cout << queue.isEmpty() << std::endl;
    std::cout << queue.peek() << std::endl;
    std::cout << "-------------------------" << std::endl;
    queue.dequeue();
    queue.display();
    std::cin.get();
}
