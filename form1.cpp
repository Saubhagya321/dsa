#include <bits/stdc++.h>
using namespace std;

int n, w;
vector<pair<int,int>> arr; // {value, weight}
int dp[1010][1010];

int solve(int level, int left){
    // base case
    if(level == n){
        return 0;
    }

    // cache check
    if(dp[level][left] != -1) return dp[level][left];

    int ans = solve(level+1, left);

    // take
    if(left >= arr[level].second){
        ans = max(ans, solve(level+1, left - arr[level].second) + arr[level].first);
    }


    return dp[level][left] = ans;
}


void generate(int level, int left){
    
     if(level == n){
        return;
    }
    int ans = solve(level, left); 
    
    int dontake =solve(level+1, left);// transition posssibility 1
    if(left >= arr[level].second){
        int take = solve(level+1, left - arr[level].second) + arr[level].first; //transiotion psoibility 2
    
    
    //why this works we can say that we decided on each transition and went this transition or other tranistion if this transiton possible then when when 
    //if it is not possible then automatically other comes
    
        // if(dontake > take){
        // cout << "Skip item " << level << "\n";
        //         genrate(level+1,left);
        // }
        // else{
        //             cout << "keeping item " << level << "\n";

        //      genrate(level+1,left- arr[level].second);
        // }
        
        
    }
    // else{
    //     cout << "Skip item " << level << "\n";
    //     genrate(level+1,left);
    // }
    
    //method 2   why this works suppose we are at a node we got it s answer that is forming and got the next two possible answers also of transition possible
    // ok so if dont take it then the value will be same just leel increases sound understandable
    // but for take we can say  with  +value  we took it and with +res of state works
    if(take == ans){
        cout << "Take item " << level << "\n";
        generate(level+1, left - arr[level].second);
    } else {
        cout << "Skip item " << level << "\n";
        generate(level+1, left);
    }
    
}

int main(){
    cin >> n >> w;

    arr.resize(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i].first;   // value
        cin >> arr[i].second;  // weight
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, w) << endl;

    return 0;
}