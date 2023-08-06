#include <bits/stdc++.h>

struct node
{
    int data;
    node *left;
    node *right;

    node(int x) : data(x), left(NULL), right(NULL){};
};

class avl
{
public:
    int height(node *t)
    {
        int h = 0;
        if (t)
        {
            int l_height = height(t->left);
            int r_height = height(t->right);
            int max_height = std::max(l_height, r_height);
            h = max_height + 1;
        }
        return h;
    }

    int difference(node *t)
    {
        int l_height = height(t->left);
        int r_height = height(t->right);
        return l_height - r_height;
    }

    node *rotate_ll(node *t)
    {
        node *i = t->left;
        t->left = i->right;
        i->right = t;
        return i;
    }

    node *rotate_rr(node *t)
    {
        node *i = t->right;
        t->right = i->right;
        i->left = t;
        return i;
    }

    node *rotate_lr(node *t)
    {
        node *i = t->left;
        t->left = rotate_rr(i);
        t = rotate_ll(t);
        return t;
    }

    node *rotate_rl(node *t)
    {
        node *i = t->right;
        t->right = rotate_ll(i);
        return rotate_rr(t);
    }

    node *balance(node *t)
    {
        int bal = difference(t);
        if (bal > 1)
        {
            if (difference(t->left) > 0)
                t = rotate_ll(t);
            else
                t = rotate_lr(t);
        }
        else if (bal < -1)
        {
            if (difference(t->right) < 0)
                t = rotate_rr(t);
            else
                t = rotate_rl(t);
        }
        return t;
    }

    node *insert(node *t, int x)
    {
        if (!t)
        {
            node *temp = new node(x);
            return temp;
        }
        else
        {
            if (t->data > x)
            {
                // std::cout << t->data << " " << x << std::endl;
                t->left = insert(t->left, x);
                t = balance(t);
            }
            else
            {
                t->right = insert(t->right, x);
                t = balance(t);
            }
            return t;
        }
    }

    void inorder(node *t)
    {
        if (t == NULL)
            return;
        if (t->left)
            inorder(t->left);
        std::cout << t->data << " ";
        if (t->right)
            inorder(t->right);
    }
};

int main()
{
    int n;
    std::cin >> n;
    avl a;
    node *p = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        p = a.insert(p, x);
    }
    a.inorder(p);
}