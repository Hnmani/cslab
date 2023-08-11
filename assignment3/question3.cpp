#include <bits/stdc++.h>
#define N 6
int main()
{
    int arr[N][N] =
        {{1, 1, 0, 1, 0, 0},
         {1, 1, 1, 0, 0, 0},
         {0, 1, 1, 1, 0, 0},
         {1, 0, 1, 1, 0, 0},
         {0, 0, 0, 0, 1, 1},
         {0, 0, 0, 0, 1, 1}};
    std::vector<bool> visited(N, false);
    std::stack<int> s;
    int provinces = 0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            provinces++;
            visited[i] = true;
            s.push(i);
            while (!s.empty())
            {
                int x = s.top();
                // std::cout << x << std::endl;
                s.pop();
                for (int j = 0; j < N; j++)
                {
                    if (arr[x][j] && !visited[j])
                    {
                        visited[j] = true;
                        s.push(j);
                    }
                }
            }
        }
    }
    std::cout << provinces << std::endl;
}