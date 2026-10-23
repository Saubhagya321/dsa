#include<bits/stdc++.h>
using namespace std;

//0 to lo-1 is 0; lo --> mid -1 is 1;  mid to high is unsorted; high+1 to n-1 is 2

void solve(vector<int> &arr){
    int n =arr.size();
    int lo=0;
    int mid =0;
    int hi =n-1;
    while(mid<=hi){
        if(arr[mid]== 0){
           swap(arr[mid],arr[lo]);
           lo++;
           mid++;
        }
        else if(arr[mid]==1){
           mid++;
        }
        else if(arr[mid]==2){
           swap(arr[mid],arr[hi]);
           hi--;
        }
    }

}

int main(){
    vector<int> arr;
    int n;
    cin>>n;

    for(int i =0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    solve(arr);
    return 0;
}