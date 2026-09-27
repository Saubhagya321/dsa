//this is the lis pattern or can say this is the ending at pattern
// we do it like this (level/config , constraint ) -----> return the best of what is asked here ending at this level

#include<bits/stdc++.h>

using namespace std;

int solve(int level){

    //pruning
    if(level<0)return 0;
    //basecase  -- inthis form the base case is not there as if we are ending at the n or 0 it is 0 or the answer
    //cachecheck
    if(dp[level]!=-1)return dp[level];

    //compute/transition
    int ans =1;
    for(int prev =0;prev< level;prev++){
        if(arr[prev]<arr[level])
          ans = max(ans, 1+solve(prev));
    }

    //save and return

    return dp[level] = ans;

}


void generate(int level){
    if(level < 0) return;

    int ans = solve(level);

    for(int prev = 0; prev < level; prev++){
        if(arr[prev] < arr[level]){
            int bans = 1 + solve(prev);

            if(ans == bans){// ok till here we got that the find the best transtion  to take according to dp 
                cout<<arr[level];
                generate(prev);  // ok so when found the correct rtransitonin a way do that and move to the stae where that transition get sus 
                break;//did not ge tit 
            }
        }
    }

}

void getcountlis(int level){
    if(level < 0) return;

    int ans = solve(level);

    if(ans ==1){
        cnt++;
    }

    for(int prev = 0; prev < level; prev++){
        if(arr[prev] < arr[level]){
            int bans = 1 + solve(prev);

            if(ans == bans){// ok till here we got that the find the best transtion  to take according to dp 
                cout<<arr[level];
                getcountlis(prev);  // ok so when found the correct rtransitonin a way do that and move to the stae where that transition get sus 
               
            }
        }
    }

}

int main(){
    cin >> n;

    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    // fill dp
    for(int i = 0; i < n; i++){
        solve(i);
    }

    // find LIS end
    int best = 0, lastIndex = -1;

    for(int i = 0; i < n; i++){
        if(dp[i] > best){
            best = dp[i];
            lastIndex = i;
        }
    }

    generate(lastIndex);
}
