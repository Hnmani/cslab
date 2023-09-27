#include <iostream>
#include <vector>

int unsorted_max_elements(std::vector<int> nums, int w)
{
    int i, count = 0;
    const int limit = 10000;
    std::vector<int> freq(2 * limit + 1, 0);
    for (auto i : nums)
    {
        freq[i + limit]++;
    }
    for (i = -limit; i <= limit; i++)
    {
        if (freq[i + limit] > 0)
        {
            while (freq[i + limit] > 0 && i <= w)
            {
                w -= i;
                freq[i + limit]--;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n, w, val;
    std::vector<int> nums;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        nums.push_back(val);
    }
    std::cout << "Enter the value of w: ";
    std::cin >> w;
    std::cout << "Maximum number of elements of A that can be selected from unsorted array is ";
    std::cout << unsorted_max_elements(nums, w) << std::endl;
    return 0;
}