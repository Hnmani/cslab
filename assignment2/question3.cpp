#include <bits/stdc++.h>
class edge
{
public:
    int node1, node2, weight;
    edge(int n1, int n2, int w)
    {
        node1 = n1;
        node2 = n2;
        weight = w;
    }

    bool operator>(const edge &other) const
    {
        return weight > other.weight;
    }
};

int main()
{
    int n, r, total_cost = 0;
    std::cin >> n >> r;
    std::vector<bool> cool(n + 1, false);
    std::priority_queue<edge, std::vector<edge>, std::greater<edge>> pq;
    for (int i = 0; i < r; i++)
    {
        int n1, n2, w;
        std::cin >> n1 >> n2 >> w;
        edge e1 = edge(n1, n2, w);
        pq.push(e1);
    }
    for (int i = 0; i < r; i++)
    {
        edge t = pq.top();
        if (!cool[t.node1] || !cool[t.node2])
        {
            total_cost += t.weight;
            cool[t.node1] = true;
            cool[t.node2] = true;
        }
        pq.pop();
    }
    std::cout << total_cost;
}