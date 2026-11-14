#include<bits/stdc++.h>
using namespace std;

/*
================================================================================
  LONGEST SUBSTRING WITH AT MOST K DISTINCT CHARACTERS
================================================================================
  Given string s and integer k, return length of the longest substring
  containing at most k distinct characters.

  PATTERN: "longest window with <= k of something" → direct Variant A
           sliding window. No atMost trick needed (we want MAX length,
           not a COUNT of exact-k subarrays).

  Adaptation from the atMost template:
    - Instead of `count += head - tail + 1`, do
      `ans = max(ans, head - tail + 1)`.
    - Track distinct via a map: size of map = distinct count.
    - Expansion condition: next char already in map (no new distinct),
      OR map.size() < k (room for one more distinct).
================================================================================
*/

int solve(string &s, int n, int k){
    if(k <= 0) return 0;
    int tail = 0;
    int head = -1;
    map<char,int> mp;
    int ans = 0;
    while(tail < n){
        // expand while window has at most k distinct
        while(head + 1 < n && (mp.size() < (size_t)k || mp.find(s[head + 1]) != mp.end())){
            head++;
            mp[s[head]]++;
        }
        // [tail..head] is largest valid window starting at tail
        ans = max(ans, head - tail + 1);

        // shrink one
        if(head >= tail){
            mp[s[tail]]--;
            if(mp[s[tail]] == 0) mp.erase(s[tail]);
            tail++;
        }
        else{
            tail++;
            head = tail - 1;
        }
    }
    return ans;
}

int main(){
    return 0;
}
