#include<bits/stdc++.h>
using namespace std;

/*
================================================================================
  EXACT-K SUBARRAY COUNTING — Pattern Notes
================================================================================

  HOW TO IDENTIFY "exact" problems:
    - Question asks: "count subarrays with sum/count EXACTLY equal to k"
    - Examples:
        * Subarrays with sum == goal          (LC 930 — binary_subarray_sum)
        * Subarrays with exactly k odd nums   (LC 1248 — this file)
        * Subarrays with exactly k distinct   (LC 992)

  WHY direct sliding window FAILS for "exact":
    - Sliding window relies on a MONOTONE validity condition
      (e.g., "sum <= k" — adding elements only increases sum,
       removing only decreases). This lets us shrink/expand cleanly.
    - "sum == k" is NOT monotone — adding a 0 keeps it equal,
      adding a 1 breaks it. You can't decide when to shrink vs expand.
    - Trying to count "exact" directly (like the earlier buggy version
      of this file) misses the trailing-neutral-elements case
      (e.g., zeros after reaching k ones, or evens after k odds).

  THE TRICK — reduce EXACT to AT-MOST:
        exactly(k) = atMost(k) - atMost(k - 1)

    Reason: subarrays with sum <= k  minus  subarrays with sum <= k-1
            = subarrays with sum exactly k.

  HOW TO WRITE atMost(k) — Variant A sliding window:
    1. Expand head while window stays valid  (count/sum <= k).
    2. For each tail, once inner loop exits, all subarrays
       [tail..h] for h in [tail..head] are valid
       → add (head - tail + 1) to count.
    3. Shrink tail by one, repeat.

  EDGE CASE:
    - If k < 0, atMost(k) = 0. Needed because atMost(k-1) with k=0
      calls atMost(-1).

  WHEN THIS PATTERN APPLIES:
    - The "thing you count" must be non-negative and monotone under
      adding/removing elements (sum of 0/1, count of odds, count of
      distinct values, etc.).
    - If it's not monotone, use prefix-sum + hashmap instead.
================================================================================
*/

int atMost(vector<int> &arr, int n, int k){
    if(k < 0) return 0;
    int tail = 0;
    int head = -1;
    int oc = 0;      // odd count in window
    int count = 0;
    while(tail < n){
        // expand while odd count stays <= k
        while(head + 1 < n && oc + (arr[head + 1] % 2) <= k){
            head++;
            if(arr[head] % 2 == 1) oc++;
        }
        // [tail..head] valid → all subarrays starting at tail up to head are valid
        count += head - tail + 1;

        // shrink one
        if(head >= tail){
            if(arr[tail] % 2 == 1) oc--;
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
