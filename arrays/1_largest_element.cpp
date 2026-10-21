#include<bits/stdc++.h>
using namespace std ;

int solve_largest(vector<int> &arr){
    int mx =INT_MIN;
    for(int i=0;i<arr.size();i++){
        mx = max(mx,arr[i]);
    }

    return mx;
}

int solve_second_largest(vector<int> &arr){
    int mx = INT_MIN;
    int smx =INT_MIN;
    int n =arr.size();
    for(int i =0;i<n;i++){
           if(mx <= arr[i]){
            smx =mx;
            mx = arr[i];
           }
           else{
            if(smx <arr[i]){
                smx =arr[i];
            }
           }
    }

    return smx;
}

bool issorted(vector<int> &arr){
   int a = arr[0];
   for(int i =1;i<arr.size();i++){
     int b =arr[i];
    if(b < a)
       return false;
   }

   return true;
}

vector<int> remove_duplicate(vector<int> &arr){
    int i =0;
    int j=0;
    while(j<arr.size()){
        if(arr[j] == arr[i]){
            j++;
        }
        else{
            i++;
            arr[i]=arr[j];
        }
    }
 
    return vector<int>(arr.begin(), arr.begin() + i + 1);
}

void left_rotate_by_one(vector<int> &arr){
   
    int n =arr.size();
    int a =arr[1];
    int b =arr[0];
    for(int i =1;i<n-1;i++){
        arr[i-1] =a;
        a =arr[i+1];
    }
   arr[n-1] = b;

}

void leftrotatebyk(int k,vector<int>& arr){
    // 1,2,3 k=5 => 231 , 312,123  , 231,312->answer repetition after each n so left real rotation is k%n
    
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k+1);
    reverse(arr.begin()+k+1,arr.end());

}

void moveallzeros(vector<int> & arr){
    //logic is pointer to the  zero and the pointer to the 
   // 1,2,0,0,5,4   -> 
   int i,j;
   int n =arr.size();
   for(int k =0;k<n;k++){
       if(arr[k] ==0) {i = k; break;}
   }
    
   j = i+1;
   while(j<n){
      if(arr[j] != 0){
        swap(arr[j],arr[i]);
       
      
      }   
        j++;
   }
    
}


int findmaxconsecutiveones(vector<int> &arr){
    int tail=0;
    int head =-1;
    // 0 1 1 0 0 0 1 1 1 0 
    int mx =0;
    int n =arr.size();
     while(tail<arr.size()){
        while(head + 1 < n  && arr[head+1]==1){
            head++;
            mx = max(head-tail+1,mx);
        }

        if(tail<head){
            tail++;
        }
        else{
            tail++;
            head =tail-1;
        }
     }
 return mx ;
}


pair<int,int> twosum(vector<int> &arr,int rsum){
   int l =0;
   int h= arr.size()-1;
   while (l<h)
   {
    int csum = arr[l] + arr[h];
    if(csum == rsum){
        return {l,h};
    }
    else if(csum < rsum){
        l++;
    }
    else{
        h--;
    }
   }
   return {-1,-1};
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
    
    cout<< solve_largest(arr) <<endl;
    cout<< solve_second_largest(arr) <<endl;

}