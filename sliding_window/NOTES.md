# Sliding Window — Session Notes & Mistakes

Consolidated learnings from working through the sliding-window problems in this folder. Focus is on **mistakes I actually made** and the **patterns to internalize** so I don't repeat them.

---

## 1. The three template variants

| Variant | Shape | When to use |
|---|---|---|
| **A** | `while (valid) expand;` then `if` shrink one step | Expansion stops *before* invalidity → window is always valid at the check point. Shrink one to make room for next iteration. |
| **B** | `expand one;` `if (invalid)` shrink one | One added element can push validity off by *at most 1 unit* → single removal restores it. Example: LC 3 (no duplicates). |
| **C** | `expand one;` `while (invalid)` shrink | One added element can push validity multiple steps off → need to shrink until valid. Example: LC 76 (min window substring), LC 1004 (max ones after k flips). |

### Golden rule
The expansion loop's exit condition must complement the shrink condition:
- **A** exits with a *valid* window → shrink is unconditional-by-one (pre-emptive, to allow next expansion).
- **C** exits with a possibly *invalid* window → shrink while invalid to restore.

### Deadlock trap I hit
Mixing "expand-while-valid" (A style) with "shrink-while-invalid" (C style) **deadlocks**: after expansion, the window is valid, so the while-shrink never runs → `tail` never advances → infinite loop.

---

## 2. Recurring mistakes I made

### 2a. Index vs value confusion in map lookups
Wrote `mp[head+1]` or `mp.find(head+1)` when `head+1` is an **index**. Wanted the value: `mp.find(arr[head+1])`.

Extra footgun: `mp[key]` on `std::map` **inserts** the key with default value if missing. So `mp[head+1] != mp.end()` is always true after touching it, and silently mutates the map inside the loop condition. Always use `mp.find(k) != mp.end()` or `mp.count(k)`.

### 2b. Inverted expansion condition
Wrote "expand while element IS in map" when I meant the opposite. Ended up with an inner loop that never runs on a fresh window (map is empty), so `head` never advanced and `ans` was garbage.

**Fix:** think about what makes the window *valid*, then expand *while valid*.

### 2c. `ans = INT_MIN`
Returning `INT_MIN` on empty input is almost never right. Initialize to `0` for length-based answers.

### 2d. Dead `else { tail++; head = tail-1; }` branch
Reset logic that discards state and, worse, leaves the map/count out of sync. Once the loop is properly maintained, this branch is unreachable — just delete it (or leave as harmless dead code, but don't rely on it).

### 2e. Guarding the shrink with a condition that can never hold
In fruits: wrote `if (mp.size() > 2) { shrink }`, but expansion prevents `mp.size()` from ever exceeding 2. Result: shrink never runs, infinite loop. Then wrote `if (mp.size() == 2)`, which fails at the end of the array: once we've consumed everything and `mp.size()` drops to 1, `tail` stops advancing.

**Fix:** in Variant A, shrink is **unconditional** (once per outer iteration). Its job isn't to *restore* validity — it's to *make room* so the next expansion can proceed.

### 2f. Redundant counter (`tcnt`)
Kept a separate `tcnt` variable equal to `head - tail + 1`. Just compute it directly.

### 2g. Operator precedence in the expansion condition
`while (head+1 < n && A || B)` parses as `(head+1 < n && A) || B` — the bounds check doesn't guard `B`. Always parenthesize: `while (head+1 < n && (A || B))`.

### 2h. Double-counting in "exact-k" attempts
Tried to count exact-k subarrays directly by adding `cnt++` both inside and after the inner loop. Off by one per tail. Also missed trailing-neutral-element subarrays (e.g., trailing evens after the k-th odd).

**Fix:** don't count exact-k directly. Use the trick in §3.

---

## 3. "Exact k" problems — the atMost trick

### How to identify
- Question asks for **count of subarrays with sum/count EXACTLY equal to k**.
- Examples in this folder:
  - `binary_subarray_sum.cpp` (LC 930)
  - `cnt_nice_subarrays.cpp` (LC 1248)
  - `subarr_k_diff_ints.cpp` (LC 992)

### Why direct sliding window fails
Sliding window needs a **monotone** validity condition. "sum == k" isn't monotone — adding a 0 keeps it equal, adding a 1 breaks it. Can't decide when to shrink vs expand.

### The trick
```
exactly(k) = atMost(k) - atMost(k - 1)
```
`atMost(k)` is a clean Variant-A window (validity `sum <= k` is monotone).

### atMost(k) skeleton (Variant A)
```cpp
int atMost(vector<int> &arr, int n, int k){
    if(k < 0) return 0;
    int tail = 0, head = -1, cur = 0, count = 0;
    while(tail < n){
        while(head + 1 < n && cur + delta(arr[head+1]) <= k){
            head++;
            cur += delta(arr[head]);
        }
        count += head - tail + 1;   // subarrays starting at tail
        if(head >= tail){
            cur -= delta(arr[tail]);
            tail++;
        } else {
            tail++; head = tail - 1;
        }
    }
    return count;
}
```

### When atMost applies
The "thing you count" must be **non-negative and monotone** under add/remove: sum of 0/1, count of odds, count of distinct values, etc. If it's not monotone (e.g., arbitrary integers with negatives), use **prefix-sum + hashmap** instead.

---

## 4. Problem-by-problem index

| File | Problem | Pattern | Notes |
|---|---|---|---|
| `len_of_long_substr_no_rept.cpp` | LC 3 — longest substr, no repeats | Variant A (or B) | Watch for index-vs-value bug; expansion condition. |
| `max_consecutves_one.cpp` | LC 1004 — max ones after k flips | Variant A | Look-ahead in expand: `arr[head+1] == 1 \|\| cnt < k`. Update `ans` unconditionally. |
| `fruit_baskets.cpp` | LC 904 — fruit into baskets | Variant A, `k=2` distinct | Shrink is unconditional-by-one. |
| `longest_substr_with_k_diffrent.cpp` | Longest substr with ≤ k distinct | Variant A | Same shape as fruits, generalized. |
| `binary_subarray_sum.cpp` | LC 930 — binary subarrays == goal | Exact-k → atMost trick | Handle `goal < 0` in atMost. |
| `cnt_nice_subarrays.cpp` | LC 1248 — exactly k odd numbers | Exact-k → atMost trick | Track odd count. |
| `subarr_k_diff_ints.cpp` | LC 992 — exactly k distinct | Exact-k → atMost trick | Track distinct via map size. |
| `longest_substr_atmost_k_distinct.cpp` | Longest substr with ≤ k distinct chars | Variant A | Max length, no atMost subtraction needed. |
| `max_points_from_cards.cpp` | LC 1423 — max card points | Sliding window on the **complement** | Greedy fails! Keep min window of `n-k`, return `total - minWindow`. |

---

## 5. Standard checklist before submitting a sliding-window solution

1. **Is the validity condition monotone?** If yes, Variant A/B/C. If no (exact-k on non-monotone), use atMost trick or prefix-sum+hashmap.
2. **Which variant?** Determined by how much invalidity one added element can cause.
3. **Expansion condition parenthesized correctly?** `head+1 < n &&` must guard *everything* after it.
4. **Using `mp.find()` (not `mp[k]`) for existence check?**
5. **Values vs indices** — every map/set operation on `arr[i]`, not `i`.
6. **Initialize `ans` sensibly** — `0` for lengths, `0` for counts, `INT_MAX` for min-length problems.
7. **Update `ans` unconditionally after the inner loop** (Variant A), not gated on a specific state.
8. **Shrink advances `tail` on every outer iteration** — otherwise infinite loop.
9. **Delete the dead `else { head = tail-1; }` branch** unless you have a real reason.
10. **Edge cases:** `n == 0`, `k == 0`, `k > n`, all-same elements, single element.

---

## 6. Max points from cards — special case

Not a standard sliding window on the *answer* window. Instead:
- You pick `i` from the left and `k-i` from the right.
- Equivalently: keep a contiguous middle window of length `n-k` and drop everything else.
- Answer = `totalSum - min(sum of window of length n-k)`.
- Edge case: `k >= n` → return `totalSum`.

**Greedy "take larger end" is wrong** — counterexample `[11,49,100,20,86,29,72], k=4`: greedy gives 207, optimal is 232 (`11+49+100+72`).
