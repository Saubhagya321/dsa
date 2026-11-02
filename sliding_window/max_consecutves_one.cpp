#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr,int n,int k){
    int tail=0;
    int head=-1;
    //ds
    int ans =INT_MIN;
    int cnt =0 ;
    while (tail<n)
    { 
         while(head+1<n && (arr[head+1] == 1 ||cnt<k)){
            head++;
            if(arr[head] ==0)cnt++;
         }
         //check
        ans = max(ans,head-tail+1);

         //shrink
         if(head>=tail){
        if(arr[tail] ==0)cnt--;
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
