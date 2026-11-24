#include<bits/stdc++.h>
using namespace std;

// ============================================================
// PART 1: Search in Rotated Sorted Array (NO duplicates)
// ============================================================
//
// Key idea: in a rotated sorted array with all DISTINCT elements,
// there is exactly one "break point" (where a bigger element is
// followed by a smaller one). That break can only lie in one of
// the two halves [low..mid] or [mid..high] at a time - so AT LEAST
// one half is always genuinely sorted.
//
// We check "is left half sorted?" using arr[low] <= arr[mid].
// - If true, left half [low..mid] is sorted -> if target lies in
//   that sorted range, search left, else search right.
// - If false, right half [mid..high] must be sorted instead -> if
//   target lies in that sorted range, search right, else search left.
//
// This comparison is RELIABLE here because with distinct elements,
// arr[low] <= arr[mid] can only be true when there's truly no break
// hidden in between.

int searchNoDuplicates(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] == target) return mid;

        // is the left half [low..mid] sorted?
        if(nums[low] <= nums[mid]){
            // left half sorted -> check if target lies inside it
            if(nums[low] <= target && target < nums[mid]){
                high = mid - 1;   // search left
            } else {
                low = mid + 1;    // search right
            }
        }
        else{
            // right half [mid..high] must be sorted
            if(nums[mid] < target && target <= nums[high]){
                low = mid + 1;    // search right
            } else {
                high = mid - 1;   // search left
            }
        }
    }

    return -1; // not found
}

// ============================================================
// PART 2: Search in Rotated Sorted Array II (duplicates ALLOWED)
// ============================================================
//
// PROBLEM with duplicates: the trick "arr[low] <= arr[mid] means
// left half is sorted" is no longer reliable.
//
// arr[low] == arr[mid] can now happen in TWO different situations
// that look identical from the outside:
//   Case A (truly sorted):      [3,3,3,4,5,6]  -> arr[low]=3, arr[mid]=3, genuinely flat/sorted
//   Case B (break is HIDDEN):   [3,1,2,3,3,3,3] with low=0, mid=3
//                                -> arr[low]=3, arr[mid]=3 too, but there's a
//                                   dip (the "1") hidden in between!
//
// We cannot tell Case A from Case B just by comparing arr[low] and
// arr[mid] - so we can't safely decide which half is sorted.
//
// Concrete failure if we ignore this and trust arr[low] <= arr[mid]
// blindly: arr=[3,1,2,3,3,3,3], target=2
//   low=0,high=6,mid=3 -> arr[mid]=3 (not target)
//   arr[low]=3 <= arr[mid]=3 -> wrongly treated as "left sorted"
//   target 2 not in [3,3) -> search right -> low=4
//   ...continues sliding right, NEVER finds the 2 sitting at index 2.
//   Returns "not found" even though 2 IS in the array. BUG.
//
// FIX: when arr[low] == arr[mid] == arr[high], we have NO information
// about which half is sorted - the signal is genuinely ambiguous.
// Since we can't safely eliminate a full half, the only safe move is
// to shrink the search space by ONE element and re-check.
//
// This is SAFE (not just an optimization) because:
//   - arr[mid] != target is already guaranteed (checked earlier in
//     the loop, would've returned true otherwise).
//   - arr[low] and arr[high] equal arr[mid] in this branch, so they
//     also aren't the target.
//   - So discarding one duplicate copy from either end never risks
//     skipping over a genuine, distinct target value elsewhere in
//     the array.
//
// NOTE: low++ alone works, high-- alone works, and doing BOTH works.
// All three are equally CORRECT - the ambiguity is symmetric, there's
// nothing that makes trimming one side "safer" than the other. Doing
// both together is purely a SPEED optimization (burns through a run
// of duplicate values roughly twice as fast on average); it is not
// required for correctness.
//
// Trade-off: this degrades worst case time complexity to O(n)
// (e.g. an array that's almost all identical values), unlike the
// clean O(log n) guarantee when duplicates aren't allowed.

bool searchWithDuplicates(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target) return true;

        // Ambiguous case: can't tell which half is sorted.
        // Shrinking from both ends here is just faster than doing
        // only low++ or only high-- - not required for correctness.
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }

        // left half sorted?
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;   // target in sorted left half
            } else {
                low = mid + 1;    // search right
            }
        }
        else{
            // right half must be sorted
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;    // target in sorted right half
            } else {
                high = mid - 1;   // search left
            }
        }
    }

    return false; // not found
}

int main(){
    // Part 1 demo: no duplicates
    vector<int> nums = {4,5,6,7,0,1,2};
    int target1 = 0;
    cout << "No duplicates -> index: " << searchNoDuplicates(nums, target1) << endl;

    // Part 2 demo: duplicates allowed
    vector<int> arr = {3,1,2,3,3,3,3};
    int target2 = 2;
    cout << "With duplicates -> found: "
         << (searchWithDuplicates(arr, target2) ? "true" : "false") << endl;

    return 0;
}
