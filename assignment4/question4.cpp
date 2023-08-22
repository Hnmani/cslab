#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int peak = 0, bottom1 = arr[0], bottom2 = 0, mls = 0, pre = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            bottom1 = i + 1;
            peak = 0;
        }
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            peak = i;
        }
        if (arr[i] < arr[i + 1] && peak)
        {
            bottom2 = i;
            mls = bottom2 - bottom1 + 1;
            bottom1 = i;
            peak = 0;
        }

        if (pre < mls)
            pre = mls;
    }
    if (pre <= 2)
    {
        std::cout << 0 << std::endl;
    }
    else
        std::cout << "The maximum length of a subsequence of the array is " << pre << std::endl;
}