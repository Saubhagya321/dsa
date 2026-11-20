#include<bits/stdc++.h>
using namespace std;
int check_ceil(int mid,vector<int> &arr,int target){
    if(arr[mid]>=target)return 1;
    else return 0;
}

int check_floor(int mid,vector<int> &arr,int target){
    if(arr[mid]<=target)return 1;
    else return 0;
}

int solve(int target,vector<int> &arr){
    int n=arr.size();
    int ans =n;
    int lo =0;
    int hi =n-1;
    while(lo<=hi){
    int mid = (lo + hi)/2;

    if(check_ceil(mid,arr,target)){
        ans = mid;
        hi = mid-1;
    }
    else{
        lo =mid+1;
    }
    }
    return ans;
}

int solve_floor(int target,vector<int> &arr){
    int n=arr.size();
    int ans =-1;
    int lo =0;
    int hi =n-1;
    while(lo<=hi){
    int mid = (lo + hi)/2;

    if(!check_floor(mid,arr,target)){
        ans = mid;
        hi = mid-1;
    }
    else{
        lo =mid+1;
    }
    }
    if(ans ==-1)return ans;
    return ans-1 ;
}
int main(){

}