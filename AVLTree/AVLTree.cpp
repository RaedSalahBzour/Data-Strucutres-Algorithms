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
   
};
int main()
{

    std::cin.get();
}