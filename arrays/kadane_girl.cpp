#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr){
     int maxi =INT_MIN;
     int sum =0;
     int n =arr.size();
     for(int i=0;i<n;i++ ){
        sum+=arr[i];
        if(sum > maxi){
            maxi =sum;
        }
        if(sum<0)sum =0;
     }
     return maxi;
}
pair<int,int> range(vector<int> &arr){
     int maxi =INT_MIN;
     int sum =0;
     int n =arr.size();
     int ansstart=-1;
     int ansend = -1;
     int start =0 ;

     for(int i=0;i<n;i++ ){
        sum+=arr[i];
        if(sum > maxi){
            maxi =sum;
        }
        if(sum<0)sum =0;
     }
     return maxi;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {   int a;
        cin>>a;
        arr.push_back(a);
    }
}
