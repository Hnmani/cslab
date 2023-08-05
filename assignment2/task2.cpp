#include <bits/stdc++.h>

int main()
{
    int arr[10][10];
    int c[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            std::cin >> arr[i][j];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 10; k++)
            {
                c[i][j] += arr[i][k] * arr[k][j];
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            std::cout << c[i][j] << " ";
        std::cout << std::endl;
    }
}