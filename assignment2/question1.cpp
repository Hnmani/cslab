#include <bits/stdc++.h>

void record_path(std::vector<int> &path_vector, int index, std::vector<int> &path_record)
{
    if (index == -1)
        return;
    record_path(path_vector, path_vector[index], path_record);
    path_record.push_back(index + 1);
}

int main()
{
    int n, e;
    std::cin >> n;
    std::cin >> e;
    int arr[n][n];
    int s, d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = -1;

    for (int i = 0; i < e; i++)
    {
        int k, l, w;
        std::cin >> k >> l >> arr[k - 1][l - 1];
    }
    std::cin >> s >> d;
    std::vector<int> dist(n, INT_MAX);
    std::vector<int> parents(n, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[s - 1] = 1;
    pq.push(std::make_pair(1, s - 1));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < n; i++)
        {
            if (arr[u][i] != -1)
            {
                if (dist[u] * arr[u][i] < dist[i])
                {
                    dist[i] = dist[u] * arr[u][i];
                    parents[i] = u;
                    pq.push(std::make_pair(dist[i], i));
                }
            }
        }
    }
    std::vector<int> path;

    // print output
    if (parents[d - 1] != -1)
    {
        std::cout << dist[d - 1] << std::endl;
        record_path(parents, d - 1, path);
        std::cout << "The path with the smallest product of edges will be:";
        for (int i = 0; i < path.size() - 1; i++)
        {
            std::cout << path[i] << " => ";
        }
        std::cout << path[path.size() - 1] << std::endl;
        std::cout << "with the product as :";
        for (int i = 1; i < path.size() - 1; i++)
        {
            int p = path[i - 1] - 1;
            int c = path[i] - 1;
            std::cout << arr[p][c] << " * ";
        }
        std::cout << arr[path[path.size() - 2] - 1][path[path.size() - 1] - 1] << " = " << dist[d - 1] << std::endl;
    }

    else
        std::cout << -1 << std::endl;
}