#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

void vecDecode(std::vector<int> &arr, std::unordered_set<std::string> &solutions, int i, std::string currString)
{
    int n = arr.size();
    if (i >= n)
    {
        solutions.insert(currString);
        return;
    }
    if (arr[i] == 0)
        return;
    if (arr[i] == 1 && i < n - 1)
    {
        int num = arr[i] * 10 + arr[i + 1];
        vecDecode(arr, solutions, i + 2, currString + (char)('A' + num - 1));
    }
    if (arr[i] == 2 && i < n - 1 && arr[i + 1] <= 6)
    {
        int num = arr[i] * 10 + arr[i + 1];
        vecDecode(arr, solutions, i + 2, currString + (char)('A' + num - 1));
    }
    vecDecode(arr, solutions, i + 1, currString + (char)('A' + arr[i] - 1));
}

std::vector<int> strToVec(std::string str)
{
    std::vector<int> stv;
    for (char c : str)
    {
        stv.push_back((int)(c - '0'));
    }
    return stv;
}

int main()
{
    std::string input;
    std::cin >> input;
    std::unordered_set<std::string> solutions;
    std::vector<int> arr = strToVec(input);
    vecDecode(arr, solutions, 0, "");
    std::cout << "Total Number of ways to decode = " << solutions.size() << std::endl;
    for (auto s : solutions)
    {
        std::cout << s << std::endl;
    }
}