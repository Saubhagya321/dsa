#include<bits/stdc++.h>
using namespace std;

pair<int,int> solve2sum(int k,vector<int> &arr){
    int n=arr.size();
    int l=0;
    int h=n-1;
    sort(arr.begin(),arr.end());

    int sum = arr[l]+arr[h];
    while(l<h){
        sum = arr[l]+arr[h];
        if(sum == k){
            pair<int,int> ans = {l,h};
            while(l<h && arr[l] == arr[l+1] )l++;
            while(l<h && arr[h] == arr[h-1] )h--;
            return ans;
        }
        else if(sum<k){
             l++;
        }
        else{
             h--;
        }
    }
    return {-1,-1};
}

auto solve3sum(vector<int> &arr,int k){
    for(int i=0;i<arr.size();i++){
        int sum = k-arr[i];
        vector<int> sub(arr.begin()+i+1,arr.end());
        auto  x = solve2sum(sum,sub);
    }
}

int main(){
    return 0;
}