#include <iostream>
class Node 
{
public:
    Node* left=nullptr;
    Node* right=nullptr;
    int value=0;
    Node() = default;
    Node(int v) : value(v) {}
};
class BST
{
public:
    Node* root;
    BST():root(nullptr){}
    bool isEmpty()
    {
        return root == nullptr;
    }
    void insertNode(int value)
    {
        Node* node = new Node(value);
        if (root==nullptr)
        {
            root = node;
            return;
        }
        Node* temp = root;
        while (temp != nullptr)
        {
            if (value == temp->value)
            {
                std::cout << "value already exists";
                delete node;
                return;
            }
            if (temp->value > value)
            {
                if (temp->left==nullptr)
                {
                    temp->left = node;
                    break;
                }
                temp = temp->left;
            }
            else if (temp->value < value)
            {
                if (temp->right==nullptr)
                {
                    temp->right = node;
                    break;
                }
                temp = temp->right;
            }
        }
    }
    void DFSPreOrderPrint(Node* node)
    {
        if (node==nullptr)
        {
            return;
        }
        std::cout << node->value << "  ";
        DFSPreOrderPrint(node->left);
        DFSPreOrderPrint(node->right);
    }
    void DFSInOrderPrint(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        DFSInOrderPrint(node->left);
        std::cout << node->value << "  ";
        DFSInOrderPrint(node->right);
    }
    void DFSPostOrderPrint(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        DFSPostOrderPrint(node->left);
        DFSPostOrderPrint(node->right);
        std::cout << node->value << "  ";
    }

};
int main()
{
    BST tree;
    tree.insertNode(30);
    tree.insertNode(18);
    tree.insertNode(45);
    tree.insertNode(10);
    tree.insertNode(25);
    tree.insertNode(65);
    tree.DFSPreOrderPrint(tree.root);
    std::cout << std::endl << "--------------------------------------------------------"<<std::endl;
    tree.DFSInOrderPrint(tree.root);
    std::cout << std::endl << "--------------------------------------------------------"<<std::endl;
    tree.DFSPostOrderPrint(tree.root);
    std::cin.get();
}