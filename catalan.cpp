#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> catalan(100000, 0);
// declared global vector catalan
// to store the computed catalan numbers.

unsigned long long c(unsigned long long n)
{
    if (catalan[n])
        return catalan[n];
    // Checks if the catalan number
    // for n is already computed or not
    else
    {
        unsigned long long x = 0;
        for (int i = 0; i < n; i++)
        {
            // running a loop from
            // 0 ... n-1 to calculate values

            x += c(i) * c(n - i - 1);
            // c(n) = c(0)(n-1) + c(1)(n-2) ... + c(n-1)(0) for n > 1;
        }
        catalan[n] = x;
        return x;
    }
}
int main()
{
    catalan[0] = 1;
    // base condition for c(n) where c(0) return 1;
    int n;
    cin >> n;
    cout << c(n);
}