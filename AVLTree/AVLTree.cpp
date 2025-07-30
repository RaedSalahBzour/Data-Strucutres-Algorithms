#include <iostream>
class Node
{
public:
    Node* left;
    Node* right;
    int value ;
    int height;
    Node() = default;
    Node(int v) : value(v), height(1), left(nullptr), right(nullptr) {}
};
class AVLTree
{
    Node* root;
public:
    AVLTree():root(nullptr){}
    bool isEmpty()
    {
        return root == nullptr;
    }
    int getHeight(Node* node) {
        return node == nullptr ? 0 : node->height;
    }
    
};
int main()
{

    std::cin.get();
}