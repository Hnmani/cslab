#include <bits/stdc++.h>

struct node
{
    int data;
    node *left;
    node *right;
    bool lt = false;
    bool rt = false;

public:
    node(int x) : data(x), left(NULL), right(NULL){};
};

class BT
{
    node *top = NULL;

public:
    void insert(node *t)
    {
        if (top)
        {
            node *temp = top;
            while (temp)
            {
                if (temp->data > t->data)
                {
                    if (temp->left)
                        temp = temp->left;
                    else
                    {
                        temp->left = t;
                        break;
                    }
                }
                else
                {
                    if (temp->right)
                        temp = temp->right;
                    else
                    {
                        temp->right = t;
                        break;
                    }
                }
            }
        }
        else
            top = t;
    }
    // void in(node *t, std::vector<int> &preorder, std::vector<int> &inorder, std::vector<int> &postorder)
    // {
    //     if (!t)
    //         return;
    //     preorder.push_back(t->data);
    //     in(t->left, preorder, inorder, postorder);
    //     inorder.push_back(t->data);
    //     in(t->right, preorder, inorder, postorder);
    //     postorder.push_back(t->data);
    // }
    void in(node *t, std::vector<int> &preorder, std::vector<int> &inorder, std::vector<int> &postorder)
    {
        std::stack<node *> s;
        s.push(t);
        }
    void traverse()
    {
        std::vector<int> preorder;
        std::vector<int> inorder;
        std::vector<int> postorder;
        in(top, preorder, inorder, postorder);
        std::cout << "The Preorder Traversal is:" << std::endl;
        for (auto x : preorder)
            std::cout << x << " ";
        std::cout << std::endl;
        std::cout << "The Inorder Traversal is:" << std::endl;
        for (auto x : inorder)
            std::cout << x << " ";
        std::cout << std::endl;
        std::cout << "The Postorder Traversal is:" << std::endl;
        for (auto x : postorder)
            std::cout << x << " ";
        std::cout << std::endl;
    }
};

int main()
{
    BT b;
    node *n = new node(40);
    node *n1 = new node(30);
    node *n2 = new node(60);
    node *n3 = new node(50);
    node *n4 = new node(10);
    b.insert(n);
    b.insert(n1);
    b.insert(n2);
    b.insert(n3);
    b.insert(n4);
    b.traverse();
}