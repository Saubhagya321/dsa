#include<bits/stdc++.h>
using namespace std;

/*
================================================================================
  SUBARRAYS WITH K DIFFERENT INTEGERS  (LC 992)
================================================================================
  Return the number of contiguous subarrays with EXACTLY k distinct integers.

  PATTERN: classic "exact k" → use the atMost trick:
              exactly(k) = atMost(k) - atMost(k - 1)

  atMost(k) = number of subarrays with AT MOST k distinct integers,
  computed by Variant A sliding window:
    - Expand while window keeps <= k distinct.
    - For each tail, add (head - tail + 1) — every subarray starting
      at tail and ending anywhere in [tail..head] is valid.
    - Shrink one, repeat.

  Distinct count tracked via map<int,int> (value → freq in window).
  map.size() = current distinct count.
================================================================================
*/

int atMost(vector<int> &arr, int n, int k){
    if(k < 0) return 0;
    int tail = 0;
    int head = -1;
    map<int,int> mp;
    int count = 0;
    while(tail < n){
        // expand while distinct count stays <= k
        while(head + 1 < n && (mp.size() < (size_t)k || mp.find(arr[head + 1]) != mp.end())){
            head++;
            mp[arr[head]]++;
        }
        // [tail..head] valid → all subarrays starting at tail are valid
        count += head - tail + 1;

        // shrink one
        if(head >= tail){
            mp[arr[tail]]--;
            if(mp[arr[tail]] == 0) mp.erase(arr[tail]);
            tail++;
        }
        else{
            tail++;
            head = tail - 1;
        }
    }
    return count;
}

int solve(vector<int> &arr, int n, int k){
    return atMost(arr, n, k) - atMost(arr, n, k - 1);
}

int main(){
    return 0;
}
