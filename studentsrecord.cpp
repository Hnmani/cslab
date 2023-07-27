#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string,pair<float,string>>&a, pair<string,pair<float,string>> &b){
    if(a.second.second<b.second.second) return true;
    else if(a.second.second == b.second.second){
        if(a.second.first<b.second.first) return true;
        else if(a.second.first == b.second.first){
            if(a.first<b.first) return true;
            else return false;
        }else return false;
    }else return false;
    return a.second.second < b.second.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<string, pair<float,string>>> data;
    for(int i =0 ; i<n; i++){
        string roll;
        float marks;
        string mk;
        string name;
        getline(cin, roll,' ');
        getline(cin, mk, ' ');
        getline(cin, name);
        marks = stof(mk);
        pair<float,string> pr;
        pr.first = marks;
        pr.second = name;
        pair<string,pair<float,string>> t;
        t.first = roll;
        t.second = pr;
        data.push_back(t);
    }
    
    sort(data.begin(),data.end(),cmp);
    for(int i =0; i<n;i++){
        pair<string,pair<float,string>> t = data[i];
        cout<<t.second.second<<" "<<t.second.first<<" "<<t.first<<endl;
    }
    
}