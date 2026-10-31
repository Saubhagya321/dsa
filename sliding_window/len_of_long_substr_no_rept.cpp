#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr,int n){
    int tail=0;
    int head=-1;
    map<int,int> mp;
    int ans =INT_MIN;
    while (tail<n)
    { 
         while(head+1<n && (mp.find(arr[head+1]) == mp.end())){
            head++;
             mp[arr[head]]++;
         }
         if(ans < head-tail+1)ans =head-tail+1;
         
         if(head>=tail){
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
