#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int L = 1e4+15, R = 1e4+15;
vector<vector<int>> g (L);
vector<int> matchr (R, -1);
int cts = 1;
vector<int> vis (L);

int dfs(int u) {
  if (vis[u] == cts) return 0;
  vis[u] = cts;
  for (int v : g[u])
    if (matchr[v] == -1 || dfs(matchr[v])) {
      matchr[v] = u; return 1;
    }

  return 0;
}

int kuhn(int l) {
  int ans = 0;
  for (int u = 0; u < l; u++) {
    ans += dfs(u);
    cts++;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v; u--; v--;
    g[u].push_back(v);
  }

  printf("%d\n",kuhn(n));

  // for (int u = 0; u < n-1; u++)
  //   if (matchr[u] != -1)
  //     printf("%d %d\n",matchr[u]+1,u+1);
}
