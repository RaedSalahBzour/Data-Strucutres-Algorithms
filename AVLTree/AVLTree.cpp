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
    void updateHeight(Node* node) {
        if (node)
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
    int getBalanceFactor(Node* node) {
        return node == nullptr ? 0 : getHeight(node->left) - getHeight(node->right);
    }
    Node* RightRotate(Node* unbalancedNode)
    {
        Node* newRoot = unbalancedNode->left;
        Node* movedSubtree = newRoot->right;

        newRoot->right = unbalancedNode;
        unbalancedNode->left = movedSubtree;
        updateHeight(unbalancedNode);
        updateHeight(newRoot);
        return newRoot;
    }
    Node* LeftRotate(Node* unbalancedNode)
    {
        Node* newRoot = unbalancedNode->right;
        Node* movedSubtree = newRoot->left;
        newRoot->left= unbalancedNode;
        unbalancedNode->right = movedSubtree;
        updateHeight(unbalancedNode);
        updateHeight(newRoot);
        return newRoot;
    }
    
};
int main()
{

    std::cin.get();
}