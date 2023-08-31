#include <bits/stdc++.h>

int solution(std::vector<int> &nums)
{
    int n = nums.size();
    int sm = 0;
    int maxMin = INT_MIN;
    int minMax = INT_MAX;
    int maxINC = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        int diff = abs(nums[i] - nums[i - 1]);
        sm += diff;
        maxMin = std::max(maxMin, std::min(nums[i - 1], nums[i]));
        minMax = std::min(minMax, std::max(nums[i - 1], nums[i]));

        maxINC = std::max(maxINC, abs(nums[0] - nums[i]) - diff);
        maxINC = std::max(maxINC, abs(nums[n - 1] - nums[i - 1]) - diff);
        // std::cout << nums[i] << " " << nums[i - 1] << " " << diff << " " << sm << " " << maxMin << " " << minMax << " " << maxINC << std::endl;
    }
    maxINC = std::max(maxINC, 2 * (maxMin - minMax));
    return sm + maxINC;
}
int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int N;
        std::cin >> N;
        std::vector<int> arr(N);
        int maxScore = 0;
        for (int i = 0; i < N; i++)
            std::cin >> arr[i];
        std::cout << solution(arr) << std::endl;
    }
}