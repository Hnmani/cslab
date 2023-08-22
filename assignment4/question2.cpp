#include <bits/stdc++.h>

int main()
{
    int N, M;
    std::cin >> N >> M;
    int arr[N][M];
    int visit_count[N][M];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            std::cin >> arr[i][j];
            visit_count[i][j] = 0;
        }

    visit_count[0][0] = !arr[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j])
                continue;
            if (j + 1 < M)
                if (!arr[i][j + 1])
                    visit_count[i][j + 1] += visit_count[i][j];
            if (i + 1 < N)
                if (!arr[i + 1][j])
                    visit_count[i + 1][j] += visit_count[i][j];
        }
    }
    std::cout << visit_count[N - 1][M - 1] << std::endl;
}