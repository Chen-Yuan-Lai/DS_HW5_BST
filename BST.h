#ifndef BST_H
#define BST_H
#include <utility>
using namespace std;
template <class K, class E>
class BST
{
    class TreeNode;

public:
    BST(TreeNode *init = 0) { root = init; }
    ~BST();
    void removeSubtree(TreeNode *Ptr);
    bool IsEmpty() const { return root == 0; }
    void Insert(const pair<K, E> &x);
    pair<K, E> *Get(const K &k);
    int *GetLeftSize(const K &k);

private:
    class TreeNode
    {
    public:
        TreeNode(pair<K, E> x) : data(x), leftChild(0), rightChild(0), leftSize(1){};
        pair<K, E> data;
        TreeNode *leftChild;
        TreeNode *rightChild;
        int leftSize;
    };
    pair<K, E> *Get(TreeNode *p, const K &k);
    TreeNode *root;
};
#endif