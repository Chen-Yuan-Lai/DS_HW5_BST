#include "BST.h"
using namespace std;

template <class K, class E>
void BST<K, E>::removeSubtree(TreeNode *Ptr)
{
    if (Ptr)
    {
        if (Ptr->leftChild)
            removeSubtree(Ptr->leftChild);
        if (Ptr->rightChild)
            removeSubtree(Ptr->rightChild);
        delete Ptr;
    }
}

template <class K, class E>
BST<K, E>::~BST()
{
    removeSubtree(root);
}

template <class K, class E>
void BST<K, E>::Insert(const pair<K, E> &x)
{
    // search for the Pair.first, pp is parent of p
    TreeNode *p = root, *pp = 0;
    while (p)
    {
        pp = p;
        if (x.first < p->data.first)
        {
            p = p->leftChild;
            pp->leftSize++;
        }
        else if (x.first > p->data.first)
        {
            p = p->rightChild;
        }
        else // duplicate, update associated element
        {
            p->data.second = x.second;
            return;
        }
    }
    // perform insertion
    p = new TreeNode(x);
    if (root) // root not empty
    {
        if (x.first < pp->data.first)
            pp->leftChild = p;
        else
            pp->rightChild = p;
    }
    else
        root = p;
}

template <class K, class E> // Driver
pair<K, E> *BST<K, E>::Get(const K &k)
{ // Search the binary search tree(*this) for a pair with key k.
    // If such a pair is found, return a pointer to this pair;otherwise return 0.
    return Get(root, k);
}

template <class K, class E>
pair<K, E> *BST<K, E>::Get(TreeNode *p, const K &k)
{
    if (!p)
        return 0;
    if (k < p->data.first)
        return Get(p->leftChild, k);
    if (k > p->data.first)
        return Get(p->rightChild, k);
    return &p->data;
}
