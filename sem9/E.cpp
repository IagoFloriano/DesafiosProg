#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
using ii = pair<int, int>;

int tk = 0;
vector<int> tin (N, -1), low (N);
vector<ii> brid;
set<int> arti;
vector<vector<int>> g;

void dfs(int u, int p) {
  tin[u] = low[u] = tk++;
  int ch = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    else if (tin[v] == -1) {
      dfs(v, u); ch++;
      if ((low[v] >= tin[u] && p != u) ||
          (ch >= 2 && p == u))
        arti.insert(u);
      if (low[v] > tin[u])
        brid.push_back(ii(u, v));
      low[u] = min(low[u], low[v]);
    } else { low[u] = min(low[u], tin[v]); }
  }
}
int main() {
  int t, n, m;
  cin >> t;
  while(t--){
    cin >> n >> m;
    g = vector<vector<int>>(n);

    while(m--){
      int u, v;
      cin >> u >> v; u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    //printf("GRAFO:\n");
    //for(int i = 0; i < n; i++){
    //  printf("%d:",i);
    //  for(auto j: g[i])
    //    printf("\t%d",j);
    //  printf("\n");
    //}

    brid.clear();
    arti.clear();
    tin = vector<int>(N,-1);
    low = vector<int>(n);
    tk = 0;
    for(int u = 0; u < n; u++) dfs(u, u);

    //printf("PONTES:\n");
    //for(auto i: brid)
    //  printf("%d->%d\t",i.first,i.second);
    //printf("\n");

    printf("%d\n", arti.size());
  }
}
