## ✅ Binary Search Problem Patterns

Here’s a list of **common patterns** where binary search is applicable:

---

### ### 1. **Basic Binary Search**

> **Problem:** Find an element in a sorted array
> 🔍 Pattern: Array is **sorted in ascending/descending order**

**Examples:**

* Search an element in sorted array
* First/Last occurrence of element (lower/upper bound)
* Count of occurrences

---

### ### 2. **Answer Lies in a Range** (Search on Answer Space)

> **Problem:** Find the minimum/maximum value that satisfies a condition
> 🔍 Pattern: Function `f(x)` is **monotonic** (either increasing or decreasing)

**Examples:**

* \[✓] **Minimum Nth root of M** (your case)
* \[✓] **Koko Eating Bananas** – find minimum eating speed
* \[✓] **Minimum number of days to make bouquets**
* \[✓] **Allocate books** – minimum maximum pages
* \[✓] **Painters Partition Problem**
* \[✓] **Find smallest divisor such that sum ≤ threshold**

🧠 These use a **custom `isValid(mid)` function** and apply binary search on a value range.

---

### ### 3. **First/Last Occurrence**

> **Problem:** Find leftmost/rightmost position of target
> 🔍 Pattern: Duplicates in sorted array, and position matters

**Examples:**

* Lower bound / Upper bound
* Count of elements less than `x`
* First bad version
* Peak index in a mountain array

---

### ### 4. **Binary Search on Index**

> **Problem:** Use BS on **indexes**, not values
> 🔍 Pattern: Sorted input, or conceptual mid-check

**Examples:**

* **Find peak in mountain array**
* **Search in rotated sorted array**
* **Index of first 1 in row of binary matrix**
* **Aggressive cows** (maximize minimum distance between placed cows)

---

### ### 5. **Binary Search on Real Numbers**

> **Problem:** Precision-based problems
> 🔍 Pattern: Need to find an answer within some `epsilon` precision

**Examples:**

* Square root of a number
* Nth root of a number
* Median of two sorted arrays
* Max/min average subarray

Use: `while (high - low > eps)`

---

### ✅ Summary Table

| Pattern                     | Condition | Key Idea                       |
| --------------------------- | --------- | ------------------------------ |
| Sorted array                | Yes       | Regular binary search          |
| Answer in range             | Yes       | Binary search on answer space  |
| Duplicates, need first/last | Yes       | Lower/upper bound logic        |
| Peaks or rotated arrays     | Yes       | Custom mid logic               |
| Precision (floats/roots)    | Yes       | BS with tolerance (`1e-6` etc) |

---
