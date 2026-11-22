#include<bits/stdc++.h>
using namespace std;

int check(int mid,vector<int> &arr){
    return 0;
}
// RULE: default value of ans depends on what check() checks, not on the problem statement.
// Imagine check() returning 0 for every index (i.e. all-0 pattern, no success found) -
// whatever index correctly represents that situation is your default ans.
// e.g. check = arr[mid]>=target (lower bound)  -> all 0 means everything < target -> default ans = n
//      check = arr[mid]<=target (floor)        -> all 0 means everything > target -> default ans = -1
//      check = arr[mid]>target  (upper bound)  -> all 0 means everything <= target -> default ans = n
int solve(int n,vector<int> &arr){
    int ans=n;//default value when there is no 1 in the array after check conversion
    int lo=0;
    int hi=n-1;
    //as answer can lie on lowa nd high so  = here
    while(lo<=hi){
        int mid= (lo + hi)/2;
        if(check(mid,arr)==1){
            ans=mid;
            hi = mid-1;
        }
        else{
            lo= mid+1;
        }
    }
}
// 0 1 2 3 4 5 6 7 
// 0 0 0 0 1 1 1 1 
int main(){

    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    solve(n,arr);
    
}