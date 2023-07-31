#include <bits/stdc++.h>
using namespace std;

void display_arr(vector<vector<int>> &arr)
{
    // Fuction to display the matrix
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            t.push_back(x);
        }
        // sorting each row using C++ STL's sort function.
        sort(t.begin(), t.end());
        arr.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> t;
        for (int j = 0; j < n; j++)
        {
            // storing the elements of columns as a vector
            t.push_back(arr[j][i]);
        }
        sort(t.begin(), t.end(), greater<int>());

        // after sorting changing the values accordingly
        for (int j = 0; j < n; j++)
            arr[j][i] = t[j];
    }

    int num;
    cin >> num;
    int i = 0, j = 0;
    bool found = false;

    // search the given num in the sorted matrix
    while (j < n && i < n)
    {
        if (arr[i][j] == num)
        {
            found = true;
            break;
        }
        else
        {
            if (arr[i][j] > num)
            {
                // if arr[i][j] > num try finding element in next row(below);
                i++;
            }
            else
                // otherwise findin it in next column(right);
                j++;
        }
    }
    if (found)
        cout << "found";
    else
        cout << "not found";
    // display_arr(arr);
}