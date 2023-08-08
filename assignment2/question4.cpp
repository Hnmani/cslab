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
    std::cout << "After Inserting all the elements the updated closest pair is ";
    a.show_closest_pair();
    while (true)
    {
        int ch;
        std::cout << "======================" << std::endl;
        std::cout << "Enter Choices" << std::endl;
        std::cout << "======================" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        std::cout << "1 - Insert Element" << std::endl;
        std::cout << "2 - Delete an Element" << std::endl;
        std::cout << "======================" << std::endl;

        std::cin >> ch;
        if (ch == 1)
        {
            std::cout << "Enter the number to Insert" << std::endl;
            int num;
            std::cin >> num;
            t = a.push(t, num);
            std::cout << "The Entered number is " << num << std::endl;
            std::cout << "After Inserting " << num << " the updated closest pair is ";
            a.show_closest_pair();
            std::cout << std::endl;
        }
        else if (ch == 2)
        {
            std::cout << "Enter the number to Delete" << std::endl;
            int num;
            std::cin >> num;
            t = a.pop(t, num);
            std::cout << "The Entered number is " << num << std::endl;
            std::cout << "After Inserting " << num << "the updated closest pair is ";
            a.show_closest_pair();
            std::cout << std::endl;
        }
        else
            break;
    }
}