#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll oo=1987654321987654321;

int main() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> grafo(n, vector<ll>(n,oo));
  map<string, ll> chaves;
  vector<string> nomes(n);
  ll lastchave = 0;
  for(ll i = 0; i < m; i++){
    string a, b;
    cin >> a >> b;
    if(chaves.find(a) == chaves.end()){
      chaves[a] = lastchave;
      nomes[lastchave++] = a;
    }
    if(chaves.find(b) == chaves.end()){
      chaves[b] = lastchave;
      nomes[lastchave++] = b;
    }
    grafo[chaves[b]][chaves[a]] = 1;
    grafo[chaves[a]][chaves[b]] = 1;
  }
  for(ll i = 0; i < n; i++)
    grafo[i][i] = 0;

  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      for(ll k = 0; k < n; k++)
        grafo[j][k] = min(grafo[j][k], grafo[j][i] + grafo[i][k]);

  //for(ll i = 0; i < n; i++)
  //  cout << i << " : " << nomes[i] << "\n";
  //cout << endl;

  //for(ll i = 0; i < n; i++){
  //  for(ll j = 0; j < n; j++)
  //    cout << grafo[i][j] << " ";
  //  cout << endl;
  //}

  ll soma = 0;
  vector<tuple<int, int, int>> distancias;
  for(ll i = 0; i < n; i++){
    for(ll j = i+1; j < n; j++){
      soma += grafo[i][j];
      distancias.push_back(make_tuple((int)grafo[i][j],i,j));
    }
  }

  sort(distancias.begin(), distancias.end());
  cout << (double)soma/distancias.size() << "\n";
  int destino = get<2>(distancias[(distancias.size()/2)-1]);
  int inicio  = get<1>(distancias[(distancias.size()/2)-1]);
  while(inicio != destino){
    cout << nomes[inicio] << " ";
    for(int i = 0; i < n; i++){
      if(grafo[inicio][destino] == 1){
        inicio = destino;
        break;
      }
      if(i == inicio || i == destino) continue;
      if(grafo[inicio][i] + grafo[i][destino] == grafo[inicio][destino]){
        inicio = i;
        break;
      }
    }
  }
  cout << nomes[destino] << "\n";
}
