#include <iostream>
#include <queue>
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

    Node* IterativeSearch(int value)
    {
        if (root == nullptr)
        {
            return root;
        }
        Node* temp = root;
        while (temp!=nullptr)
        {
            if (temp->value==value)
            {
                return temp;
            }
            else if (temp->value > value)
            {
                temp = temp->left;
            }
            else //else if (temp->value < value)
            {
                temp = temp->right;
            }
        }
        return nullptr;
    }
    Node* RecursiveSearch(Node*node,int value)
    {

        if (node==nullptr||node->value==value)
        {
            return node;
        }
        else if (node->value > value)
        {
           return RecursiveSearch(node->left,value);
        }
        else
        {
           return  RecursiveSearch(node->right,value);
        }
    }
    int   HeightUsingRecursion(Node* node)
    {
        if (node==nullptr)
        {
            return -1;
        }
        else
        {
            int lHeight = HeightUsingRecursion(node->left);
            int rHeight = HeightUsingRecursion(node->right);

            return std::max(lHeight, rHeight) + 1;
        }
    }
    void  BFSPrint(Node* node)
    {
        //this takes O(node*height)
        //which is not efficient way 
        int height = HeightUsingRecursion(node);
        for (int i{};i <= height;i++)
        {
            PrintGivenLevel(node, i);
        }
    }
    void  PrintGivenLevel(Node* node, int level)
    {
        if (node==nullptr)
        {
            return;
        }
        else if(level==0)
        {
            std::cout << node->value << "  ";
        }
        else
        {
            PrintGivenLevel(node->left, level - 1);
            PrintGivenLevel(node->right, level - 1);
        }
    }
    void  BFSUsingQueue(Node*root)
    {
        //this will take O(n)
        if (!root)
            return;
        std::queue<Node*>queue;
        queue.push(root);
        while (!queue.empty())
        {
            Node* currentNode = queue.front();
            queue.pop();
            std::cout << currentNode->value << "  ";
            if (currentNode->left)
            {
                queue.push(currentNode->left);
            }
            if (currentNode->right)
            {
                queue.push(currentNode->right);
            }
        }
    }
    Node* minNode(Node* node)
    {
        Node* currentNode = node;
        while (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }return currentNode;
    }
    Node* deleteNode(Node* node, int value)
    {
        if (node==nullptr)
        {
            return nullptr;
        }
        else if (value<node->value)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            if (node->left==nullptr)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node* temp = minNode(node->right);
                node->value = temp->value;
                node->right = deleteNode(node->right, temp->value);
            }
        }
        return node;
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
    std::cout << std::endl << "--------------------------------------------------------"<<std::endl;
    Node*node=tree.IterativeSearch(25);
    std::cout << node->value;
    std::cout << std::endl << "--------------------------------------------------------" << std::endl;
    node = tree.RecursiveSearch(tree.root,65);
    std::cout << node->value;
    std::cout << std::endl << "--------------------------------------------------------" << std::endl;
    std::cout << tree.HeightUsingRecursion(tree.root);
    std::cout << std::endl << "--------------------------------------------------------" << std::endl;
    tree.BFSPrint(tree.root);
    std::cout << std::endl << "--------------------------------------------------------" << std::endl;
    tree.BFSUsingQueue(tree.root);
    std::cin.get();
}