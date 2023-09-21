#include <iostream>
#include <algorithm>

int main()
{
    int n;
    int k;
    std::cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    std::sort(arr, arr + n);
    int count = 0;
    int index;
    for (int i = 0; i < n; i++)
    {
        if (count + arr[i] <= k)
            count += arr[i];
        else
        {
            index = i;
            break;
        }
    }
    std::cout << index << std::endl;
}