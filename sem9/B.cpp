#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using edges=vector<int>;
using vertice=pair<int, edges>;

vector<int> explored;
vector<int> ammount;
int counting;
vector<vertice> g;

void dfs(int u, int exp){
  explored[u] = exp;
  edges e = g[u].second;
  for(int n: e){
    if(explored[n] == exp) continue ;

    if(ammount[n] == 1) counting++;
    if(ammount[n] == 2) continue;
    ammount[n]++;
    dfs(n,exp);
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

  //printf("GRAFO:\n");
  //for(int i = 0; i < n; i++){
  //  printf("%d(%d):",i,g[i].first);
  //  for(auto j: g[i].second)
  //    printf("\t%d",j);
  //  printf("\n");
  //}

  explored = vector<int>(n,0);
  for(int i = 0; i < n; i++){
    if (g[i].first) continue;
    dfs(i,i+1);
  }

  printf("%d\n",counting);
}
