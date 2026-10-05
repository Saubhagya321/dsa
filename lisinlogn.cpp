#include<bits/stdc++.h>
using namespace std;

/*
===========================================================
🧠 PROBLEM: Longest Increasing Subsequence (LIS)
===========================================================

We use binary search + greedy to get O(n log n)

-----------------------------------------------------------
💡 CORE IDEA (WHAT lis ARRAY REALLY MEANS)
-----------------------------------------------------------

lis[len] = smallest possible ending value of an increasing
subsequence of length = len+1

IMPORTANT:
This array is NOT the actual LIS

-----------------------------------------------------------
🧪 EXAMPLE:
-----------------------------------------------------------

arr = 1 5 7 10 9 6 7 9 2 3

lis evolves:

1
1 5
1 5 7
1 5 7 10
1 5 7 9
1 5 6 9
1 5 6 7
1 5 6 7 9
1 2 6 7 9
1 2 3 7 9

Final lis = [1 2 3 7 9]
Length = 5

-----------------------------------------------------------
❗ IMPORTANT QUESTION:
HOW DO WE PRINT THE ACTUAL LIS?

-----------------------------------------------------------
🧠 YOUR INTUITION (REFINED — THIS IS THE KEY PART)
-----------------------------------------------------------

// ok now to print the lis

// see the lis is 1 5 6 7 9

// we got the last correctly as 9
// because this was the point where LIS was EXTENDED
// so this 9 is definitely correct last element

// now think:
// when this 9 was added, it must have extended something

// so what did it extend?
// → it extended a LIS ending at 7

// now go to that 7
// this 7 must have extended something
// → it extended 6

// then 6 → extended 5
// then 5 → extended 1

// so we can reconstruct backwards:
// 9 ← 7 ← 6 ← 5 ← 1

//-----------------------------------------------------------
// ⚠️ VERY IMPORTANT OBSERVATION
//-----------------------------------------------------------

// why NOT take earlier 9 (like the one replacing 10)?

// because:
// that 9 did NOT lead to further extension
// it was replaced later

// only those elements matter:
// which actually contributed to FINAL extension

//-----------------------------------------------------------
// 💡 CONCLUSION FROM THIS THINKING
//-----------------------------------------------------------

// we need to store:
// "when an element was inserted in lis,
//  from which previous element it came"

// i.e.

// 1) at what LENGTH this element was placed
// 2) from which INDEX it extended

//-----------------------------------------------------------
// 🧩 THIS GIVES US 2 ARRAYS
//-----------------------------------------------------------

// pos[len]
// → index in original array where LIS of length (len+1) ends

// parent[i]
// → previous index from which arr[i] extended

//-----------------------------------------------------------
// 🔗 CONNECTION TO CODE
//-----------------------------------------------------------

// okay so for each element if i get what it extended i can jus then reverse track from the back witht his array now when i go to make this array
// i found out tha lis is storing values but i need the indexes so the pos array comes in picture to make parent array

// idx = position in lis
// → tells LENGTH

// pos[idx] = i
// → tells where this length is ending

// parent[i] = pos[idx-1]
// → tells from where it extended

//-----------------------------------------------------------
*/




//-----------------------------------------------------------

// okay so for each element if i get what it extended,
// i can just reverse track from the back using this info

// i.e.
// if i know:
// "this element came from that element"
// then I can reconstruct LIS by going backwards

//-----------------------------------------------------------

// now problem:

// while building LIS, we are storing only VALUES in lis[]
// but to reconstruct answer, we need INDEXES

// because parent array stores INDEX connections
// not values

//-----------------------------------------------------------

// so question becomes:

// "when I place arr[i] at position idx in lis,
//  which INDEX in original array corresponds to this?"

// 👉 THIS is why we need pos[]

// pos[idx] = index in original array
// where LIS of length (idx+1) is ending

//-----------------------------------------------------------

// now connection becomes clear:

// lis[idx] = value
// pos[idx] = index of that value

//-----------------------------------------------------------

// now when arr[i] is placed at idx:

// it means:
// arr[i] is extending a subsequence of length idx

// so previous element must be:
// pos[idx - 1]

// hence:

// parent[i] = pos[idx - 1]

//-----------------------------------------------------------

// so final flow:

// 1. use lower_bound → get idx (length)

// 2. update lis[idx] = arr[i]

// 3. update pos[idx] = i   (store index)

// 4. connect:
//    parent[i] = pos[idx - 1]

//-----------------------------------------------------------

// now reconstruction becomes easy:

// start from:
// pos[last]  → last element of LIS

// then:
// parent → parent → parent

// reverse it

//-----------------------------------------------------------
vector<int> solve(vector<int> &arr){

    int n = arr.size();

    vector<int> lis;           // smallest tail values
    vector<int> pos;           // index of tails
    vector<int> parent(n, -1); // backtracking

    for(int i = 0; i < n; i++){

        // STEP 1: find position (length)
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        int idx = it - lis.begin();

        // STEP 2: update lis
        if(it == lis.end()){
            lis.push_back(arr[i]);
            pos.push_back(i);
        }
        else{
            *it = arr[i];
            pos[idx] = i;
        }

        // STEP 3: store "from where it extended"
        if(idx > 0){
            parent[i] = pos[idx - 1];
        }
    }

    /*
    -------------------------------------------------------
    🔁 RECONSTRUCTION (MATCHES YOUR THINKING)
    -------------------------------------------------------

    Start from last element of LIS

    keep going to parent:

    9 → 7 → 6 → 5 → 1

    reverse it
    */

    vector<int> ans;
    int cur = pos.back();

    while(cur != -1){
        ans.push_back(arr[cur]);
        cur = parent[cur];
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> lis = solve(arr);

    cout << "Length: " << lis.size() << "\n";

    cout << "LIS: ";
    for(int x : lis){
        cout << x << " ";
    }
    cout << "\n";
}


/*
===========================================================
🚀 FINAL CRUX (ULTRA SHORT REVISION)
===========================================================

1. lis → gives correct LENGTH (not sequence)

2. Only elements that EXTEND LIS matter
   (not ones that got replaced)

3. parent[i] → from where current element came

4. pos[len] → where LIS of this length ends

5. Start from last → go backwards using parent

-----------------------------------------------------------
⚡ MEMORY LINE:

"Track extension, not replacement"
===========================================================
*/