#include<bits/stdc++.h>
using namespace std;
vector <int> catalan(100000,0);

int c(int n){
    if(catalan[n]) return catalan[n];
    if(n==0){
        return 1;
    }
    else{
        int  x = 0;
        for(int i=0;i<n;i++){
            x += c(i) * c(n-i-1);
        }
        catalan[n] = x;
        return x;
    }
}
int main(){
    catalan[0]=1;
    int n;
    cin >>n;
    cout<< c(n);
}