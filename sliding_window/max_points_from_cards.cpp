#include<bits/stdc++.h>
using namespace std;

/*
================================================================================
  MAX POINTS FROM CARDS (LC 1423)
================================================================================
  Pick EXACTLY k cards from either the front or the back of the row.
  Maximize the sum of picked cards.

  --------------------------------------------------------------------------
  WHY GREEDY ("take the larger end") IS WRONG:
  --------------------------------------------------------------------------
    Counterexample:
       arr = [11, 49, 100, 20, 86, 29, 72],  k = 4
       Greedy picks: 72, 29, 86, 20  → 207
       Optimal:      11 + 49 + 100 (left) + 72 (right) = 232

    Greedy is locally optimal but misses that committing to one side
    can unlock a bigger cluster there.

  --------------------------------------------------------------------------
  CORRECT APPROACH — Sliding Window:
  --------------------------------------------------------------------------
    Observation: any valid pick = (prefix of length i) + (suffix of length k-i)
                 for some 0 <= i <= k.
    Equivalently, we KEEP a contiguous middle window of length (n - k)
    and DROP everything else.
       → answer = totalSum - min(sum of any window of length n-k)

    Edge case: if k == n, we take everything → return totalSum.

    Time  : O(n)
    Space : O(1)
================================================================================
*/

int solve(vector<int> &arr, int n, int k){
    int total = 0;
    for(int x : arr) total += x;

    if(k >= n) return total;

    int windowLen = n - k;
    int windowSum = 0;
    for(int i = 0; i < windowLen; i++) windowSum += arr[i];

    int minWindow = windowSum;
    for(int i = windowLen; i < n; i++){
        windowSum += arr[i] - arr[i - windowLen];
        minWindow = min(minWindow, windowSum);
    }
    return total - minWindow;
}

/*
--------------------------------------------------------------------------
  Alternative form — prefix + suffix (same idea, more direct):
--------------------------------------------------------------------------
    int leftSum = 0, rightSum = 0;
    for(int i = 0; i < k; i++) leftSum += arr[i];
    int best = leftSum;
    int r = n - 1;
    for(int i = k - 1; i >= 0; i--){
        leftSum  -= arr[i];      // drop one from left
        rightSum += arr[r--];    // pick one from right
        best = max(best, leftSum + rightSum);
    }
    return best;
--------------------------------------------------------------------------
*/


/*
--------------------------------------------------------------------------
  WRONG greedy version (kept only as a reference — do NOT use):
--------------------------------------------------------------------------
    int greedyWrong(vector<int> &arr, int n, int k){
        int i = 0, j = n - 1, sum = 0;
        while(i <= j && k > 0){
            if(arr[i] >= arr[j]){ sum += arr[i]; i++; }
            else                { sum += arr[j]; j--; }
            k--;
        }
        return sum;
    }
--------------------------------------------------------------------------
*/

int main(){
    return 0;
}
