#include<iostream>
#include<limits.h>
#include<bitset>
#include<cstring>

int main(){
    int n;
    std::cin >> n;
    int arr[n][3];
    for(int i = 0; i<n; i++){
        std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    int src, dest, k;
    std::cin >> src >> dest >> k;
    int dist[k+2][n];
    for(int j = 0; j<k+2; j++) for(int i = 0; i<n; i++) dist[j][i] = INT_MAX;
    for(int i =0 ; i<k+2; i++)dist[i][src] = 0;
    for(int i = 0; i<k+2; i++){
        for(int j = 0; j<n; j++){
            int d = arr[j][1];
            if(d == src) continue;
            if(dist[i][arr[j][0]]==INT_MAX) continue;
            if(dist[i][arr[j][0]] + arr[j][2] < dist[i][d]) dist[i+1][d] = dist[i][arr[j][0]] + arr[j][2]; 
        }
    }
    std::cout<<dist[k+1][dest]<<std::endl;
}