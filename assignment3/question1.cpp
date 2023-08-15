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

public:
    void in(node *t, std::vector<int> &preorder, std::vector<int> &inorder, std::vector<int> &postorder)
    {
        std::stack<node *> s;
        s.push(t);
        while (!s.empty())
        {
            node *temp = s.top();
            if (!(temp->lt))
            {
                if (temp->left)
                {
                    s.push(temp->left);
                }
                temp->lt = true;
                preorder.push_back(temp->data);
            }
            else if (!(temp->rt))
            {
                if (temp->right)
                {
                    s.push(temp->right);
                }
                inorder.push_back(temp->data);
                temp->rt = true;
            }
            else
            {
                s.pop();
                temp->lt = false;
                temp->rt = false;
                postorder.push_back(temp->data);
            }
        }
    }
    void traverse(node *top)
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
    n->left = n1;
    n1->left = n4;
    n->right = n2;
    n2->left = n3;
    b.traverse(n);
}