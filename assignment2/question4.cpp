#include "avl.h"

int main()
{
    int n;
    std::cin >> n;
    minheap h;
    avl a;
    node *t = NULL;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        t = a.insert(t, x);
    }
    a.inorder(t, t);
    a.show_closest_pair();
    t = a.push(t, 4);
    a.show_closest_pair();
    t = a.pop(t, 4);
    a.show_closest_pair();
}