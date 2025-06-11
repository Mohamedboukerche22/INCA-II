# 📚 Competitive Programming Snippets in C++

This repository contains simple explanations and small implementations of core algorithms and data structures in C++ commonly used in competitive programming.

---

## 🧮 1. Prefix Sums

**Definition**: Prefix Sum is a technique to preprocess an array so that sum queries on any subarray can be answered in constant time.

### ✅ Time Complexity

* Preprocessing: `O(n)`
* Query: `O(1)`

### 🧩 Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + a[i];

    // Sum from index 1 to 3 (2+3+4 = 9)
    cout << "Sum(1..3): " << prefix[4] - prefix[1] << endl;
}
```

---

---

## 🌐 3. BFS (Breadth-First Search)

**Definition**: BFS is a graph traversal algorithm that explores all neighbors at the current depth before moving deeper.

### 💡 Use Case: Shortest path in unweighted graphs

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

---

## 🌲 4. DFS (Depth-First Search)

**Definition**: DFS is a graph traversal technique that explores as far as possible along a branch before backtracking.

```cpp
#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}
```

---

## 🔗 5. DSU (Disjoint Set Union)

**Definition**: DSU is a data structure that keeps track of elements partitioned into disjoint sets. Useful in Kruskal's algorithm, connected components, etc.

### 🚀 Features

* `find(u)` returns representative of the set of u
* `unite(u, v)` merges the sets of u and v

### 🛠️ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
```

---

## 🧠 Contribution

Feel free to fork and contribute more snippets!

---
