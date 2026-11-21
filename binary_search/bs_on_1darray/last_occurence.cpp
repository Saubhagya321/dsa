#include<bits/stdc++.h>
using namespace std;

int check(int tar,int mid,vector<int> &arr){
    if(arr[mid]>tar){
        return 1;
    }
    else return 0;
}

int solve(int target,vector<int>&arr){
    int n =arr.size();
    int lo =0 ;
    int hi =n-1;
    int ans =n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(target,mid,arr)==1){
             ans = mid;
        hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

     if(ans-1 >= 0 && arr[ans-1] == target) return ans-1;
     return -1;
}

int main(){

}