#include<bits/stdc++.h>
using namespace std;


int atMost(vector<int> &arr, int n, int goal){
    if(goal < 0) return 0;
    int tail = 0;
    int head = -1;
    int sum = 0;
    int count = 0;
    while(tail < n){
        // expand while window sum stays <= goal
        while(head + 1 < n && sum + arr[head + 1] <= goal){
            head++;
            sum += arr[head];
        }
        // window [tail..head] is largest valid starting at tail
        count += head - tail + 1;

        // shrink one
        if(head >= tail){
            sum -= arr[tail];
            tail++;
        }
        else{
            tail++;
            head = tail - 1;
        }
    }
    return count;
}

int solve(vector<int> &arr, int n, int goal){
    return atMost(arr, n, goal) - atMost(arr, n, goal - 1);
}

int main(){

    return 0;
}
