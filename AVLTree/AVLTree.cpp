#include <iostream>
#include <queue>
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
public:
    Node* root;
    AVLTree():root(nullptr){}
    bool isEmpty()
    {
        return root == nullptr;
    }
    int getHeight(Node* node) {
        return node ? node->height : 0;
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
    Node* balance(Node* node) {
        updateHeight(node);
        int balanceFactor = getBalanceFactor(node);

        // Left heavy
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) < 0)
                node->left = LeftRotate(node->left); // Left-Right Case
            return RightRotate(node);               // Left-Left Case
        }
        // Right heavy
        else if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) > 0)
                node->right = RightRotate(node->right); // Right-Left Case
            return LeftRotate(node);                    // Right-Right Case
        }
        return node;
    }
    Node* InsertNodeRecursively(Node* node,int value)
    {
        if (!node)
            return new Node(value);
        if (value < node->value)
            node->left = InsertNodeRecursively(node->left, value);
        else if (value > node->value)
            node->right = InsertNodeRecursively(node->right, value);
        else
        {
            return node;
        }
        return balance(node);
    }
    //beacue the root is changed
    void Insert(int value) {
        root = InsertNodeRecursively(root, value);
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
        if (node == nullptr)
        {
            return nullptr;
        }
        else if (value < node->value)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
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
        updateHeight(node);
        return balance(node);
    }
    //beacue the root is changed
    void Delete(int value) {
        root = deleteNode(root, value);
    }
    void DFSPreOrderPrint(Node* node)
    {
        if (node == nullptr)
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
    void  BFSUsingQueue(Node* root)
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

};
int main()
{
    AVLTree tree;
    tree.Insert(30);
    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(25);
    tree.Insert(35);
    tree.Insert(50);
    tree.BFSUsingQueue(tree.root);
    std::cout << std::endl << "--------------------------------" << std::endl;
    tree.Delete(20);
    tree.Delete(10);
    tree.Insert(60);
    tree.Insert(68);
    tree.BFSUsingQueue(tree.root);
    std::cin.get();
}