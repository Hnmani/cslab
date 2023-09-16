#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool backtrack(std::vector<int> &nums, std::vector<std::vector<int>> &subsets, std::unordered_map<int, int> &count, int targetSum, int K, int currentSum, int startIndex)
{
    if (K == 0)
    {
        return true;
    }

    if (currentSum == targetSum)
    {
        return backtrack(nums, subsets, count, targetSum, K - 1, 0, 0);
    }

    for (int i = startIndex; i < nums.size(); i++)
    {
        if (count[nums[i]] > 0 && currentSum + nums[i] <= targetSum)
        {
            count[nums[i]]--;
            subsets[K - 1].push_back(nums[i]);

            if (backtrack(nums, subsets, count, targetSum, K, currentSum + nums[i], i + 1))
            {
                return true;
            }

            count[nums[i]]++;
            subsets[K - 1].pop_back();
        }
    }

    return false;
}

std::vector<std::vector<int>> canPartitionKSubsets(std::vector<int> &nums, int K)
{
    int totalSum = 0;
    for (int num : nums)
    {
        totalSum += num;
    }

    if (totalSum % K != 0)
    {
        return {};
    }

    int targetSum = totalSum / K;
    std::unordered_map<int, int> count;
    std::vector<std::vector<int>> subsets(K, std::vector<int>());

    for (int num : nums)
    {
        count[num]++;
    }

    bool canPartition = backtrack(nums, subsets, count, targetSum, K, 0, 0);

    return canPartition ? subsets : std::vector<std::vector<int>>();
}

int main()
{
    int n, a;
    std::cin >> n;

    std::vector<int> nums;
    int K = 4;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        nums.push_back(a);
    }

    std::vector<std::vector<int>> result = canPartitionKSubsets(nums, K);

    if (result.empty())
    {
        std::cout << "It is not possible to divide the array into " << K << " subsets with the same sum." << std::endl;
    }
    else
    {
        std::cout << "Possible subsets with the same sum:" << std::endl;
        for (const std::vector<int> &subset : result)
        {
            for (int num : subset)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}