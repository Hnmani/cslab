#include <iostream>

int main()
{
    int n, i, subSeqSize = 2, temp = 1, diff;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    n = sizeof(arr) / sizeof(arr[0]);
    bool flag = true; // true means ascending, false means descending
    for (i = 0; i < n - 1; i++)
    {
        diff = arr[i + 1] - arr[i];
        if (flag)
        {
            if (diff > 0)
            {
                temp++;
            }
            else if (diff == 0)
            {
                temp = 1;
            }
            else
            {
                temp++;
                flag = false;
            }
        }
        else
        {
            if (diff < 0)
            {
                temp++;
            }
            else if (diff == 0)
            {
                if (temp > subSeqSize)
                {
                    subSeqSize = temp;
                }
                temp = 1;
                flag = true;
            }
            else
            {
                if (temp > subSeqSize)
                {
                    subSeqSize = temp;
                }
                temp = 2;
                flag = true;
            }
        }
    }
    if (temp > subSeqSize)
    {
        subSeqSize = temp;
    }
    std::cout << "The maximum length of a subsequence of the array is ";
    if (subSeqSize != 2)
        std::cout
            << subSeqSize;
    else
        std::cout << 0;
    std::cout << std::endl;
    return 0;
}