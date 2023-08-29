#include <bits/stdc++.h>

int maxUnique(std::string S, std::set<std::string> &st)
{
    int stringmax = 0;
    for (int i = 1; i <= S.length(); i++)
    {
        std::string temp = S.substr(0, i);
        if (st.find(temp) == st.end())
        {
            st.insert(temp);
            stringmax = std::max(stringmax, maxUnique(S.substr(i), st) + 1);
            st.erase(temp);
        }
    }
    return stringmax;
}
int main()
{
    std::set<std::string> st;
    std::string S = "";
    std::cin >> S;
    int res = maxUnique(S, st);
    std::cout << "the maximum number of unique substrings " << res << std::endl;
}