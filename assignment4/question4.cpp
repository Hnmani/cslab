#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    std::vector<int> btm;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    btm.push_back(0);
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] <= arr[i - 1] && arr[i] <= arr[i + 1])
        {
            btm.push_back(i);
        }
    }
    btm.push_back(n - 1);
    int len = 0;
    for (int i = 1; i < btm.size(); i++)
    {
        if (len < btm[i] - btm[i - 1] + 1)
            len = btm[i] - btm[i - 1] + 1;
    }
    std::cout << len << std::endl;
}