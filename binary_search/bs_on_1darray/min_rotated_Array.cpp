#include<bits/stdc++.h>
using namespace std;

int check(int mid,vector<int> &arr,int lo){
    if(arr[mid]<arr[0]){
       return 1;
    }
    else{
   return 0;
    }
}

int solve(int n,vector<int> &arr){
    int lo = 0;
    int hi = n-1;
    int ans =-1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid,arr,lo)){
           ans = mid;
           hi = mid-1;

        }
        else{
            lo = mid+1;

        }
    }
    return ans;
}

int main(){
    return 0;
}