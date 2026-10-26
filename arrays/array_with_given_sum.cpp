#include <bits/stdc++.h>
using namespace std;


// Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
// Output: 2
// Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

//only for all positives
int solve(vector<int> &arr,int n,int k){
   
    int tail = 0;
    int head = -1;
    int ans=0;
    int sum =0;
    map<int,int> mp;

    while(tail<n){
          while(head+1 <n && sum<= k-arr[head+1]){
            sum+=arr[head+1];
            mp[sum]=tail;
            head++;
          }
          if(mp.find(k)!=mp.end()){
            ans++;
          }

          if(tail<head){
            tail++;
            mp.erase(sum);
            sum-=arr[tail-1];
          }
          else{
              tail++;
              head= tail-1;
          }
    }
     return ans;

}


// WRONG. Gives ans=3 instead of 2 on the sample input (3,1,2,4 / k=6) -- verified by hand trace.
//
// Bug 1: the inner while lost the "sum <= k - arr[head+1]" bound check, so on the
// very first outer iteration head races straight to n-1 in one shot. After that,
// "head+1<n" is false forever, so the inner loop never runs again -- mp is only
// ever populated once, from the very first pass, and is never rebuilt relative
// to later values of tail.
//
// Bug 2: because of Bug 1, mp still contains stale sums computed for a window
// that no longer exists (e.g. mp[6] from tail=0 is still found at tail=1 and
// tail=2, producing phantom matches -- ans gets incremented 3 times for what
// should be 2 real subarrays).
//
// Bug 3 (the real reason this can't be patched to support negatives): the
// mp.find(k - sum) line is trying to reuse the "prefix sum complement" trick
// from subarraySum() below, but that trick only works if you keep EVERY prefix
// sum ever seen. Here mp.erase(sum) actively deletes entries as tail advances,
// throwing away exactly the history the complement check needs. The two-pointer
// shrink/erase approach itself only makes sense when sum grows monotonically
// with head, which requires non-negative elements -- so it can't be extended to
// negatives just by removing the bound check.
//
// Correct approach for arrays with negatives: subarraySum() below (prefix sum +
// hashmap, never erasing entries).
int solvewithneg(vector<int> &arr,int n,int k){

    int tail = 0;
    int head = -1;
    int ans=0;
    int sum =0;
    map<int,int> mp;

    while(tail<n){
          while(head+1 <n ){
            sum+=arr[head+1];
            mp[sum]=tail;
            head++;
          }
          if(mp.find(k)!=mp.end()){
            ans++;
          }
          if(mp.find(k-sum)!=mp.end()){
            ans++;
          }

          if(tail<head){
            tail++;
            mp.erase(sum);
            sum-=arr[tail-1];
          }
          else{
              tail++;
              head= tail-1;
          }
    }
     return ans;

}

int subarraySum(vector<int>& arr, int k) {
        // Size of the array
        int n = arr.size();

        // Map to store frequency of prefix sums
        unordered_map<int, int> prefixSumCount;

        // Initialize prefix sum and count of subarrays
        int prefixSum = 0;
        int count = 0;

        // Base case: prefix sum 0 has occurred once
        prefixSumCount[0] = 1;

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // Add current element to prefix sum
            prefixSum += arr[i];

            // Calculate the prefix sum that needs to be removed
            int remove = prefixSum - k;

            // If this prefix sum has been seen before,
            // add its count to the result
            if (prefixSumCount.find(remove) != prefixSumCount.end()) {
                count += prefixSumCount[remove];
            }

            // Update the frequency of the current prefix sum
            prefixSumCount[prefixSum]++;
        }

        // Return the total count of subarrays
        return count;
    }

int main(){
    return 0;
}