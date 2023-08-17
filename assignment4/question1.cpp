#include <bits/stdc++.h>
struct node
{
    node *parent = NULL;
    std::vector<node *> adj;
};

int main()
{
    int e;
    int n;
    std::cin >> n;
    std::cin >> e;
    std::vector<node *> arr(n);
    for (int i = 0; i < n; i++)
    {
        node *t = new node();
        arr[i] = t;
    }
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        std::cin >> n1, n2;
        arr[n1]->adj.push_back(arr[n2]);
        arr[n2]->parent = arr[n1];
    }
    node *root_node;
    for (int i = 0; i <)
}