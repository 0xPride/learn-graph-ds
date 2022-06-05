# Breadth First Search

Breadth first search is one of the basic searching algorithm on graphs

The algorithm work on O(n + m) where n is the number of vertices and m is the number of edges

The algorithm will take unweighted graph and a source vertex id (s)

## steps

- create a queue q which contain the vertices to be processed
- create boolean array used[] which indicate each vertex if it is visited
- push the source (s) to the queue (q) and set used[s]=true
- set all used[v] = false (source vertex will have a edges to other vertices)
- loop on the queue and dequeue a vertex
- loop on all that vertex edges and if any edge is not visited (used[v]) then visit them and enqueue that edge

## Pseudocode
```
procedure BFS(G, root) is
     let Q be a queue
     label root as explored
     Q.enqueue(root)
     while Q is not empty do
         v := Q.dequeue()
         if v is the goal then
             return v
         for all edges from v to w in G.adjacentEdges(v) do
             if w is not labeled as explored then
                 label w as explored
                 Q.enqueue(w)
```

## C++
```
vector<vector<int>> adj;  // adjacency list representation
int n; // number of nodes
int s; // source vertex

queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);

q.push(s);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}
```
# Problems

- [ ] [SPOJ: AKBAR](http://spoj.com/problems/AKBAR)
- [ ] [SPOJ: NAKANJ](http://www.spoj.com/problems/NAKANJ)
- [ ] [SPOJ: WATER](http://www.spoj.com/problems/WATER)
