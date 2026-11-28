#include<bits/stdc++.h>
using namespace std;

// check(mid) tells us we're still on the "rising" slope:
// if arr[mid] < arr[mid+1], a peak must exist somewhere to the right
// (including mid+1), so we move lo = mid+1.
// otherwise (arr[mid] >= arr[mid+1]), we're on/after a "falling" slope,
// so a peak lies at mid or to its left, we move hi = mid (keep mid, since
// mid itself could be the peak).
bool check(int mid, vector<int> &arr){
    return arr[mid] < arr[mid+1];
}

int solve(int n, vector<int> &arr){
    int lo = 0;
    int hi = n - 1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(check(mid, arr)){
            lo = mid + 1;
        }
        else{
            hi = mid;
        }
    }
    return lo; // lo == hi -> index of a peak element
}

int main(){
    vector<int> arr = {1,2,1,3,5,6,4};
    int n = arr.size();
    int idx = solve(n, arr);
    cout << "Peak element: " << arr[idx] << " at index " << idx << endl;
    return 0;
}
