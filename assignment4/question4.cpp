// #include <bits/stdc++.h>

// int main()
// {
//     int n;
//     std::cin >> n;
//     int arr[n];
//     std::vector<int> btm;
//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> arr[i];
//     }
//     btm.push_back(0);
//     for (int i = 1; i < n - 1; i++)
//     {
//         if (arr[i] <= arr[i - 1] && arr[i] <= arr[i + 1])
//         {
//             btm.push_back(i);
//         }
//     }
//     btm.push_back(n - 1);
//     int len = 0;
//     for (int i = 1; i < btm.size(); i++)
//     {
//         if (len < btm[i] - btm[i - 1] + 1)
//             len = btm[i] - btm[i - 1] + 1;
//     }
//     std::cout << len << std::endl;
// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    
    int peak=0, bottom1 = arr[0], bottom2 , mls, pre;
   
    for(int i=0;i <n; i++){
       if(arr[i] == arr[i+1]){
           bottom1 = i+1;
           peak =0;
       } 
       if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
        peak = i;
       }
       if(arr[i] < arr[i+1] && peak){
          bottom2 = i;
          mls = bottom2 - bottom1 + 1;
          bottom1 = i;
          peak = 0;
       }
       
       if( pre < mls) pre= mls;

       if(pre <=2 ){
        return 0;
       }
       
    }
    cout << "The maximum length of a subsequence of the array is "<<  pre << endl;
}