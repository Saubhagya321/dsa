#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr,int n){
    int tail=0;
    int head=-1;
    //ds
    int ans =INT_MIN;
    map<int,int> mp;
    while (tail<n)
    { 
         while(head+1<n && (mp.find(arr[head+1]) == mp.end())){
            head++;
         }
         //check
         
         //shrink
         if(head>=tail){
          
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
