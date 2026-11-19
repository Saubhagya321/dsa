#include<bits/stdc++.h>
using namespace std;

int check(int mid,vector<int> &arr,int target){
    if(arr[mid]>target){return 1;}
    else{
         return 0;
    }
}


int solve(int target,vector<int> &arr){
    int n =arr.size();
    int lo = 0;
     int hi =n-1;
     int ans =n;

     while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid,arr,target)){
            ans =mid;
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