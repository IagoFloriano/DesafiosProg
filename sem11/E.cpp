#include <bits/stdc++.h>
using namespace std; using ii = pair<int, int>;
const int N = 1e5+15, B = ceil(sqrt(N));
#define NEUTRAL 0
#define OP(X, Y) max(X, Y)
vector<vector<ii>> g (N);
vector<int> depth (N);
vector<int> up (N); vector<int> weiop (N);
vector<int> bup (N); vector<int> bweiop (N);

void stdt_decompose(int u, int p, int w) {
  //printf("stdt_decompose(%d, %d, %d)\n",u,p,w);
  up[u] = p; weiop[u] = w;
  depth[u] = depth[p] + 1;
  bup[u] = depth[u] % B ? bup[p] : p;
  for (auto [v, w] : g[u]) if (v != p)
    stdt_decompose(v, u, w);
}

int std_lca(int a, int b) {
  if (!(depth[a]/B > depth[b]/B)) { swap(a, b); }
  while (depth[a]/B > depth[b]/B) { a = bup[a]; }
  if (!(depth[a] > depth[b])) { swap(a, b); }
  while (depth[a] > depth[b]) { a = up[a]; }
  while (a != b) { a = up[a]; b = up[b]; }
  return a;
}

int stdt_op(int a, int b) {
  int ans = NEUTRAL;
  if (!(depth[a]/B > depth[b]/B)) { swap(a, b); }
  while (depth[a]/B > depth[b]/B) {
    ans = OP(ans, bweiop[a]); a = bup[a]; }
  if (!(depth[a] > depth[b])) { swap(a, b); }
  while (depth[a] > depth[b]) {
    ans = OP(ans, weiop[a]); a = up[a]; }
  while (a != b) {
    ans = OP(ans, OP(weiop[a], weiop[b]));
    a = up[a]; b = up[b];
  }
  return ans;
}

int main() {
  int n; cin >> n;
  int m = n;
  vector<ii>lookup(n, ii(-1,-1));
  int curr = 0;
  while(m--){
    int u; cin >> u; u--;
    if(lookup[u].first == -1) lookup[u].first = curr++;
    else lookup[u].second = curr++;
  }
  // printf("Vetor:");
  // for(int i = 0; i < n/2; i++)
  //   printf("\t(%d,%d)", lookup[i].first, lookup[i].second);
  // printf("\n");
  m = n-1;
  while(m--){
    int u, v; cin >> u >> v; u--; v--;
    g[u].push_back(ii(v,1));
    g[v].push_back(ii(u,1));
  }
  // printf("GARFO:\n");
  // for(int i = 0; i < n; i++){
  //   printf("%d:", i);
  //   for(ii j: g[i])
  //     printf("\t%d",j.first);
  //   printf("\n");
  // }
  stdt_decompose(0, 0, 0);
  int ans = 0;
  // printf("PROFUNDO:\n");
  // for(int i = 0; i < n/2; i++){
  //   printf("%d[%d]\n", i, depth[i]);
  // }
  for(int i = 0; i < n/2; i++){
    int p = lookup[i].first, s = lookup[i].second;
    //printf("dist(%d,%d): %d\n",p,s,depth[p] + depth[s] -(2*depth[std_lca(p, s)]));
    ans += depth[p] + depth[s] -(2*depth[std_lca(p, s)]);
  }
  printf("%d\n",ans);
}
