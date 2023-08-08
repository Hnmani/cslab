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
    a.h.show();
    std::cout << "====" << std::endl;
    t = a.pop(t, 7);
    t = a.pop(t, 2);
    t = a.pop(t, 5);
    t = a.pop(t, 11);
    t = a.pop(t, 13);
    t = a.push(t, 15);
    t = a.push(t, 10);
    a.h.show();
}