#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subMatrix(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mp.find(sum) != mp.end())
        {
            ans = max(ans, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
        cout << "[";
        for (const auto &kv : mp)
        {
            cout << kv.first << ": " << kv.second << ", ";
        }
        cout << "] " << sum << endl;
    }
    return ans;
}

int largestSubMatrixWithSumZero(vector<vector<int>> &mat, int n, int m)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                temp[k] += mat[j][k];
            }
            cout << "[";
            for (int val : temp)
            {
                cout << val << ", ";
            }
            cout << "]" << endl;
            int len = subMatrix(temp);
            ans = max(ans, (j - i + 1) * len);
            cout << ans << " " << len << endl
                 << endl;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int ans = largestSubMatrixWithSumZero(mat, n, m);
    cout << "Size of sub-matrix is: " << ans << endl;

    return 0;
}
