#include <bits/stdc++.h>
int get_min(int a, int b, int c)
{
    if (a < b)
    {
        if (a < c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b < c)
        {
            return b;
        }
        else
            return c;
    }
}
int main()
{
    int n;
    std::cin >> n;
    int cost[3] = {2, 7, 15};
    int costs[367];
    int days[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> days[i];
    }
    int j = 0;
    costs[0] = 0;
    for (int i = 1; i < 367; i++)
    {
        if (j < n && i == days[j])
        {
            j++;
            int cost7 = 0;
            int cost30 = 0;
            if (i - 7 > -1)
                cost7 = costs[i - 7];
            if (i - 30 > -1)
                cost30 = costs[i - 30];

            costs[i] = get_min(costs[i - 1] + cost[0], cost7 + cost[1], cost30 + cost[2]);
        }
        else
        {
            costs[i] = costs[i - 1];
        }
    }
    std::cout << costs[366];
}