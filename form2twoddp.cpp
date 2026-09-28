#include<bits/stdc++.h>

vector<vector<int>> dp;

int rec(int r,int c)
{  
    //this way we define it as the number of ways to reach(r,c) from (0,0)
    //we are going via form 2 ande it says for transition go to all previous states possible and do the compute if required
    if(r<0 || c<0 || r>n-1 || c>n-1)return 0;
    if(r == 0 && c==0)return 1;

    if(dp[r][c] != -1) return dp[r][c];

    int ans =rec(r-1,c) + rec(r,c-1);
    
    return dp[r][c] = ans;
}

int recmaxpathsum(int r,int c,vector<vector<int>> &mat){

    //defining it as the maximum sum possible to get ending at (r,c) when moving from (0,0)
    if (r < 0 || c < 0) return -1e9; // invalid
    if(r == 0 && c==0)return mat[r][c];
  
    if(dp[r][c] != -1) return dp[r][c];
    
    int ans = recmaxpathsum(r-1,c,mat) + mat[r][c];
    ans = max(recmaxpathsum(r,c-1,mat)+mat[r][c], ans);

    return dp[r][c] = ans;
}

void generaterecmaxpathsum(int r,int c,vector<vector<int>> &mat){

        if(r == 0 && c==0)return ;

        int solve = recmaxpathsum(r,c,mat);
         
        int ans = recmaxpathsum(r-1,c,mat) + mat[r][c];

        int right = recmaxpathsum(r,c-1,mat)+mat[r][c];
        

        if(ans > right){
            cout<<"we nare going up from here but it is down in realoit when we go from the (1,1
            to (r,c)";
            generaterecmaxpathsum(r-1,c);
        }
        else{
                cout<<"we nare going right from here but it is left in realoit when we go from the (1,1
            to (r,c)";
            generaterecmaxpathsum(r,c-1);
        }

}