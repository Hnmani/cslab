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

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         std::cout << arr[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    std::cin >> s >> d;
    std::vector<int> dist(n, INT_MAX);
    std::vector<int> frm(n, -1);
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
                    frm[i] = u;
                    pq.push(std::make_pair(dist[i], i));
                }
            }
        }
    }
    std::vector<int> path;
    if (frm[d - 1] != -1)
    {
        std::cout << dist[d - 1] << std::endl;
        record_path(frm, d - 1, path);
        for (auto x : path)
        {
            std::cout << x << " ";
        }
        for (auto x : path)
        {
            std::cout << x << " ";
        }
        // std::cout << s1.first << d << std::endl;
        // std::cout << s1.second << std::endl;
    }

    else
        std::cout << -1;
}