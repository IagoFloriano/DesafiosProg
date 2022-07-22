#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll oo=1987654321987654321;

int main() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> grafo(n, vector<ll>(n,oo));
  for(ll i = 0; i < m; i++){
    ll u, v, w;
    cin >> u >> v >> w;
    grafo[u][v] = w;
    grafo[v][u] = w;
  }
  for(ll i = 0; i < n; i++)
    grafo[i][i] = 0;

  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      for(ll k = 0; k < n; k++)
        grafo[j][k] = min(grafo[j][k], grafo[j][i] + grafo[i][k]);

  vector<ll> maiores(n);
  for(ll i=0;i<n;i++)
    maiores[i] = *max_element(grafo[i].begin(), grafo[i].end());

  cout << *min_element(maiores.begin(), maiores.end())<< "\n";

}
