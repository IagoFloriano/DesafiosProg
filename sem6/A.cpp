#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void busca(vector<pair <int, vector<ll>>>& grafo, ll vertice, ll componente){
  if(grafo[vertice].first != 0) return;
  grafo[vertice].first = componente;
  for(auto next: grafo[vertice].second){
    busca(grafo, next, componente);
  }
}

int main() {
  ll N, M;
  cin >> N >> M;

  vector<pair <int, vector<ll>>> grafo = vector<pair <int, vector<ll>>>(N,make_pair(0,vector<ll>(0)));
  
  for(ll i = 0; i < M; i++){
    ll a, b;
    cin >> a >> b;
    grafo[a].second.push_back(b);
    grafo[b].second.push_back(a);
  }

  ll numcomponentes = 0;
  for (ll i = 0; i < N; i++){
    if(grafo[i].first == 0){
      numcomponentes++;
      busca(grafo, i, numcomponentes);
    }
  }
  cout << numcomponentes << "\n";

}
