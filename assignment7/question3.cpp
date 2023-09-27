#include <iostream>
#include <vector>

long long int houseRobber(std::vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {

        return valueInHouse[0];
    }
    long long prev[2];
    long long curr[2];
    long long ans1 = 0, ans2 = 0;
    prev[0] = 0;
    prev[1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        curr[0] = std::max(prev[0], prev[1]);
        curr[1] = valueInHouse[i] + prev[0];
        prev[0] = curr[0];
        prev[1] = curr[1];
    }
    ans1 = std::max(curr[0], curr[1]);
    prev[0] = 0;
    prev[1] = 0;
    for (int i = n - 1; i > 0; i--)
    {
        curr[0] = std::max(prev[0], prev[1]);
        curr[1] = valueInHouse[i] + prev[0];
        prev[0] = curr[0];
        prev[1] = curr[1];
    }
    ans2 = std::max(curr[0], curr[1]);
    return std::max(ans1, ans2);
}
int main()
{
    std::vector<int> valueInHouse = {4, 5, 4, 1};
    int res = houseRobber(valueInHouse);
    std::cout << "Max amount of money that can be robbed tonight without without alerting the police: " << res << std::endl;
}