#include<bits/stdc++.h>
using namespace std;

// Input : arr[] = {1,1,2,2,3,3,4,5,5,6,6}
//{1,1,2,2,3,3,4,5,5,6,6}
//{0,0,0,0,0,0,1,1,1,1,1}
//{0,1,2,3,4,5,6,7,8,9,10}->last occurence at even index 
//check -> if(mid is even) then check if it is first or last occurence if it si last return 1 else 0,
//else -> if(mid is odd) then check if it is firs tor last occurence if it first then return 1; else return 0;
// Output: 4
// Explanation: Only the number 4 appears once in the array.

// "first occurrence" of arr[mid]'s value = it differs from the PREVIOUS element
// (or mid is index 0). "last occurrence" = it differs from the NEXT element
// (or mid is the last index).
bool isFirstOccurrence(int mid, vector<int> &arr){
    return mid == 0 || arr[mid] != arr[mid - 1];
}

bool isLastOccurrence(int mid, vector<int> &arr){
    int n = arr.size();
    return mid == n - 1 || arr[mid] != arr[mid + 1];
}

int check(int mid, vector<int> &arr){
    if(mid % 2 == 0){
        // before the single element, an even index is always a "first
        // occurrence" (start of its pair). once it becomes a "last
        // occurrence" too (i.e. the pair breaks), we've reached/passed
        // the single element -> answer candidate
        if(isLastOccurrence(mid, arr)) return 1;
        else return 0;
    }
    else{
        // before the single element, an odd index is always a "last
        // occurrence" (end of its pair). once it becomes a "first
        // occurrence" too, we've reached/passed the single element
        if(isFirstOccurrence(mid, arr)) return 1;
        else return 0;
    }
}

int solve(int n, vector<int> &arr){
    int lo = 0;
    int hi = n - 1;
    int ans = n - 1; // default: check is all-0 means single element is the last index
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid, arr) == 1){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,4,5,5,6,6};
    int n = arr.size();
    int idx = solve(n, arr);
    cout << "Single element: " << arr[idx] << " at index " << idx << endl;
    return 0;
}