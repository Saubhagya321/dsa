#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& mat){
    int n =mat.size();
    int m = mat[0].size();

    int frow=1;
    int fcol=1;
    for (int i = 0; i < n; i++)
    {
        if(mat[i][0] == 0){
            frow=0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(mat[0][i] == 0){
            fcol=0;
        }
    }

    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j] == 0){
                mat[0][j]=0;
                mat[i][0] = 0;
            }   
        }
    }

    for(int i =0 ;i<n;i++){
        if(mat[i][0]==0){
            for(int j=0;j<m;j++){
                mat[i][j]=0;
            }
        }
    }
    for(int j=0;j<m;j++){
         if(mat[0][j]==0){
            for(int i=0;i<n;i++){
                mat[i][j]=0;
            }
        }
    }
   if(fcol == 0)
    for(int i=0;i<n;i++){
        mat[i][0]=0;
    }

    if(frow == 0)
    for(int j=0;j<m;j++){
        mat[0][j]=0;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            cin>>mat[i][j];
        }
    }

    solve(mat);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;

}