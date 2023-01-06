#include "BST.h"
#include "BST.cpp"
#include <utility>
using namespace std;

int main()
{
    BST<int, int> x;
    pair<int, int> a(30, 1);
    pair<int, int> b(5, 2);
    pair<int, int> c(40, 3);
    pair<int, int> d(2, 4);
    pair<int, int> y[4] = {a, b, c, d};
    for (int i = 0; i < 4; i++)
    {
        x.Insert(y[i]);
    }
    return 0;
}