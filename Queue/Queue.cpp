#include <iostream>
class Queue
{
    int front;
    int rear;
    int size;
    int* arr;
public:
    Queue(int s) :front(-1), rear(-1), size(s)
    {
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        return front == -1;  
    }
    bool isFull()
    {
        return front == (rear+1)%size;
    }
    void enqueue(int data)
    {
        if (isFull())
        {
            std::cout << "queue is full";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = data;
        
    }
    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "queue is empty" << std::endl;
            return;
        }
        if (front==rear)
        {
            front = rear = -1;
        }
        else
        {
            front =(front+1)%size;
        }
        
    }
    int count() {
        if (isEmpty()) return 0;
        if (rear >= front)
            return rear - front + 1;
        else
            return size - (front - rear - 1);
    }
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    void display()
    {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        int i = front;
        while (true) {
            std::cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        std::cout << std::endl;
    }
    ~Queue() {
        delete[] arr;
    }
};
int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(4);
    q.enqueue(-6);
    q.display();
    std::cout << "---------------------" << std::endl;
    q.dequeue();
    q.dequeue();
    q.display();
    std::cout << "---------------------" << std::endl;
    std::cout << "Front element: " << q.peek() << std::endl;
    std::cout << "Count: " << q.count() << std::endl;

    std::cin.get();
}