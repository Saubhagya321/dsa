#include<bits/stdc++.h>
using namespace std;

int largest_subarray_with_sum_0(vector<int> & arr){
   map<int,int> mp;
   int n=arr.size();
   int ans =INT_MIN;
   int sum=0;
   for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum==0){ans = max(ans,i+1);}
    if(mp.find(sum)!=mp.end()){
    ans = max(ans, i-mp[sum]);
   }
  if(mp.find(sum)==mp.end()) mp[sum]=i;   }

   return ans;
   
}

int count_subarray_with_xor0(vector<int> &arr){
      map<int,int> mp;
      int xorr = 0, ans = 0;
      mp[0] = 1;
      for(int x : arr){
          xorr ^= x;
          if(mp.find(xorr) != mp.end()) ans += mp[xorr];
          mp[xorr]++;
      }
      return ans;
  }

int main(){
    return 0;
}