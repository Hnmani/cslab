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
    a.h.show();
    std::cout << "====" << std::endl;
    t = a.pop(t, 2);
    a.h.show();
}