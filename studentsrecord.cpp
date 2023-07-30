#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, pair<float, string>> &a, pair<string, pair<float, string>> &b)
{
    /*
        This function is used for sorting the data,
        it defines the order in which it has to be sorted;
        first it is compared on the basis of name ( *.second.second)
        then on the basis of cgpa (*.second.first)[only if name are same]
        finally on the basis of roll[only if both name and cgpa are same].
    */
    if (a.second.second < b.second.second)
        return true;
    else if (a.second.second == b.second.second)
    {
        if (a.second.first < b.second.first)
            return true;
        else if (a.second.first == b.second.first)
        {
            if (a.first < b.first)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
    return a.second.second < b.second.second;
}

int main()
{

    ifstream inputFile;
    // inputFile reads from input.txt from which
    // we extract the required data

    inputFile.open("input.txt", ios::in);
    fstream output;
    // output is fstream object which writes the records to output.txt

    output.open("output.txt", ios::out);
    int n;
    inputFile >> n;
    vector<pair<string, pair<float, string>>> data;
    // data is a vector of pair of string and a pair of float and string
    // [<roll,<cgpa,name>>]
    for (int i = 0; i < n; i++)
    {
        string roll;
        float marks;
        string name;
        inputFile >> roll;
        inputFile >> marks;
        getline(inputFile, name);
        pair<float, string> pr;
        pr.first = marks;
        pr.second = name;
        pair<string, pair<float, string>> t;
        t.first = roll;
        t.second = pr;
        data.push_back(t);
    }

    sort(data.begin(), data.end(), cmp);
    // using sort function from STL and cmp function for sorting the data
    for (int i = 0; i < n; i++)
    {
        pair<string, pair<float, string>> t = data[i];
        output << t.second.second << " " << t.second.first << " " << t.first << endl;
    }
}