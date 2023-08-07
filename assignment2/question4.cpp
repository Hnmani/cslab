#include <bits/stdc++.h>

// struct node
// {
//     int data;
//     node *left;
//     node *right;

//     node(int x) : data(x), left(NULL), right(NULL){};
// };

// class avl
// {
// public:
//     int height(node *t)
//     {
//         int h = 0;
//         if (t)
//         {
//             int l_height = height(t->left);
//             int r_height = height(t->right);
//             int max_height = std::max(l_height, r_height);
//             h = max_height + 1;
//         }
//         return h;
//     }

//     int difference(node *t)
//     {
//         int l_height = height(t->left);
//         int r_height = height(t->right);
//         return l_height - r_height;
//     }

//     node *rotate_ll(node *t)
//     {
//         node *i = t->left;
//         t->left = i->right;
//         i->right = t;
//         return i;
//     }

//     node *rotate_rr(node *t)
//     {
//         node *i = t->right;
//         t->right = i->left;
//         i->left = t;
//         return i;
//     }

//     node *rotate_lr(node *t)
//     {
//         node *i = t->left;
//         t->left = rotate_rr(i);
//         t = rotate_ll(t);
//         return t;
//     }

//     node *rotate_rl(node *t)
//     {
//         node *i = t->right;
//         t->right = rotate_ll(i);
//         return rotate_rr(t);
//     }

//     node *balance(node *t)
//     {
//         int bal = difference(t);
//         if (bal > 1)
//         {
//             if (difference(t->left) > 0)
//                 t = rotate_ll(t);
//             else
//                 t = rotate_lr(t);
//         }
//         else if (bal < -1)
//         {
//             if (difference(t->right) < 0)
//                 t = rotate_rr(t);
//             else
//                 t = rotate_rl(t);
//         }
//         return t;
//     }

//     node *insert(node *t, int x)
//     {
//         if (!t)
//         {
//             node *temp = new node(x);
//             return temp;
//         }
//         else
//         {
//             // std::cout << t->data << " " << x << std::endl;
//             if (x < t->data)
//             {
//                 t->left = insert(t->left, x);
//                 t = balance(t);
//             }
//             else
//             {
//                 t->right = insert(t->right, x);
//                 t = balance(t);
//             }
//             return t;
//         }
//     }

//     node *erase(node *t, int x)
//     {

//         return t;
//     }

//     void inorder(node *t)
//     {
//         if (t == NULL)
//             return;
//         inorder(t->left);
//         std::cout << t->data << " ";
//         inorder(t->right);
//     }
// };

struct minheap_node
{
    int diff;
    int node1;
    int node2;
    minheap_node(int d, int n1, int n2) : diff(d), node1(n1), node2(n2){};
};

class minheap
{
    std::vector<minheap_node *> v;

public:
    int parent_index(int i)
    {
        if (i == 0)
            return -1;
        return i / 2;
    }
    void show()
    {
        for (auto x : v)
        {
            std::cout << x->diff << " " << x->node1 << " " << x->node2 << std::endl;
        }
    }
    void insert(minheap_node *n)
    {
        v.push_back(n);
        heapifyUp(v.size() - 1);
    }
    void heapifyUp(int i)
    {
        if (parent_index(i) == -1)
            return;
        if (v[parent_index(i)]->diff > v[i]->diff)
        {
            auto it = v[parent_index(i)];
            v[parent_index(i)] = v[i];
            v[i] = it;
            heapifyUp(parent_index(i));
        }
    }
    void heapifyDown(int i)
    {
        int l_index = 2 * i;
        int r_index = 2 * i + 1;
        if (l_index > v.size() && r_index > v.size())
        {
            auto it = v[i];
            int sml_id = i;
            if (it->diff > v[l_index]->diff)
            {
                it = v[l_index];
                sml_id = l_index;
            }
            if (it->diff > v[r_index]->diff)
            {
                it = v[r_index];
                sml_id = r_index;
            }
            if (sml_id != i)
            {
                auto it = v[i];
                v[i] = v[sml_id];
                v[sml_id] = it;
                heapifyDown(sml_id);
            }
        }
    }
};

int main()
{
    int n;
    std::cin >> n;
    // avl a;
    // node *p = NULL;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     std::cin >> x;
    //     p = a.insert(p, x);
    // }
    // a.inorder(p);
    // minheap_node *m2 = new minheap_node(2, 2, 5);
    // minheap_node *m1 = new minheap_node(1, 2, 3);
    // minheap_node *m3 = new minheap_node(0, 0, 0);
    minheap h;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        arr[i] = x;
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
    {
        minheap_node *m = new minheap_node(abs(arr[i] - arr[i - 1]), arr[i], arr[i - 1]);
        h.insert(m);
    }
    h.show();

    // std::cout << p->left->right->data;
}