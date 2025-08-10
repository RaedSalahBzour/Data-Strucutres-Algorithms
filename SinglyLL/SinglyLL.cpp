#include <iostream>
class Node
{
public:
    int key;
    int data;
    Node* next;
    Node() :key(0), data(0), next(nullptr) {}
    Node(int _key, int _data) :key(_key), data(_data), next(nullptr) {}
};
class SinglyLinkedList
{
public:
    Node* head;
    SinglyLinkedList() :head(nullptr) {}
    SinglyLinkedList(Node* node) :head(node) {}

    Node* nodeExisting(const int k)const
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->key == k)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    void appendNode(Node* n)
    {
        if (nodeExisting(n->key) != nullptr)
        {
            std::cout << "cannot append existing node";
        }
        else
        {
            if (head == nullptr)
            {
                head = n;
            }
            else
            {
                Node* lastNode = head;
                while (lastNode->next != nullptr)
                {

                    lastNode = lastNode->next;
                }
                lastNode->next = n;
            }
        }

    }
    void prependNode(Node* n)
    {
        if (nodeExisting(n->key) != nullptr)
        {
            std::cout << "cannot prepend exsisting node";
        }
        else
        {
            n->next = head;
            head = n;
        }
    }
    void insertNodeAfter(const int k, Node* n)
    {
        if (nodeExisting(n->key) != nullptr)
        {
            std::cout << "Cannot insert: node with key "
                << n->key << " already exists." << std::endl;
            return;
        }
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            if (currentNode->key == k)
            {
                n->next = currentNode->next;
                currentNode->next = n;
                return;
            }
            currentNode = currentNode->next;
        }
        std::cout << "No node found with key "
            << k << " to insert after." << std::endl;
    }
    void deleteNodeByKey(const int k)
    {
        if (head == nullptr)
        {
            std::cout << "list is empty";
            return;
        }
        if (head->key == k)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* currentNode = head;
        while (currentNode->next != nullptr)
        {
            if (currentNode->next->key == k)
            {
                Node* temp = currentNode->next;
                currentNode->next = currentNode->next->next;
                temp->next = nullptr;
                delete temp;
                return;
            }
            currentNode = currentNode->next;
        }

        std::cout << "Node with key " << k << " not found." << std::endl;

    }
    void updateNodeByKey(const int k, int data)
    {
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            if (currentNode->key == k)
            {
                currentNode->data = data;
                return;
            }
            currentNode = currentNode->next;
        }
        std::cout << "Node with key " << k << " was not found." << std::endl;
    }
    void printList() const
    {
        if (head == nullptr)
        {
            std::cout << "the list is empty" << std::endl;
        }
        else
        {
            std::cout << "values:" << std::endl;
            Node* current = head;
            while (current != nullptr)
            {
                std::cout << "key: " << current->key
                    << "  data: " << current->data << std::endl;
                current = current->next;
            }
        }
    }
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};
class General
{
public:
    General() {}
    Node* reverseLinkedlistIteratively(Node* head)
    {
        Node* savedNext = nullptr;
        Node* currentNode = head;
        Node* previous = nullptr;
        while (currentNode != nullptr)
        {
            savedNext = currentNode->next;
            currentNode->next = previous;
            previous = currentNode;
            currentNode = savedNext;
        }
        head = previous;
        return head;
    }
    Node* reverseLinkedlistRecursively(Node* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        //here the newHead is the last node 
        //and the head is the pre last node
        Node* newHead = reverseLinkedlistRecursively(head->next);
        //making the next of the last node points to the pre last
        head->next->next = head;
        //destroy the link from pre last to last node
        head->next = nullptr;
        return newHead;
    }
};
int main()
{
    SinglyLinkedList list;
    Node* n1 = new Node(1, 6);
    Node* n2 = new Node(2, 2);
    Node* n3 = new Node(3, 19);
    Node* n4 = new Node(4, -5);
    Node* n5 = new Node(5, 44);
    list.appendNode(n1);
    list.appendNode(n2);
    list.insertNodeAfter(1, n3);
    list.updateNodeByKey(3, -19);
    list.prependNode(n4);
    list.appendNode(n5);
    list.printList();
    std::cout << "--------------------------------" << std::endl;
    list.deleteNodeByKey(5);
    list.printList();
    std::cout << "--------------------------------";
    General g;
    list.head = g.reverseLinkedlistIteratively(list.head);
    list.printList();
    std::cin.get();
}