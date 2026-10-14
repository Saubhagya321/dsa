# 🚀 CP Technique: Avoiding `memset` Using Visited Array (Timestamp Trick)

When solving DP problems with **multiple test cases**, a very common bottleneck is clearing large DP tables again and again using `memset`.

This article explains a powerful trick — the **Visited Array (Timestamp Technique)** — which helps you **avoid clearing DP entirely** and makes your solution significantly faster.

---

## ❗ The Problem

Suppose you have:

```
dp[1000][1000]
```

and for each test case, you do:

```
memset(dp, -1, sizeof(dp));
```

### Worst Case:

* DP size = `10^6`
* Test cases = `10^5`

Total operations:

```
10^5 × 10^6 = 10^11 ❌ (Too slow)
```

Even if your DP logic is optimal, this alone can cause **TLE**.

---

## 💡 The Idea

Instead of clearing DP, we **mark which states are valid for the current test case**.

We use:

* `dp[i][j]` → stores answer
* `vis[i][j]` → stores *when* this state was last computed
* `timer` → current test case ID

---

## 🧠 Key Insight

Instead of:

```
dp[i][j] = -1 → not computed
```

We do:

```
vis[i][j] == timer → computed in current test
vis[i][j] != timer → stale value (ignore)
```

---

## 🔧 Implementation Pattern

### Step 1: Declare arrays

```cpp
ll dp[N][N];
int vis[N][N];
int timer = 1;
```

---

### Step 2: Modify DP check

Instead of:

```cpp
if (dp[i][j] != -1) return dp[i][j];
```

Use:

```cpp
if (vis[i][j] == timer) return dp[i][j];
```

---

### Step 3: Mark state as visited

```cpp
vis[i][j] = timer;
dp[i][j] = result;
```

---

### Step 4: Increment timer per test case

```cpp
timer++;
```

---

## ✅ Example (Balanced Bracket DP)

```cpp
ll solve(int i, int open) {
    if (vis[i][open] == timer) return dp[i][open];

    vis[i][open] = timer;

    // compute answer...
    return dp[i][open] = ans;
}
```

---

## ⚡ Why This Works

* Old DP values remain in memory
* But `vis[][]` ensures we only use values from the **current test**
* No need to clear arrays

---

## 📊 Complexity Improvement

| Approach      | Cost per Test | Total Cost  |
| ------------- | ------------- | ----------- |
| memset        | O(n²)         | ❌ Too slow  |
| visited array | O(1)          | ✅ Efficient |

Total DP still:

```
O(sum of n²) ≤ 10^6 ✔
```

---

## 🔥 When to Use This Trick

Use this whenever:

* Multiple test cases (`T` large)
* Large DP table (`n²`, `n³`)
* Reinitialization is costly

---

## 🧩 Common Use Cases

* Interval DP
* Grid DP
* Digit DP
* String DP
* Memoized recursion problems

---

## ⚠️ Important Notes

* Use `int` for `vis`, not `bool`
* Always increment `timer` per test case
* Make sure `timer` doesn’t overflow (rare, but safe with `int`)

---

## 🏁 Summary

Instead of:

```
memset(dp, -1, sizeof(dp));
```

Use:

```
vis[i][j] == timer
```

👉 This turns a potentially **TLE solution into AC**

---

## 💬 Final Thought

This is one of those **small but powerful CP tricks** that:

* doesn’t change your logic
* but drastically improves performance

Once you start using it, you’ll never go back to `memset` for large DP again ⚡

---
