#include<bits/stdc++.h>
using namespace std;

void merge(int left,int mid,int right, vector<int> &a){
     
    vector<int> temp;
    int i=left;
    int j =mid+1;
    int k=0;
    while(i<=mid && j <=right){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
          i++;

        }
        else{
           temp.push_back(a[j]);
           j++;
        }
    }
     // leftover elements (jo tumne pehle socha tha)
    while (i <= mid) { temp.push_back(a[i]); i++; }
    while (j <= right) { temp.push_back(a[j]); j++; }
    
    // ab temp ko wapas arr mein copy karo, position left se start karke
    for (int k = 0; k < temp.size(); k++) {
        a[left + k] = temp[k];
    }

   
}

int mergesort(int left,int right,vector<int> &a){
    if (left >= right) return;              // base case
    int mid = left + (right-left)/2;

    mergesort(left,mid,a);
    mergesort(mid+1,right,a);
    merge(left,mid,right,a);
}

// Same structure as merge()/mergesort() above, but merge now returns an int
// (count of inversions found while merging this left/right half), and
// mergesort returns the sum of counts from both halves plus its own merge.
int merge_inv(int left,int mid,int right, vector<int> &a){

    vector<int> temp;
    int i=left;
    int j =mid+1;
    int cnt=0;
    while(i<=mid && j <=right){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
          i++;

        }
        else{
           temp.push_back(a[j]);
           j++;
           // a[i..mid] is already sorted, so if a[j] < a[i], then a[j] is
           // also less than every element from i to mid -> that's (mid-i+1)
           // inversions in one shot.
           cnt += (mid - i + 1);
        }
    }
     // leftover elements (jo tumne pehle socha tha)
    while (i <= mid) { temp.push_back(a[i]); i++; }
    while (j <= right) { temp.push_back(a[j]); j++; }

    // ab temp ko wapas arr mein copy karo, position left se start karke
    for (int k = 0; k < temp.size(); k++) {
        a[left + k] = temp[k];
    }

    return cnt;
}

int mergesort_inv(int left,int right,vector<int> &a){
    if (left >= right) return 0;              // base case
    int mid = left + (right-left)/2;

    int cnt = 0;
    cnt += mergesort_inv(left,mid,a);
    cnt += mergesort_inv(mid+1,right,a);
    cnt += merge_inv(left,mid,right,a);
    return cnt;
}


int main(){
     vector<int> arr;
     for(int i =0;i<arr.size();i++){
     int a;
     cin>>a;
     arr.push_back(a);
     }
    return 0;
}