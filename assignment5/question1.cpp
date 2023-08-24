#include <bits/stdc++.h>

int main()
{
    int N;
    std::cin >> N;
    int arr[N];
    int minimum = arr[0];
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        if (arr[i] < minimum)
            minimum = arr[i];
        if (res < arr[i] - minimum)
        {
            res = arr[i] - minimum;
        }
    }
    std::cout << res << std::endl;
}