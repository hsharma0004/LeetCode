#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  unordered_map<int, list<pair<int, int>>> adj;
  void AddEdge(int u, int v, int weight)
  {
    pair<int, int> p = make_pair(v, weight);
    adj[u].push_back(p);
  }

  void printAdj()
  {
    for (auto i : adj)
    {
      cout << i.first << " -> ";
      for (auto j : i.second)
      {
        cout << "(" << j.first << "," << j.second << "), ";
      }
      cout << endl;
    }
  }

  void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
  {
    visited[node] = 1;
    for (auto nei : adj[node])
    {
      if (!visited[nei.first])
      {
        dfs(nei.first, visited, s);
      }
    }
    s.push(node);
  }

  void getShortestrPath(int src, vector<int> &dist, stack<int> &s)
  {
    dist[src] = 0;
    while (!s.empty())
    {
      int top = s.top();
      s.pop();

      if (dist[top] != INT_MAX)
      {
        for (auto i : adj[top])
        {
          if (dist[top] + i.second < dist[i.first])
          {
            dist[i.first] = dist[top] + i.second;
          }
        }
      }
    }
  }
};

int main()
{
  Graph g;
  g.AddEdge(0, 1, 5);
  g.AddEdge(0, 2, 3);
  g.AddEdge(1, 2, 2);
  g.AddEdge(1, 3, 6);
  g.AddEdge(2, 3, 7);
  g.AddEdge(2, 4, 4);
  g.AddEdge(2, 5, 2);
  g.AddEdge(3, 4, -1);
  g.AddEdge(4, 5, -2);

  g.printAdj();
  int n = 6;
  // Topological Sort
  unordered_map<int, bool> visited;
  stack<int> s;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      g.dfs(i, visited, s);
    }
  }
  int src = 1;
  vector<int> dist(n);
  for (int i = 0; i < n; i++)
    dist[i] = INT_MAX;

  g.getShortestrPath(src, dist, s);

  cout << "Answer is : " << endl;

  for (int i = 0; i < dist.size(); i++)
  {
    cout << dist[i] << " ";
  }
  cout << endl;
}