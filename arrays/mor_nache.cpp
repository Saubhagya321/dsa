#include<bits/stdc++.h>
using namespace std;

int getmajor1(vector<int>& arr){

    int cnt =0;
    int major=-1;
    int n= arr.size();
    for(int i =0;i<n;i++){
        if(major == arr[i]){
        
          cnt++;

        }
        else if(cnt ==0){
            major = arr[i];
            cnt =1;
        }
        else{
          cnt--;
    }
    }

    return major;
    
}


/*
    ORDER MATTERS: element-match checks MUST come before the cnt==0 checks.

    FAILING TEST CASE if you swap the order (checking cnt1==0 / cnt2==0
    before checking arr[i]==elem1 / arr[i]==elem2):

        arr = {3, 1, 1, 2, 1, 2}      (n=6, need count > n/3 = 2)
        true majority = 1 (appears 3 times)

        correct order -> candidates {elem1=2, elem2=1}, cnt2 correctly reaches 2
        buggy order   -> candidates collapse to {elem1=1, elem2=1}, both counts end at 0

    CRUX / WHY IT BREAKS:
    At i=4, x=1 arrives while cnt1 happens to be 0 and elem2 is ALREADY 1
    (with cnt2=1). The buggy order asks "is slot 1 free?" (cnt1==0) BEFORE
    asking "does this element already match my tracked candidate elem2?".
    So it hijacks the vote into elem1 instead of recognizing x==elem2 and
    incrementing cnt2. This breaks the algorithm's core invariant: elem1
    and elem2 must always stay two DISTINCT candidates, and a vote for an
    existing candidate must always extend that candidate's count, never
    spawn a duplicate. Once that invariant breaks, votes get silently
    misallocated between elem1/elem2 and a genuine majority element can
    vanish from the final answer entirely.
*/
pair<int,int> getmajor2(vector<int>& arr){
     int cnt1=0;int cnt2 =0;
     int n =arr.size();
     int elem1 = -1;int elem2 =-1;
     for(int i =0;i<n;i++){
        if(arr[i]==elem1){
            cnt1++;
        }
        else if(arr[i]==elem2){
            cnt2++;
        }
        else if(cnt1 == 0){
             elem1 = arr[i];
             cnt1++;
        }
        else if(cnt2 == 0){
  elem2 = arr[i];
             cnt2++;
        }
         else{
            cnt1--;
            cnt2--;
        }
     }

     return {elem1,elem2};
}
 
int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {   int a;
        cin>>a;
        arr.push_back(a);
    }

    
    return 0;
}