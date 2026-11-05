#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr,int n){
    int tail=0;
    int head=-1;
    //ds
    int ans =INT_MIN;
    int tcnt=0;
    map<int,int> mp;
    while (tail<n)
    { 
         while(head+1<n && (mp.size()<2 || (mp.size()==2 && mp.find(arr[head+1])!=mp.end()))){
            head++;
            mp[arr[head]]++;
            tcnt++;
         }
         //check
         ans = max(ans,tcnt);
         
         //shrink
         if(head>=tail){
          tcnt--;
          mp[arr[tail]]--;
          if(mp[arr[tail]] == 0)mp.erase(arr[tail]);
          tail++;
         }
         else{
             tail++;
             head = tail-1;
         }
        
    }

    return ans;
    
}

int main(){

    return 0;
}
