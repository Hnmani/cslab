#include <bits/stdc++.h>

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
    std::unordered_map<int, std::pair<int, int>> mp;
    int parent_index(int i)
    {
        if (i == 0)
            return -1;
        return i / 2;
    }

    void heapifyUp(int i)
    {
        if (parent_index(i) == -1)
            return;
        if (v[parent_index(i)]->diff > v[i]->diff)
        {
            minheap_node *it = v[parent_index(i)];
            v[parent_index(i)] = v[i];
            v[i] = it;
            mp[v[parent_index(i)]->node1].second = parent_index(i);
            mp[v[parent_index(i)]->node2].first = parent_index(i);
            mp[v[i]->node1].second = i;
            mp[v[i]->node2].first = i;
            heapifyUp(parent_index(i));
        }
    }

    void heapifyDown(int i)
    {
        int l_index = 2 * i;
        int r_index = 2 * i + 1;
        if (l_index < v.size())
        {
            minheap_node *it = v[i];
            int sml_id = i;
            if (it->diff > v[l_index]->diff)
            {
                it = v[l_index];
                sml_id = l_index;
            }
            if (r_index < v.size())
            {
                if (it->diff > v[r_index]->diff)
                {
                    it = v[r_index];
                    sml_id = r_index;
                }
            }
            if (sml_id != i)
            {
                minheap_node *it = v[i];
                v[i] = v[sml_id];
                v[sml_id] = it;
                mp[v[sml_id]->node1].second = sml_id;
                mp[v[sml_id]->node2].first = sml_id;
                mp[v[i]->node1].second = i;
                mp[v[i]->node2].first = i;
                heapifyDown(sml_id);
            }
        }
    }

public:
    minheap_node *top()
    {
        return v[0];
    }
    void show_map(int x)
    {
        minheap_node *m1 = v[mp[x].first];
        minheap_node *m2 = v[mp[x].second];

        std::cout << m1->diff << " " << m1->node1 << " " << m1->node2 << std::endl;
        std::cout << m2->diff << " " << m2->node1 << " " << m2->node2 << std::endl;
    }
    std::pair<int, int> get_node_from_heapMap(int x)
    {
        return mp[x];
    }

    minheap_node *get_node(int i)
    {
        return v[i];
    }
    void pop_top()
    {
        mp[v[0]->node1].second = -1;
        mp[v[0]->node2].first = -1;
        v[0] = v[v.size() - 1];
        mp[v[0]->node1].second = 0;
        mp[v[0]->node2].first = 0;
        v.pop_back();
        heapifyDown(0);
    }
    void show()
    {
        for (auto x : v)
        {
            std::cout << x->diff << " " << x->node1 << " " << x->node2 << std::endl;
        }
    }
    void delete_from_heap(int i)
    {
        v[i]->diff = INT_MIN;
        heapifyUp(i);
        pop_top();
    }
    void insert(minheap_node *n)
    {
        v.push_back(n);
        mp[n->node1].second = v.size() - 1;
        mp[n->node2].first = v.size() - 1;
        heapifyUp(v.size() - 1);
    }
};
