#include<bits/stdc++.h>
using namespace std;
int check(int mid,vector<int> &arr,int target){
  if(arr[mid] >= target)return 1;
  else return 0;
}
int solve(vector<int>& arr,int target){
    int n=arr.size();
    int lo=0;
    int hi =n-1;
    int ans= n;
    while(lo<=hi){
         int mid = (lo+hi)/2;
        if(check(mid,arr,target) == 1){
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
    vector<int> arr = {1,3,5,7,9};
    int target = 5;
    int ans = solve(arr,target);
    if(ans < (int)arr.size() && arr[ans] == target){
        cout << "Found at index " << ans << endl;
    } else {
        cout << "Not found" << endl;
    }
}