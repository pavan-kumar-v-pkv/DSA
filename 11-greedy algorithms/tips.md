# 🧠 Greedy Algorithms – Tricks, Patterns & Common Questions

---

## 📌 What is Greedy Algorithm?

Greedy algorithms build up a solution piece by piece, always choosing the option that looks best **at the moment**.

> "Make the locally optimal choice at each step, hoping it leads to a globally optimal solution."

---

## ✅ When Does Greedy Work?

- ✅ **Greedy Choice Property**: A global optimum can be arrived at by choosing a local optimum.
- ✅ **Optimal Substructure**: Optimal solution of the whole problem includes optimal sub-solutions.

---

## 🔥 Common Patterns Where Greedy Works

### 1. Activity Selection / Interval Scheduling
- **Goal**: Maximize number of non-overlapping activities.
- **Trick**: Sort by **end time**, pick earliest finishing activity.
- ✅ Works perfectly.

---

### 2. Fractional Knapsack
- **Goal**: Maximize value in a knapsack (fractions allowed).
- **Trick**: Sort by **value/weight ratio**, take most valuable first.
- ✅ Works.

---

### 3. Huffman Encoding (Data Compression)
- **Goal**: Minimize cost of encoding symbols.
- **Trick**: Combine lowest frequency symbols using **min-heap**.
- ✅ Works.

---

### 4. Job Sequencing with Deadlines
- **Goal**: Schedule jobs to maximize total profit before deadlines.
- **Trick**: Sort by **profit descending**, use union-find or greedy slot allocation.
- ✅ Works.

---

### 5. Coin Change (Minimum Coins)
- **Goal**: Use fewest coins to make amount (unlimited supply).
- **Trick**: Always pick largest denomination ≤ remaining amount.
- ⚠️ Works **only** if coin system is **canonical**.

---

## 🛠 Greedy Techniques / Tricks

| Technique | Description | Example |
|----------|-------------|---------|
| **Sort & Scan** | Sort input and iterate greedily | Activity Selection, Merge Intervals |
| **Priority Queue / Heap** | Select smallest/largest efficiently | Huffman Coding, Connecting Ropes |
| **Two Pointers** | Greedy from both ends | Lifeboats, Interval Overlap |
| **Cost-Benefit Ratio** | Sort by ratio for best payoff | Fractional Knapsack |

---

## 💻 Classic Greedy Problems (with Platforms)

| Problem | Platform | Idea |
|--------|----------|------|
| Jump Game | Leetcode | Furthest reach so far |
| Gas Station | Leetcode | Track fuel deficit |
| Greedy Florist | HackerRank | Sort prices, buy costly first |
| Minimum Platforms | GFG | Sort arrivals & departures |
| Merge Intervals | Leetcode | Sort & merge overlapping |
| Connect Ropes | Leetcode | Min-heap to combine smallest ropes |

---

## ❌ When Greedy Fails (Use DP Instead)

| Problem | Why Greedy Fails |
|---------|------------------|
| 0/1 Knapsack | Requires tracking multiple states |
| Longest Increasing Subsequence | Need global information |
| Grid Path Problems (min cost, max score) | Greedy gets stuck in local minima |

---

## 🎯 How to Identify Greedy-Friendly Problems

Ask yourself:

- ✅ Is the problem asking for **min/max** of something?
- ✅ Can I sort the input and make **local decisions**?
- ✅ Can I **prove** that local choices won't affect the global result?

---

## 📚 Bonus Tip: Proving Greedy is Correct

- Use **Greedy Stays Ahead** proof technique.
- Try **Counterexample** to show if greedy fails.
- Compare with **Dynamic Programming** version to validate.

---

