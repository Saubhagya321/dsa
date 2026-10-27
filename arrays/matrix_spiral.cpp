#include<bits/stdc++.h>
using namespace std;

// FIX 1: lt/bottom/top/rt were globals initialized from `n` before `n` was ever
// set (n=0 at that point), so bottom/rt started at -1. Made them locals inside
// solve(), computed from the actual matrix size once mat is known.
// FIX 2: rt (right boundary) must come from the column count, not row count --
// using n-1 for both broke non-square matrices.
// FIX 3: return type was `int` but the function builds a `vector<int>` -- changed
// to `vector<int>`.
// FIX 4: loop condition was `lt<rt && bottom<top`, which is backwards (bottom
// starts below top, and true condition should keep going while boundaries
// haven't crossed) -- changed to `top<=bottom && lt<=rt`.
// FIX 5: the last two inner loops (bottom row, left column) ran unconditionally
// even after the boundaries crossed mid-iteration (e.g. single row/column
// matrices), which re-visits/duplicates cells -- added guards before each.
// FIX 6: `lt--` at the end moved the left boundary the wrong way (outward
// instead of inward), which would either infinite-loop or skip columns --
// changed to `lt++`.
vector<int> solve(vector<vector<int>> &mat){
    vector<int> ans;
    int n = mat.size();
    int m = mat[0].size();
    int lt=0, rt=m-1, top=0, bottom=n-1;

    while(top<=bottom && lt<=rt){

        for(int i=lt;i<=rt;i++){
            ans.push_back(mat[top][i]);
        }
        top++;

        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][rt]);
        }
        rt--;

        if(top<=bottom){
            for(int i=rt;i>=lt;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        if(lt<=rt){
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][lt]);
            }
            lt++;
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    vector<int> ans = solve(mat);
    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}
