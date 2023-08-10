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
    int provinces = 0;
    std::stack<int> s;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            provinces++;
            visited[i] = true;
        }
        for (int j = 0; j < 6; j++)
        {
            if (arr[i][j])
            {
                visited[j] = true;
            }
        }
    }
    std::cout << provinces << std::endl;
}