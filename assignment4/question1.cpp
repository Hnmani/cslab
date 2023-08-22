#include <bits/stdc++.h>
struct node
{
    node *parent = NULL;
    int level = -1;
    std::vector<node *> adj;
};

int main()
{
    int e;
    int n;
    std::cin >> n;
    std::cin >> e;
    std::vector<node *> arr(n + 1);
    for (int i = 0; i < n; i++)
    {
        node *t = new node();
        arr[i] = t;
    }
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        std::cin >> n1;
        std::cin >> n2;
        n1 = n1 - 1;
        n2 = n2 - 1;
        arr[n1]->adj.push_back(arr[n2]);
        arr[n2]->parent = arr[n1];
    }
    node *root_node;
    for (int i = 0; i < n; i++)
    {
        if (!arr[i]->parent)
            root_node = arr[i];
    }
    int ll = 0;
    std::vector<std::vector<node *>> levels;
    std::vector<node *> t;
    t.push_back(root_node);
    levels.push_back(t);
    std::cout << levels.size();
    while (true)
    {
        std::vector<node *> nl;
        for (int i = 0; i < levels[ll].size(); i++)
        {
            for (int j = 0; j < levels[ll][i]->adj.size(); j++)
            {
                nl.push_back(levels[ll][i]->adj[j]);
            }
        }
        if (nl.size() == 0)
            break;
        levels.push_back(nl);
        ++ll;
    }
    int odd_node = 0, even_node = 0;
    for (int i = 0; i < levels.size(); i++)
    {
        if (i & 1)
        {
            odd_node += levels[i].size();
        }
        else
            even_node += levels[i].size();
    }
    std::cout << (odd_node * even_node) - e << std::endl;
}