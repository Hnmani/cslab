#include <bits/stdc++.h>

bool backTrack(std::vector<int> &vec, int p, int n, std::vector<bool> &vis, int sz)
{
    if (p == sz)
    {
        if (count(vec.begin(), vec.end(), 0) == 0)
            return true;
        return false;
    }
    for (int i = n; i >= 1; i--)
    {
        if (i == 1 && vec[p] == 0 && vis[i] == false)
        {
            vis[i] = true;
            vec[p] = i;
            if (backTrack(vec, p + 1, n, vis, sz))
                return true;
            vis[i] = false;
            vec[p] = 0;
        }
        else if (p + i < sz && vec[p] == 0 && vec[p + i] == 0 && vis[i] == false)
        {
            vis[i] = true;
            vec[p] = vec[p + i] = i;
            if (backTrack(vec, p + 1, n, vis, sz))
                return true;
            vis[i] = false;
            vec[p] = vec[p + i] = 0;
        }
    }
    if (count(vec.begin(), vec.end(), 0) == 0)
        return true;
    return backTrack(vec, p + 1, n, vis, sz);
}
std::vector<int> constructDistancedSequence(int n)
{
    int size = 2 * n - 1;
    std::vector<int> vec(size, 0);
    std::vector<bool> vis(n + 1, false);
    bool what = backTrack(vec, 0, n, vis, size);
    int su = vec.size();
    for (int i = 0; i < su; i++)
    {
        std::cout << " " << vec[i];
    }
    std::cout << std::endl;
    return vec;
}

int main()
{

    int n;
    std::cin >> n;
    constructDistancedSequence(n);
    return 0;
}