#include<iostream>
class Node
{
public:
	int key;
	int data;
	Node* next;
	Node* previous;
	Node() :key(0), data(0), next(nullptr), previous(nullptr) {};
	Node(int k, int d) :key(k), data(d), next(nullptr), previous(nullptr) {};
};
class doublyLinkedList
{
private:
	Node* head;
public:
	doublyLinkedList() :head(nullptr) {};
	doublyLinkedList(Node* node) :head(node) {};
	Node* nodeExisiting(const int k)const
	{
		Node* currentNode = head;
		while (currentNode!= nullptr)
		{
			if (currentNode->key==k)
			{
				return currentNode;
			}
			currentNode = currentNode->next;
		}
		return nullptr;
	}
	void appendNode(Node* node)
	{
		if (nodeExisiting(node->key)!=nullptr)
		{
			std::cout << "node are already exist" << std::endl;
			return;
		}
		if (head==nullptr)
		{
			head = node;
			return;
		}
		Node* currentNode = head;
		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = node;
		node->previous = currentNode;
		node->next = nullptr;
	}
	void prependNode(Node* node)
	{
		if (nodeExisiting(node->key)!=nullptr)
		{
			std::cout << "node are already exist" << std::endl;
			return;
		}
		if (head == nullptr)
		{
			head = node;
			head->next = nullptr;
			head->previous= nullptr;
			return;
		}
		node->next = head;
		node->previous = nullptr;
		head->previous = node;
		head = node;
	}
	void insertNodeAfterKey(const int k, Node* node)
	{
		if (nodeExisiting(node->key)!=nullptr)
		{
			std::cout << "node are already exist" << std::endl;
			return;
		}
		Node* currentNode = head;
		while (currentNode!=nullptr)
		{
			if (currentNode->key==k)
			{
				node->next = currentNode->next;
				node->previous = currentNode;
				currentNode->next = node;
				if (node->next != nullptr)
				{
					node->next->previous = node; 
				}
				return;
			}
			currentNode = currentNode->next;
		}
		std::cout << "No node found with key "
			<< k << " to insert after." << std::endl;
	}
	void deleteNodeByKey(const int k)
	{
		if (head==nullptr)
		{
			std::cout << "list is empty !" << std::endl;
			return;
		}
		Node* currentNode = head;
		while (currentNode!=nullptr)
		{
			if (currentNode->key==k)
			{
				if (currentNode == head)
				{
					head = currentNode->next;
					if (head != nullptr)
						head->previous = nullptr;
					delete currentNode;
					return;
				}
				Node* temp = currentNode;
				currentNode->previous->next = currentNode->next;
				if(currentNode->next!=nullptr)
					currentNode->next->previous = currentNode->previous;
				delete temp;
				return;
			}
			currentNode = currentNode->next;
		}
		std::cout << "No node found with key "
			<< k << " to delete." << std::endl;
	}
	void updateNodeByKey(const int k,int d)
	{
		Node* currentNode = head;
		while (currentNode!=nullptr)
		{
			if (currentNode->key==k)
			{
				currentNode->data = d;
				return;
			}
			currentNode = currentNode->next;
		}
		std::cout << "Node with key " << k << " was not found." << std::endl;
	}
	~doublyLinkedList()
	{
		Node* currentNode = head;
		while (currentNode !=nullptr)
		{
			Node* temp = currentNode;
			currentNode = currentNode->next;
			delete temp;
		}
	}
	void printList()
	{
		if (head==nullptr)
		{
			std::cout << "list is empty";
			return;
		}
		Node* currentNode = head;
		while (currentNode!=nullptr)
		{
			std::cout << "key: " << currentNode->key << " value: " << currentNode->data << std::endl;
			currentNode = currentNode->next;
		}
	}

};
int main()
{
	Node* n1 = new Node(1, 7);
	Node* n2 = new Node(2, 56);
	Node* n3 = new Node(3, 34);
	Node* n4 = new Node(4, -8);
	Node* n5 = new Node(5, 12);
	doublyLinkedList linkedlist;
	linkedlist.appendNode(n1);
	linkedlist.printList();
	std::cout << "-------------------------------" << std::endl;
	linkedlist.prependNode(n2);
	linkedlist.insertNodeAfterKey(1, n3);
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