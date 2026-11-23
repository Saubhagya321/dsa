#include<bits/stdc++.h>
using namespace std;

int check_last(int tar,int mid,vector<int> &arr){
    if(arr[mid]>tar){
        return 1;
    }
    else return 0;
}

int solve_last(int target,vector<int>&arr){
    int n =arr.size();
    int lo =0 ;
    int hi =n-1;
    int ans =n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check_last(target,mid,arr)==1){
             ans = mid;
        hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

     if(ans-1 >= 0 && arr[ans-1] == target) return ans-1;
     return -1;
}

int check_first(int tar,int mid,vector<int> &arr){
    if(arr[mid]<tar){
        return 0;
    }
    else return 1;
}

int solve_first(int target,vector<int>&arr){
    int n =arr.size();
    int lo =0 ;
    int hi =n-1;
    int ans =n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check_first(target,mid,arr)==1){
             ans = mid;
        hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

     return ans;
}
int countOccurrences(int target, vector<int> &arr){
    int n = arr.size();
    int first = solve_first(target, arr);
    if(first == n || arr[first] != target) return 0; // target not present
    int last = solve_last(target, arr);
    return last - first + 1;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;

    int count = countOccurrences(target, arr);
    cout << count << endl;
}