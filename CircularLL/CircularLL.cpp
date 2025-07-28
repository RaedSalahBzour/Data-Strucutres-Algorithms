#include <iostream>
class Node
{
 public:
     int key;
     int data;
     Node* next;
     Node():key(0),data(0),next(nullptr){}
     Node(int k, int d):key(k),data(d),next(nullptr){}
};
class CircularLinkedList
{
 private:
     Node* head;
 public:

     CircularLinkedList():head(nullptr){}
     CircularLinkedList(Node*node):head(node){}
     Node* nodeExisitng(const int k)const
     {
         if (head == nullptr)
             return nullptr;
         Node*currentNode = head;
         do{
             if (currentNode->key == k)
             return currentNode;
             currentNode = currentNode->next;
         } while (currentNode != head);
         return nullptr;
     }
     void appendNode(Node* node)
     {
         if (nodeExisitng(node->key)!=nullptr)
         {
             std::cout << "node are already exist" << std::endl;
             return;
         }
         if (head==nullptr)
         {
             head = node;
             node->next = head;
             return;
         }
         Node* currentNode = head;
         while (currentNode->next!=head)
         {
             currentNode = currentNode->next;
         }
         currentNode->next = node;
         node->next = head;
     }
     void prepend(Node* node)
     {
         if (nodeExisitng(node->key) != nullptr)
         {
             std::cout << "node are already exist" << std::endl;
             return;
         }
         if (head == nullptr)  
         {
             head = node;
             node->next = head;  
             return;
         }
         Node* currentNode = head;
         while (currentNode->next!=head)
         {
             currentNode = currentNode->next;
         }
         currentNode->next = node;
         node->next = head;
         head = node;
             
     }
     void insertNodeAfter(const int k, Node* node)
     {
         if (nodeExisitng(node->key)!=nullptr)
         {
             std::cout << "node already exist" << std::endl;
             return;
         }
         Node* currentNode = head;
         do {
             if (currentNode->key == k)
             {
                 node->next = currentNode->next;
                 currentNode->next = node;
                 return;
             }
             currentNode = currentNode->next;
         } while (currentNode != head);
         std::cout << "No node found with key "
             << k << " to insert after." << std::endl;
     }
     void deleteNodeByKey(const int k)
     {

         if (head==nullptr)
         {
             std::cout << "list is empty";return;
         }
         if (head->key==k)
         {
             Node* temp = head;
             if (head->next == head)
             {
                 delete temp;
                 head = nullptr;
                 return;
             }
             else
             {
                 Node* lastNode = head;
                 while (lastNode->next !=head)
                 {
                     lastNode = lastNode->next;
                 }
                 head = head->next;
                 lastNode->next = head;
                 delete temp;
                 return;
             }
         }
         Node* currentNode = head;
         do
         {
             if (currentNode->next->key==k)
             {
                 Node* temp = currentNode->next;
                 currentNode->next = currentNode->next->next;
                 temp->next = nullptr;
                 delete temp;
                 return;
             }
             currentNode = currentNode->next;
         } while (currentNode != head);
         std::cout << "Node with key " << k << " not found." << std::endl;
     }
     void updateNodeByKey(const int k,int d)
     {
         if (head==nullptr)
         {
             std::cout << "list is empty";return;
         }
         Node* currentNode = head;
         do
         {
             if (currentNode->key==k)
             {
                 currentNode->data = d;
                 return;
             }
             currentNode = currentNode->next;
         } while (currentNode != head);
         std::cout << "Node with key " << k << " not found." << std::endl;
     }
     void printList()
     {
         if (head == nullptr)
         {
             std::cout << "list is empty";
             return;
         }
         Node* currentNode = head;
         do
         {
             std::cout << "key: " << currentNode->key 
                 << " value: " << currentNode->data << std::endl;
             currentNode = currentNode->next;
         } while (currentNode!=head);
     }
     ~CircularLinkedList()
     {
         if (head == nullptr)
             return;
         Node* currentNode = head->next;
         while (currentNode != head)
         {
             Node* temp = currentNode;
             currentNode = currentNode->next;
             delete temp;
         }
         delete head;
         head = nullptr;
     }
};
int main()
{
    Node* n1 = new Node(1, 9);
    Node* n2 = new Node(2, 12);
    Node* n3 = new Node(3, -5);
    Node* n4 = new Node(4, 24);
    Node* n5 = new Node(5, 712);
    CircularLinkedList linkedlist;
    linkedlist.appendNode(n1);
    linkedlist.printList();
    std::cout << "-------------------------------" << std::endl;
    linkedlist.prepend(n2);
    linkedlist.insertNodeAfter(1, n3);
    linkedlist.appendNode(n4);
    linkedlist.updateNodeByKey(4, -19);
    linkedlist.printList();
    std::cout << "-------------------------------" << std::endl;
    linkedlist.appendNode(n5);
    linkedlist.deleteNodeByKey(5);
    linkedlist.deleteNodeByKey(2);
    linkedlist.printList();
    std::cin.get();
}