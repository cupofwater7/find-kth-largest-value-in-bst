#include <iostream>

using namespace std;
 
// This is an input class. Do not edit.
class BST {
public:
    int value;
    BST* left = nullptr;
    BST* right = nullptr;

    BST(int value) { this->value = value; }
};

struct TreeInfo
{
    int numberOfNodesVisited;
    int lastestVisitedNodeValue;
};

void reverseInOrderTraverse(BST* node, int k, TreeInfo& treeinfo);
int findKthLargestValueInBst(BST* tree, int k);

int main()
{
    auto root = new BST(15);
    root->left = new BST(5);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    root->left->left->right = new BST(3);
    root->left->right = new BST(5);
    root->right = new BST(20);
    root->right->left = new BST(17);
    root->right->right = new BST(22);

    int k = 3;

    cout << findKthLargestValueInBst(root, k);
}

int findKthLargestValueInBst(BST* tree, int k) {
    // Write your code here.
    auto treeInfo = TreeInfo{ 0,-1 };
    reverseInOrderTraverse(tree, k, treeInfo);
    return treeInfo.lastestVisitedNodeValue;
}



void reverseInOrderTraverse(BST* node, int k, TreeInfo& treeinfo)
{
    if (node == nullptr || treeinfo.numberOfNodesVisited >= k)return;

    reverseInOrderTraverse(node->right, k, treeinfo);
    if (treeinfo.numberOfNodesVisited < k)
    {
        treeinfo.numberOfNodesVisited++;
        treeinfo.lastestVisitedNodeValue = node->value;
        reverseInOrderTraverse(node->left, k, treeinfo);
    }
}
