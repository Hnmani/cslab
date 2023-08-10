#include <bits/stdc++.h>

struct node
{
    int data;
    node *left;
    node *right;

public:
    node(int x) : data(x), left(NULL), right(NULL){};
};

class BT
{
public:
    node *top = NULL;
    int maximum = INT_MIN;
    int height(node *t)
    {
        if (t == NULL)
            return -1;
        else
        {
            int left_height = height(t->left);
            int right_height = height(t->right);
            if (left_height == right_height)
            {
                if (left_height == -1)
                    return 0;
            }
            int height = std::max(left_height, right_height) + 1;
            return height;
        }
    }
    int get_diameter(node *t)
    {
        int hleft = height(t->left);
        int hright = height(t->right);
        return hleft + hright + 2;
    }
    void update_max_diameter(node *t)
    {
        if (t == NULL)
            return;
        update_max_diameter(t->left);
        if (maximum < get_diameter(t))
            maximum = get_diameter(t);
        update_max_diameter(t->right);
    }
    int get_max_diameter()
    {
        // update_max_diameter(top);
        return maximum;
    }
};

int main()
{
    BT b;
    node *n = new node(1);
    node *n1 = new node(2);
    node *n2 = new node(3);
    node *n3 = new node(4);
    node *n4 = new node(5);
    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;
    b.update_max_diameter(n);
    std::cout << b.get_max_diameter() << std::endl;
}