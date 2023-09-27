#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cout << "Enter number of rows & columns: ";
    std::cin >> n;
    std::vector<int> temp;
    std::vector<std::vector<int>> res(n, std::vector<int>(n));
    std::vector<std::vector<int>> trans(n, std::vector<int>(n));
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j][0] < a[j + 1][0])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            trans[i][j] = a[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (trans[j][0] > trans[j + 1][0])
            {
                temp = trans[j];
                trans[j] = trans[j + 1];
                trans[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = trans[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}