#include<bits/stdc++.h>
using namespace std;

/*
    MULTISET NOTES (C++ STL)
    =========================

    WHAT IS IT
    ----------
    - Defined in <set> (already pulled in by bits/stdc++.h).
    - Stores elements in SORTED order automatically, and unlike `set`,
      it ALLOWS DUPLICATES.
    - Internally implemented as a self-balancing BST (Red-Black Tree),
      NOT a hash table and NOT an array.

    IMPORTANT CORRECTION (common misconception)
    ---------------------------------------------
    multiset is NOT random-access like an array, and it is NOT a priority_queue.
    - priority_queue only gives you fast access to the TOP (max or min) element.
    - multiset gives you fast access to BOTH ends (smallest via begin(),
      largest via rbegin()) AND keeps everything else sorted in between,
      but you cannot do ms[i] to jump to the i-th element directly (no
      random access) because it's a tree, not a contiguous array.
    - If you need "give me the k-th smallest element" in O(log n), plain
      multiset can't do that either — you'd need a Policy-Based Data
      Structure (ordered_set / order_statistics tree from <ext/pb_ds>),
      which is a separate, more advanced topic.

    WHY USE MULTISET
    -----------------
    - Keeps data sorted automatically as you insert/erase (no need to
      re-sort after every change, unlike a vector).
    - O(log n) insert, erase, find, count — much faster than a sorted
      vector's O(n) insert/erase.
    - Handles duplicate values cleanly (unlike `set`, which stores each
      value only once).
    - Great when you repeatedly need: min, max, and "does X exist / how
      many times" while the data keeps changing.

    TIME COMPLEXITY SUMMARY
    -------------------------
    insert(x)         -> O(log n)
    erase(value)       -> O(log n + count(value))  (removes ALL copies of value)
    erase(iterator)    -> O(log n)                  (removes ONE element)
    find(x)            -> O(log n)
    count(x)           -> O(log n + count(value))
    lower_bound/upper_bound -> O(log n)
    begin()/rbegin()   -> O(1)  (smallest / largest element)
*/

void multiset_demo(){

    multiset<int> ms;

    // ---------- ADD ----------
    ms.insert(5);
    ms.insert(1);
    ms.insert(9);
    ms.insert(5);   // duplicates allowed -> {1, 5, 5, 9}

    cout << "After inserts: ";
    for(int x : ms) cout << x << " ";   // always prints in sorted order
    cout << endl;

    // ---------- SMALLEST / LARGEST ----------
    cout << "Smallest: " << *ms.begin() << endl;
    cout << "Largest: " << *ms.rbegin() << endl;

    // ---------- SEARCH ----------
    if(ms.find(5) != ms.end())
        cout << "5 exists in the multiset" << endl;

    cout << "Count of 5: " << ms.count(5) << endl;   // how many times 5 appears

    // ---------- DELETE ----------
    // erase(value) removes ALL occurrences of that value
    multiset<int> temp = ms;
    temp.erase(5);
    cout << "After erase(5) [removes all 5s]: ";
    for(int x : temp) cout << x << " ";
    cout << endl;

    // to remove only ONE occurrence, erase a single iterator
    auto it = ms.find(5);
    if(it != ms.end())
        ms.erase(it);   // removes just ONE copy of 5
    cout << "After erasing one occurrence of 5: ";
    for(int x : ms) cout << x << " ";
    cout << endl;

    // ---------- UPDATE ----------
    // multiset has NO direct update/replace function.
    // To "update" a value: erase the old one, insert the new one.
    it = ms.find(9);
    if(it != ms.end()){
        ms.erase(it);
        ms.insert(20);
    }
    cout << "After 'updating' 9 -> 20: ";
    for(int x : ms) cout << x << " ";
    cout << endl;

    // ---------- lower_bound / upper_bound ----------
    // lower_bound(x): first element >= x
    // upper_bound(x): first element > x
    ms.insert(3);
    ms.insert(7);
    cout << "multiset now: ";
    for(int x : ms) cout << x << " ";
    cout << endl;

    auto lb = ms.lower_bound(5);
    auto ub = ms.upper_bound(5);
    cout << "lower_bound(5): " << (lb != ms.end() ? to_string(*lb) : "none") << endl;
    cout << "upper_bound(5): " << (ub != ms.end() ? to_string(*ub) : "none") << endl;

    // ---------- SIZE / EMPTY ----------
    cout << "Size: " << ms.size() << endl;
    cout << "Empty? " << (ms.empty() ? "yes" : "no") << endl;
}

int main(){
    multiset_demo();
}

/*
    QUICK COMPARISON
    -----------------
    set          -> sorted, unique elements only, O(log n) ops
    multiset     -> sorted, duplicates allowed, O(log n) ops
    unordered_set-> not sorted, unique only, O(1) avg ops
    priority_queue-> only fast access to top (max or min), not fully sorted,
                     no arbitrary search/erase in O(log n)
    vector (sorted) -> O(1) random access, but O(n) insert/erase
*/
