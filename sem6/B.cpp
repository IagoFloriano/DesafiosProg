#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<ll> distancias;

void busca(vector<pair <int, vector<ll>>>& grafo, ll vertice){
  for(auto i: grafo[vertice].second){
    ll dist = distancias[vertice] + grafo[i].first - grafo[vertice].first;
    if(dist < distancias[i]){
      distancias[i] = dist;
      busca(grafo, i);
    }
  }
}

int main() {
  ll N, M, Q;
  cin >> N;

  vector<pair <int, vector<ll>>> grafo = vector<pair <int, vector<ll>>>(N+1,make_pair(0,vector<ll>(0)));
  distancias = vector<ll>(N+1,1123456789);

  grafo[0].first = 9000;
  for(ll i = 1; i < N+1; i++){
    cin >> grafo[i].first;
  }
  cin >> M;

  for(ll i = 1; i <= M; i++){
    ll a, b;
    cin >> a >> b;
    grafo[a].second.push_back(b);
  }

  cin >> Q;

  distancias[1] = 0;
  busca(grafo, 1);
  //for(ll i = 1; i <= N; i++)
  //  cout << distancias[i] << " ";
  //cout << endl;
  for(ll i = 0; i < Q; i++){
    ll temp;
    cin >> temp;
    ll dist = distancias[temp];
    cout << (dist < 3 || dist == 1123456789? "Não, Edsger..." : to_string(dist)) << "\n";
  }

}
