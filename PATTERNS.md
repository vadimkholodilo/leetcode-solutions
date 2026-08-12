# LeetCode Pattern Cheatsheet (C#)

Personal reference: for each common LeetCode pattern — when to recognize it, and a minimal
C# skeleton to adapt. Signal to look for → skeleton to copy, not full solutions.

**Assumed context for every snippet below:**
- `using System.Linq;` where LINQ methods (`Sum`, `Max`, `OrderBy`, `Select`, `Cast`, `Enumerable.Range`) are used.
- `ListNode` / `TreeNode` follow LeetCode's standard C# boilerplate (lowercase fields to match what LeetCode generates):

```csharp
public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int val = 0, ListNode next = null) { this.val = val; this.next = next; }
}

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val; this.left = left; this.right = right;
    }
}
```

---

## Table of Contents

1. [Two Pointers](#1-two-pointers)
2. [Sliding Window](#2-sliding-window)
3. [Fast & Slow Pointers (Linked List)](#3-fast--slow-pointers-linked-list)
4. [Binary Search](#4-binary-search)
5. [Binary Search on Answer](#5-binary-search-on-answer)
6. [Prefix Sum](#6-prefix-sum)
7. [Hash Map / Frequency Counting](#7-hash-map--frequency-counting)
8. [Monotonic Stack](#8-monotonic-stack)
9. [Stack for Matching/Parsing](#9-stack-for-matchingparsing)
10. [Tree DFS (Recursive)](#10-tree-dfs-recursive)
11. [Tree BFS (Level Order)](#11-tree-bfs-level-order)
12. [Graph DFS (Grid/Adjacency)](#12-graph-dfs-gridadjacency)
13. [Graph BFS (Shortest Path / Multi-source)](#13-graph-bfs-shortest-path--multi-source)
14. [Topological Sort](#14-topological-sort)
15. [Backtracking](#15-backtracking)
16. [Dynamic Programming — 1D](#16-dynamic-programming--1d)
17. [Dynamic Programming — 2D / Grid](#17-dynamic-programming--2d--grid)
18. [Dynamic Programming — Knapsack](#18-dynamic-programming--knapsack)
19. [Greedy / Intervals](#19-greedy--intervals)
20. [Heap / Priority Queue](#20-heap--priority-queue)
21. [Union-Find (Disjoint Set)](#21-union-find-disjoint-set)
22. [Trie](#22-trie)
23. [Linked List Reversal](#23-linked-list-reversal)
24. [Bit Manipulation](#24-bit-manipulation)
25. [Matrix Traversal](#25-matrix-traversal)
26. [Design — Hash Map + Doubly Linked List (LRU Cache)](#26-design--hash-map--doubly-linked-list-lru-cache)

---

## 1. Two Pointers

**Recognize:** sorted array, need pairs/triplets summing to a target, comparing from both ends,
in-place partitioning (dedupe, move zeroes).

```csharp
public int[] TwoPointers(int[] nums, int target)
{
    int left = 0, right = nums.Length - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target) return new[] { left, right };
        if (sum < target) left++;
        else right--;
    }
    return Array.Empty<int>();
}
```

Variant — same-direction pointers (in-place overwrite, e.g. Move Zeroes / Remove Duplicates):

```csharp
public int RemoveDuplicates(int[] nums)
{
    int slow = 0;
    for (int fast = 1; fast < nums.Length; fast++)
    {
        if (nums[fast] != nums[slow])
        {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}
```

---

## 2. Sliding Window

**Recognize:** "contiguous subarray/substring", longest/shortest/count satisfying a condition.
Fixed-size window vs. dynamically growing/shrinking window.

```csharp
// Variable-size window: shrink while invalid, track best size
public int LongestSubstringWithoutRepeating(string s)
{
    var seen = new HashSet<char>();
    int left = 0, best = 0;

    for (int right = 0; right < s.Length; right++)
    {
        while (seen.Contains(s[right]))
        {
            seen.Remove(s[left]);
            left++;
        }
        seen.Add(s[right]);
        best = Math.Max(best, right - left + 1);
    }
    return best;
}
```

```csharp
// Fixed-size window of size k
public int MaxSumFixedWindow(int[] nums, int k)
{
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += nums[i];

    int best = windowSum;
    for (int i = k; i < nums.Length; i++)
    {
        windowSum += nums[i] - nums[i - k];
        best = Math.Max(best, windowSum);
    }
    return best;
}
```

---

## 3. Fast & Slow Pointers (Linked List)

**Recognize:** cycle detection, find middle node, "kth from end", detect palindrome list.

```csharp
public bool HasCycle(ListNode head)
{
    var slow = head;
    var fast = head;

    while (fast != null && fast.next != null)
    {
        slow = slow.next;
        fast = fast.next.next;
        if (slow == fast) return true;
    }
    return false;
}

public ListNode FindMiddle(ListNode head)
{
    var slow = head;
    var fast = head;

    while (fast != null && fast.next != null)
    {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow; // second middle if even length
}
```

---

## 4. Binary Search

**Recognize:** sorted array, need index/boundary in O(log n). Watch for rotated arrays,
duplicates, and "first/last occurrence" variants.

```csharp
public int BinarySearch(int[] nums, int target)
{
    int left = 0, right = nums.Length - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

Variant — leftmost insertion point / first index where predicate is true:

```csharp
public int LowerBound(int[] nums, int target)
{
    int left = 0, right = nums.Length; // note: exclusive right
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}
```

Variant — rotated sorted array (compare against the sorted half):

```csharp
public int SearchRotated(int[] nums, int target)
{
    int left = 0, right = nums.Length - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid]) // left half is sorted
        {
            if (nums[left] <= target && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        else // right half is sorted
        {
            if (nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}
```

---

## 5. Binary Search on Answer

**Recognize:** "minimize the maximum" / "maximize the minimum", monotonic feasibility check
over a range of possible answers (e.g. Koko Eating Bananas, capacity to ship packages).

```csharp
public int BinarySearchOnAnswer(int[] nums, int constraint)
{
    int low = 1, high = nums.Max(); // define feasible answer range

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (IsFeasible(nums, mid, constraint)) high = mid;   // mid works, try smaller
        else low = mid + 1;                                  // mid too small, need bigger
    }
    return low;
}

private static bool IsFeasible(int[] nums, int candidate, int constraint)
{
    // e.g. simulate consumption/allocation with `candidate` and check against constraint
    return true;
}
```

---

## 6. Prefix Sum

**Recognize:** repeated range-sum queries, subarray sum equals target, "product except self".

```csharp
public int[] BuildPrefixSums(int[] nums)
{
    var prefix = new int[nums.Length + 1];
    for (int i = 0; i < nums.Length; i++)
        prefix[i + 1] = prefix[i] + nums[i];
    return prefix; // sum(i..j) = prefix[j + 1] - prefix[i]
}
```

Variant — subarray sum equals K (prefix sum + hash map):

```csharp
public int SubarraySumEqualsK(int[] nums, int k)
{
    var prefixCount = new Dictionary<int, int> { [0] = 1 };
    int sum = 0, count = 0;

    foreach (var n in nums)
    {
        sum += n;
        if (prefixCount.TryGetValue(sum - k, out var c)) count += c;
        prefixCount[sum] = prefixCount.GetValueOrDefault(sum) + 1;
    }
    return count;
}
```

---

## 7. Hash Map / Frequency Counting

**Recognize:** anagrams, majority element, "have I seen this before", grouping by a derived key.

```csharp
public bool IsAnagram(string s, string t)
{
    if (s.Length != t.Length) return false;

    var counts = new Dictionary<char, int>();
    foreach (var c in s) counts[c] = counts.GetValueOrDefault(c) + 1;
    foreach (var c in t)
    {
        if (!counts.ContainsKey(c) || --counts[c] < 0) return false;
    }
    return true;
}

public IList<IList<string>> GroupAnagrams(string[] strs)
{
    var groups = new Dictionary<string, List<string>>();
    foreach (var s in strs)
    {
        var key = new string(s.OrderBy(c => c).ToArray()); // canonical key
        if (!groups.TryGetValue(key, out var list))
            groups[key] = list = new List<string>();
        list.Add(s);
    }
    return groups.Values.Cast<IList<string>>().ToList();
}
```

---

## 8. Monotonic Stack

**Recognize:** "next greater/smaller element", daily temperatures, histogram/rectangle problems.
Stack holds indices in increasing/decreasing order of value; pop while the invariant breaks.

```csharp
public int[] DailyTemperatures(int[] temperatures)
{
    var answer = new int[temperatures.Length];
    var stack = new Stack<int>(); // indices, decreasing temperature

    for (int i = 0; i < temperatures.Length; i++)
    {
        while (stack.Count > 0 && temperatures[i] > temperatures[stack.Peek()])
        {
            var prevIndex = stack.Pop();
            answer[prevIndex] = i - prevIndex;
        }
        stack.Push(i);
    }
    return answer;
}
```

---

## 9. Stack for Matching/Parsing

**Recognize:** brackets/parentheses validity, expression evaluation (RPN), asteroid-collision-
style "cancel with previous" logic.

```csharp
public bool IsValidParentheses(string s)
{
    var pairs = new Dictionary<char, char> { [')'] = '(', [']'] = '[', ['}'] = '{' };
    var stack = new Stack<char>();

    foreach (var c in s)
    {
        if (!pairs.ContainsKey(c)) { stack.Push(c); continue; }
        if (stack.Count == 0 || stack.Pop() != pairs[c]) return false;
    }
    return stack.Count == 0;
}
```

---

## 10. Tree DFS (Recursive)

**Recognize:** depth, path sum, subtree comparisons, validating tree properties (BST, balance,
symmetry). Recursion naturally mirrors tree structure.

```csharp
public int MaxDepth(TreeNode root)
{
    if (root == null) return 0;
    return 1 + Math.Max(MaxDepth(root.left), MaxDepth(root.right));
}

// Passing state down + bounds (e.g. Validate BST)
public bool IsValidBst(TreeNode root) => IsValidBst(root, long.MinValue, long.MaxValue);

private static bool IsValidBst(TreeNode node, long lower, long upper)
{
    if (node == null) return true;
    if (node.val <= lower || node.val >= upper) return false;
    return IsValidBst(node.left, lower, node.val) && IsValidBst(node.right, node.val, upper);
}
```

Variant — accumulate a global best via an instance field while a helper returns local state
(e.g. Diameter of Binary Tree):

```csharp
private int _diameter;

public int DiameterOfBinaryTree(TreeNode root)
{
    _diameter = 0;
    Height(root);
    return _diameter;
}

private int Height(TreeNode node)
{
    if (node == null) return 0;
    var left = Height(node.left);
    var right = Height(node.right);
    _diameter = Math.Max(_diameter, left + right);
    return 1 + Math.Max(left, right);
}
```

---

## 11. Tree BFS (Level Order)

**Recognize:** "level order", per-level aggregation, right-side view, minimum depth via
shortest path.

```csharp
public IList<IList<int>> LevelOrder(TreeNode root)
{
    var result = new List<IList<int>>();
    if (root == null) return result;

    var queue = new Queue<TreeNode>();
    queue.Enqueue(root);

    while (queue.Count > 0)
    {
        int levelSize = queue.Count;
        var level = new List<int>();

        for (int i = 0; i < levelSize; i++)
        {
            var node = queue.Dequeue();
            level.Add(node.val);
            if (node.left != null) queue.Enqueue(node.left);
            if (node.right != null) queue.Enqueue(node.right);
        }
        result.Add(level);
    }
    return result;
}
```

---

## 12. Graph DFS (Grid/Adjacency)

**Recognize:** connected components, flood fill, island counting, "explore all reachable
cells/nodes". Mark visited to avoid infinite recursion.

```csharp
public int NumIslands(char[][] grid)
{
    int rows = grid.Length, cols = grid[0].Length, count = 0;

    for (int r = 0; r < rows; r++)
    for (int c = 0; c < cols; c++)
    {
        if (grid[r][c] == '1')
        {
            count++;
            Sink(grid, r, c);
        }
    }
    return count;
}

private static void Sink(char[][] grid, int r, int c)
{
    if (r < 0 || r >= grid.Length || c < 0 || c >= grid[0].Length || grid[r][c] != '1')
        return;

    grid[r][c] = '0'; // mark visited in place
    Sink(grid, r + 1, c);
    Sink(grid, r - 1, c);
    Sink(grid, r, c + 1);
    Sink(grid, r, c - 1);
}
```

---

## 13. Graph BFS (Shortest Path / Multi-source)

**Recognize:** shortest path in unweighted graph, "minimum steps/time", multi-source spread
(e.g. Rotting Oranges — start BFS from all sources simultaneously).

```csharp
public int RottingOranges(int[][] grid)
{
    int rows = grid.Length, cols = grid[0].Length, fresh = 0, minutes = 0;
    var queue = new Queue<(int r, int c)>();

    for (int r = 0; r < rows; r++)
    for (int c = 0; c < cols; c++)
    {
        if (grid[r][c] == 2) queue.Enqueue((r, c));
        else if (grid[r][c] == 1) fresh++;
    }

    int[][] directions = { new[] { 1, 0 }, new[] { -1, 0 }, new[] { 0, 1 }, new[] { 0, -1 } };

    while (queue.Count > 0 && fresh > 0)
    {
        int levelSize = queue.Count;
        for (int i = 0; i < levelSize; i++)
        {
            var (r, c) = queue.Dequeue();
            foreach (var d in directions)
            {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != 1) continue;
                grid[nr][nc] = 2;
                fresh--;
                queue.Enqueue((nr, nc));
            }
        }
        minutes++;
    }
    return fresh == 0 ? minutes : -1;
}
```

---

## 14. Topological Sort

**Recognize:** dependency ordering, "course schedule", detecting cycles in a directed graph.
Kahn's algorithm (BFS with in-degrees) shown below.

```csharp
public bool CanFinish(int numCourses, int[][] prerequisites)
{
    var adjacency = new List<int>[numCourses];
    var inDegree = new int[numCourses];
    for (int i = 0; i < numCourses; i++) adjacency[i] = new List<int>();

    foreach (var p in prerequisites)
    {
        adjacency[p[1]].Add(p[0]);
        inDegree[p[0]]++;
    }

    var queue = new Queue<int>();
    for (int i = 0; i < numCourses; i++)
        if (inDegree[i] == 0) queue.Enqueue(i);

    int visited = 0;
    while (queue.Count > 0)
    {
        var course = queue.Dequeue();
        visited++;
        foreach (var next in adjacency[course])
        {
            if (--inDegree[next] == 0) queue.Enqueue(next);
        }
    }
    return visited == numCourses; // false => cycle exists
}
```

---

## 15. Backtracking

**Recognize:** "all subsets/permutations/combinations", constraint satisfaction (N-Queens, word
search), generate all valid configurations. Choose → recurse → undo (unchoose).

```csharp
public IList<IList<int>> Subsets(int[] nums)
{
    var result = new List<IList<int>>();
    Backtrack(nums, 0, new List<int>(), result);
    return result;
}

private static void Backtrack(int[] nums, int start, List<int> current, List<IList<int>> result)
{
    result.Add(new List<int>(current)); // snapshot at every node

    for (int i = start; i < nums.Length; i++)
    {
        current.Add(nums[i]);           // choose
        Backtrack(nums, i + 1, current, result); // recurse
        current.RemoveAt(current.Count - 1);     // unchoose
    }
}
```

Variant — permutations (track used elements instead of a start index):

```csharp
public IList<IList<int>> Permute(int[] nums)
{
    var result = new List<IList<int>>();
    Backtrack(nums, new List<int>(), new bool[nums.Length], result);
    return result;
}

private static void Backtrack(int[] nums, List<int> current, bool[] used, List<IList<int>> result)
{
    if (current.Count == nums.Length)
    {
        result.Add(new List<int>(current));
        return;
    }

    for (int i = 0; i < nums.Length; i++)
    {
        if (used[i]) continue;
        used[i] = true;
        current.Add(nums[i]);
        Backtrack(nums, current, used, result);
        current.RemoveAt(current.Count - 1);
        used[i] = false;
    }
}
```

---

## 16. Dynamic Programming — 1D

**Recognize:** "number of ways", optimal value depending only on a small window of previous
states (climbing stairs, house robber, longest increasing subsequence).

```csharp
public int ClimbStairs(int n)
{
    if (n <= 2) return n;

    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++)
    {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
```

Variant — full DP array when transitions need more than the last two states (e.g. LIS):

```csharp
public int LengthOfLIS(int[] nums)
{
    var dp = new int[nums.Length];
    Array.Fill(dp, 1);
    int best = 1;

    for (int i = 1; i < nums.Length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i]) dp[i] = Math.Max(dp[i], dp[j] + 1);
        }
        best = Math.Max(best, dp[i]);
    }
    return best;
}
```

Variant — Kadane's algorithm (max/min subarray sum, running local-best vs. reset-and-restart):

```csharp
public int MaxSubArray(int[] nums)
{
    int best = nums[0], current = nums[0];

    for (int i = 1; i < nums.Length; i++)
    {
        current = Math.Max(nums[i], current + nums[i]); // extend or restart at i
        best = Math.Max(best, current);
    }
    return best;
}
```

Variant — top-down with memoization (natural when the recursive relation is easier to write
than the iterative fill order, e.g. House Robber, Word Break):

```csharp
private Dictionary<int, int> _memo = new();

public int RobTopDown(int[] nums) => Rob(nums, nums.Length - 1);

private int Rob(int[] nums, int i)
{
    if (i < 0) return 0;
    if (_memo.TryGetValue(i, out var cached)) return cached;

    var result = Math.Max(Rob(nums, i - 1), Rob(nums, i - 2) + nums[i]);
    return _memo[i] = result;
}
```

---

## 17. Dynamic Programming — 2D / Grid

**Recognize:** two strings/sequences compared (edit distance, LCS), grid path counting, states
indexed by two indices.

```csharp
public int UniquePaths(int rows, int cols)
{
    var dp = new int[rows, cols];
    for (int r = 0; r < rows; r++)
    for (int c = 0; c < cols; c++)
    {
        if (r == 0 || c == 0) dp[r, c] = 1;
        else dp[r, c] = dp[r - 1, c] + dp[r, c - 1];
    }
    return dp[rows - 1, cols - 1];
}

// Two-sequence DP (e.g. Longest Common Subsequence)
public int LongestCommonSubsequence(string a, string b)
{
    var dp = new int[a.Length + 1, b.Length + 1];
    for (int i = 1; i <= a.Length; i++)
    for (int j = 1; j <= b.Length; j++)
    {
        dp[i, j] = a[i - 1] == b[j - 1]
            ? dp[i - 1, j - 1] + 1
            : Math.Max(dp[i - 1, j], dp[i, j - 1]);
    }
    return dp[a.Length, b.Length];
}
```

---

## 18. Dynamic Programming — Knapsack

**Recognize:** "subset achieving exact sum/capacity", partition problems, coin change (bounded
vs. unbounded item usage). Iterate capacity backwards for 0/1, forwards for unbounded.

```csharp
// 0/1 knapsack: each item used at most once — iterate capacity DESCENDING
public bool CanPartition(int[] nums)
{
    int sum = nums.Sum();
    if (sum % 2 != 0) return false;

    int target = sum / 2;
    var dp = new bool[target + 1];
    dp[0] = true;

    foreach (var num in nums)
    {
        for (int cap = target; cap >= num; cap--)
        {
            dp[cap] = dp[cap] || dp[cap - num];
        }
    }
    return dp[target];
}

// Unbounded knapsack: items reusable — iterate capacity ASCENDING
public int CoinChange(int[] coins, int amount)
{
    var dp = new int[amount + 1];
    Array.Fill(dp, amount + 1);
    dp[0] = 0;

    for (int cap = 1; cap <= amount; cap++)
    {
        foreach (var coin in coins)
        {
            if (coin <= cap) dp[cap] = Math.Min(dp[cap], dp[cap - coin] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
```

---

## 19. Greedy / Intervals

**Recognize:** "maximize/minimize count of non-overlapping choices", merge/insert intervals.
Sort first (usually by start or end), then make locally optimal choices.

```csharp
public int[][] MergeIntervals(int[][] intervals)
{
    Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));

    var merged = new List<int[]>();
    foreach (var interval in intervals)
    {
        if (merged.Count == 0 || merged[^1][1] < interval[0])
        {
            merged.Add(interval);
        }
        else
        {
            merged[^1][1] = Math.Max(merged[^1][1], interval[1]);
        }
    }
    return merged.ToArray();
}

// Greedy by end time: max non-overlapping intervals
public int EraseOverlapIntervals(int[][] intervals)
{
    Array.Sort(intervals, (a, b) => a[1].CompareTo(b[1]));

    int removed = 0, lastEnd = int.MinValue;
    foreach (var interval in intervals)
    {
        if (interval[0] >= lastEnd) lastEnd = interval[1];
        else removed++;
    }
    return removed;
}
```

---

## 20. Heap / Priority Queue

**Recognize:** "top/kth largest/smallest", merge k sorted lists, running median, task
scheduling by priority. `PriorityQueue<TElement, TPriority>` is a min-heap by default.

```csharp
public int FindKthLargest(int[] nums, int k)
{
    var minHeap = new PriorityQueue<int, int>();

    foreach (var n in nums)
    {
        minHeap.Enqueue(n, n);
        if (minHeap.Count > k) minHeap.Dequeue();
    }
    return minHeap.Peek();
}

// Top-k frequent elements
public int[] TopKFrequent(int[] nums, int k)
{
    var counts = new Dictionary<int, int>();
    foreach (var n in nums) counts[n] = counts.GetValueOrDefault(n) + 1;

    var minHeap = new PriorityQueue<int, int>();
    foreach (var (num, freq) in counts)
    {
        minHeap.Enqueue(num, freq);
        if (minHeap.Count > k) minHeap.Dequeue();
    }
    return minHeap.UnorderedItems.Select(x => x.Element).ToArray();
}
```

Variant — two heaps for a running median (max-heap for the lower half, min-heap for the upper
half, keep sizes within 1 of each other):

```csharp
public class MedianFinder
{
    private readonly PriorityQueue<int, int> _lowerMax = new(Comparer<int>.Create((a, b) => b.CompareTo(a)));
    private readonly PriorityQueue<int, int> _upperMin = new();

    public void AddNum(int num)
    {
        _lowerMax.Enqueue(num, num);

        var moved = _lowerMax.Dequeue();      // keep every lower-half value <= every upper-half value
        _upperMin.Enqueue(moved, moved);

        if (_upperMin.Count > _lowerMax.Count)
        {
            var back = _upperMin.Dequeue();
            _lowerMax.Enqueue(back, back);
        }
    }

    public double FindMedian()
    {
        if (_lowerMax.Count > _upperMin.Count) return _lowerMax.Peek();
        return (_lowerMax.Peek() + _upperMin.Peek()) / 2.0;
    }
}
```

---

## 21. Union-Find (Disjoint Set)

**Recognize:** dynamic connectivity, "number of connected components", cycle detection in an
undirected graph, grouping under equivalence relations.

```csharp
public class UnionFind
{
    private readonly int[] _parent;
    private readonly int[] _rank;

    public UnionFind(int n)
    {
        _parent = Enumerable.Range(0, n).ToArray();
        _rank = new int[n];
    }

    public int Find(int x)
    {
        if (_parent[x] != x) _parent[x] = Find(_parent[x]); // path compression
        return _parent[x];
    }

    public bool Union(int a, int b)
    {
        int rootA = Find(a), rootB = Find(b);
        if (rootA == rootB) return false; // already connected => cycle if edge processed

        if (_rank[rootA] < _rank[rootB]) (rootA, rootB) = (rootB, rootA);
        _parent[rootB] = rootA;
        if (_rank[rootA] == _rank[rootB]) _rank[rootA]++;
        return true;
    }
}
```

---

## 22. Trie

**Recognize:** prefix search, autocomplete, "word search II" style problems combining trie
with backtracking on a grid.

```csharp
public class Trie
{
    private class TrieNode
    {
        public Dictionary<char, TrieNode> Children { get; } = new();
        public bool IsWord { get; set; }
    }

    private readonly TrieNode _root = new();

    public void Insert(string word)
    {
        var node = _root;
        foreach (var c in word)
        {
            if (!node.Children.TryGetValue(c, out var next))
                node.Children[c] = next = new TrieNode();
            node = next;
        }
        node.IsWord = true;
    }

    public bool Search(string word) => Find(word)?.IsWord ?? false;

    public bool StartsWith(string prefix) => Find(prefix) != null;

    private TrieNode Find(string s)
    {
        var node = _root;
        foreach (var c in s)
        {
            if (!node.Children.TryGetValue(c, out var next)) return null;
            node = next;
        }
        return node;
    }
}
```

---

## 23. Linked List Reversal

**Recognize:** "reverse a linked list" (whole or sublist), palindrome check on a list,
reordering nodes. Track three pointers: previous, current, next.

```csharp
public ListNode ReverseList(ListNode head)
{
    ListNode prev = null;
    var current = head;

    while (current != null)
    {
        var next = current.next;
        current.next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
```

---

## 24. Bit Manipulation

**Recognize:** "single number" (XOR cancels pairs), counting set bits, subset generation via
bitmask, power-of-two checks.

```csharp
public int SingleNumber(int[] nums)
{
    int result = 0;
    foreach (var n in nums) result ^= n; // pairs cancel out, one remains
    return result;
}

public int HammingWeight(uint n)
{
    int count = 0;
    while (n != 0)
    {
        n &= n - 1; // clears the lowest set bit
        count++;
    }
    return count;
}

// Enumerate all subsets of a set of size n via bitmask
public void EnumerateSubsets(int n)
{
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                // element i is included in this subset
            }
        }
    }
}
```

---

## 25. Matrix Traversal

**Recognize:** "rotate the image", "spiral order", diagonal traversal, transpose — problems that
manipulate a 2D grid's layout rather than search it (contrast with Graph DFS/BFS, §12–13).

```csharp
public IList<int> SpiralOrder(int[][] matrix)
{
    var result = new List<int>();
    int top = 0, bottom = matrix.Length - 1, left = 0, right = matrix[0].Length - 1;

    while (top <= bottom && left <= right)
    {
        for (int c = left; c <= right; c++) result.Add(matrix[top][c]);
        top++;
        for (int r = top; r <= bottom; r++) result.Add(matrix[r][right]);
        right--;
        if (top <= bottom)
        {
            for (int c = right; c >= left; c--) result.Add(matrix[bottom][c]);
            bottom--;
        }
        if (left <= right)
        {
            for (int r = bottom; r >= top; r--) result.Add(matrix[r][left]);
            left++;
        }
    }
    return result;
}

// Rotate n x n matrix 90 degrees clockwise in place: transpose, then reverse each row
public void Rotate(int[][] matrix)
{
    int n = matrix.Length;
    for (int r = 0; r < n; r++)
    for (int c = r + 1; c < n; c++)
    {
        (matrix[r][c], matrix[c][r]) = (matrix[c][r], matrix[r][c]);
    }
    foreach (var row in matrix) Array.Reverse(row);
}
```

---

## 26. Design — Hash Map + Doubly Linked List (LRU Cache)

**Recognize:** "design a data structure that supports O(1) X and Y" where one operation needs
fast lookup (hash map) and the other needs fast reordering/eviction (doubly linked list). Classic
for LRU Cache; the same shape reappears for LFU Cache and browser history.

```csharp
public class LRUCache
{
    private class Node
    {
        public int Key, Value;
        public Node Prev, Next;
    }

    private readonly int _capacity;
    private readonly Dictionary<int, Node> _map = new();
    private readonly Node _head = new(); // dummy, head.Next = most recently used
    private readonly Node _tail = new(); // dummy, tail.Prev = least recently used

    public LRUCache(int capacity)
    {
        _capacity = capacity;
        _head.Next = _tail;
        _tail.Prev = _head;
    }

    public int Get(int key)
    {
        if (!_map.TryGetValue(key, out var node)) return -1;
        MoveToFront(node);
        return node.Value;
    }

    public void Put(int key, int value)
    {
        if (_map.TryGetValue(key, out var node))
        {
            node.Value = value;
            MoveToFront(node);
            return;
        }

        if (_map.Count == _capacity)
        {
            var lru = _tail.Prev;
            Remove(lru);
            _map.Remove(lru.Key);
        }

        var fresh = new Node { Key = key, Value = value };
        _map[key] = fresh;
        AddToFront(fresh);
    }

    private void MoveToFront(Node node) { Remove(node); AddToFront(node); }

    private void Remove(Node node)
    {
        node.Prev.Next = node.Next;
        node.Next.Prev = node.Prev;
    }

    private void AddToFront(Node node)
    {
        node.Next = _head.Next;
        node.Prev = _head;
        _head.Next.Prev = node;
        _head.Next = node;
    }
}
```

---

## Quick Pattern-Recognition Index

| Signal in the problem statement | Likely pattern |
|---|---|
| Sorted array, pair/triplet sum | Two Pointers (§1) |
| "Longest/shortest contiguous substring/subarray" | Sliding Window (§2) |
| Cycle in linked list, middle node | Fast & Slow Pointers (§3) |
| Sorted array, find index in O(log n) | Binary Search (§4) |
| "Minimize the maximum" / feasibility check | Binary Search on Answer (§5) |
| Repeated range-sum queries | Prefix Sum (§6) |
| Anagrams, duplicates, grouping | Hash Map (§7) |
| "Next greater/smaller element" | Monotonic Stack (§8) |
| Balanced brackets, expression eval | Stack (§9) |
| Tree property / path / depth | Tree DFS (§10) |
| Tree "level order" / right-side view | Tree BFS (§11) |
| Islands, connected components, flood fill | Graph DFS (§12) |
| Shortest path unweighted, multi-source spread | Graph BFS (§13) |
| Course prerequisites, build order | Topological Sort (§14) |
| "All subsets/permutations/combinations" | Backtracking (§15) |
| "Number of ways", optimal value, small state | DP 1D (§16) |
| Two strings/sequences compared, grid paths | DP 2D (§17) |
| "Subset sums to X", coin change | DP Knapsack (§18) |
| Merge/insert intervals, max non-overlap | Greedy / Intervals (§19) |
| "Top/kth largest", merge k sorted | Heap (§20) |
| Dynamic connectivity, cycle in undirected graph | Union-Find (§21) |
| Prefix search, autocomplete | Trie (§22) |
| "Reverse a linked list" | Linked List Reversal (§23) |
| "Single number", set bits, bitmask subsets | Bit Manipulation (§24) |
| "Rotate matrix", "spiral order", grid layout manipulation | Matrix Traversal (§25) |
| "Design a data structure with O(1) get/put and eviction" | Design — LRU Cache (§26) |
