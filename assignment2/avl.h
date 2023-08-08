#include "minheap.h"
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
    minheap h;

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
        t->right = i->left;
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
            t = temp;
            // return t;
        }
        else
        {
            // std::cout << t->data << " " << x << std::endl;
            if (x < t->data)
            {
                t->left = insert(t->left, x);
                t = balance(t);
            }
            else
            {
                t->right = insert(t->right, x);
                t = balance(t);
            }
            // return t;
        }
        return t;
    }

    void findPreSuc(node *root, node *&pre, node *&suc, int key)
    {
        // Base case
        if (root == NULL)
            return;

        // If key is present at root
        if (root->data == key)
        {
            // the maximum value in left subtree is predecessor
            if (root->left != NULL)
            {
                node *tmp = root->left;
                while (tmp->right)
                    tmp = tmp->right;
                pre = tmp;
            }

            // the minimum value in right subtree is successor
            if (root->right != NULL)
            {
                node *tmp = root->right;
                while (tmp->left)
                    tmp = tmp->left;
                suc = tmp;
            }
            return;
        }

        // If key is smaller than root's key, go to left subtree
        if (root->data > key)
        {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }
        else // go to right subtree
        {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }

    node *findMaxInSubtree(node *node)
    {
        while (node->right != NULL)
        {
            node = node->right;
        }
        return node;
    }

    node *erase(node *t, int x)
    {
        if (!t)
            return t;
        if (x < t->data)
        {
            t->left = erase(t->left, x);
        }
        else if (x > t->data)
        {
            t->right = erase(t->right, x);
        }
        else
        {
            if (!t->left && !t->right)
            {
                delete t;
                return nullptr;
            }
            else if (!t->left)
            {
                node *temp = t->right;
                delete t;
                return temp;
            }
            else if (!t->right)
            {
                node *temp = t->left;
                delete t;
                return temp;
            }
            else
            {
                node *temp = findMaxInSubtree(t->left);
                t->data = temp->data;
                t->left = erase(t->left, temp->data);
            }
        }
        t = balance(t);
        return t;
    }

    void inorder(node *t, node *d)
    {
        if (t == NULL)
            return;
        inorder(t->left, d);
        node *pre = NULL, *suc = NULL;
        findPreSuc(d, pre, suc, t->data);
        if (pre)
        {
            minheap_node *m = new minheap_node(abs(pre->data - t->data), pre->data, t->data);
            h.insert(m);
        }
        inorder(t->right, d);
    }

    void inorder_show(node *t)
    {
        if (t == NULL)
            return;
        inorder_show(t->left);
        std::cout << t->data << " ";
        inorder_show(t->right);
    }

    node *push(node *t, int x)
    {
        t = insert(t, x);
        node *pre = NULL, *suc = NULL;
        findPreSuc(t, pre, suc, x);
        minheap_node *m1 = NULL, *m2 = NULL;
        if (pre)
            m1 = new minheap_node(abs(pre->data - x), pre->data, x);
        if (suc)
            m2 = new minheap_node(abs(suc->data - x), x, suc->data);
        h.delete_from_heap(h.get_node_from_heapMap(pre->data).second);
        if (m1)
            h.insert(m1);
        if (m2)
            h.insert(m2);
        return t;
    }

    node *pop(node *t, int x)
    {
        t = erase(t, x);
        std::pair<int, int> p = h.get_node_from_heapMap(x);
        int n1 = h.get_node(p.first)->node1;
        int n2 = h.get_node(p.second)->node2;
        h.delete_from_heap(p.first);
        p = h.get_node_from_heapMap(x);
        h.delete_from_heap(p.second);
        minheap_node *m1 = new minheap_node(abs(n1 - n2), n1, n2);
        h.insert(m1);
        return t;
    }

    void show_closest_pair()
    {
        minheap_node *m = h.top();
        std::cout << m->diff << " " << m->node1 << " " << m->node2 << std::endl;
    }
};
