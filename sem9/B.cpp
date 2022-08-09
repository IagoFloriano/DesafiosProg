#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using edges=vector<int>;
using vertice=pair<int, edges>;

vector<int> explored;
vector<int> ammount;
int counting;
vector<vertice> g;

void dfs(int u){
  explored[u] = 1;
  edges e = g[u].second;
  for(int n: e){
    if(explored[n]) continue ;

    if(ammount[n] == 1) counting++;
    ammount[n]++;
    dfs(n);
  }
}

int main() {
  ll n, m;
  cin >> n >> m;
  counting = 0;
  g = vector<vertice>(n);
  ammount = vector<int>(n,0);

  while(m--){
    ll u, v;
    cin >> u >> v;
    u--; v--;
    g[v].first++;
    g[u].second.push_back(v);
  }

  // printf("GRAFO:\n");
  // for(int i = 0; i < n; i++){
  //   printf("%d(%d):",i,g[i].first);
  //   for(auto j: g[i].second)
  //     printf("\t%d",j);
  //   printf("\n");
  // }

  for(int i = 0; i < n; i++){
    if (g[i].first) continue;
    explored = vector<int>(n,0);
    dfs(i);
  }

  printf("%d\n",counting);
}
