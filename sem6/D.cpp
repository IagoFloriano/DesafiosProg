#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll oo=500;

vector<string> nomes;

bool cmpqTuple(tuple<int, int, int> a, tuple<int, int, int>b){
  if(get<0>(a) == get<0>(b)){
    if(get<1>(a) == get<1>(b))
      return nomes[get<2>(a)].compare(nomes[get<2>(b)]) < 0;
    return nomes[get<1>(a)].compare(nomes[get<1>(b)]) < 0;
  }
  return get<0>(a) < get<0>(b);
}

int main() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> grafo(n, vector<ll>(n,oo));
  vector<vector<ll>> next(n, vector<ll>(n,-1));
  map<string, ll> chaves;
  nomes = vector<string>(n);
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
    grafo[chaves[a]][chaves[b]] = 1;
    next[chaves[a]][chaves[b]] = chaves[b];
  }
  for(ll i = 0; i < n; i++){
    grafo[i][i] = 0;
    next[i][i] = i;
  }

  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      for(ll k = 0; k < n; k++)
        if(grafo[j][i] + grafo[i][k] < grafo[j][k]){
          grafo[j][k] = grafo[j][i] + grafo[i][k];
          next[j][k] = next[j][i];
        }

  //for(ll i = 0; i < n; i++)
  //  cout << i << " : " << nomes[i] << "\n";
  //cout << endl;

  //for(ll i = 0; i < n; i++){
  //  for(ll j = 0; j < n; j++)
  //    cout << grafo[i][j] << " ";
  //  cout << endl;
  //}

  ll soma = 0;
  vector<tuple<int, string, string>> distancias;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      if(grafo[i][j] != 0 && grafo[i][j] != oo){
        soma += grafo[i][j];
        distancias.push_back(make_tuple((int)grafo[i][j],nomes[i],nomes[j]));
      }
    }
  }

  sort(distancias.begin(), distancias.end());
  cout << (double)soma/distancias.size() << "\n";
  string destinos = get<2>(distancias[ceil((double)distancias.size()/2)-1]);
  string inicios  = get<1>(distancias[ceil((double)distancias.size()/2)-1]);
  int dest = chaves[destinos];
  int ini = chaves[inicios];
  while(ini != dest){
    cout << nomes[ini] << " ";
    ini = next[ini][dest];
  }
  cout << destinos << "\n";
}
