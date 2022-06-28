#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> vetor;

  for (ll i = 0; i < n; i++){
    ll temp;
    cin >> temp;
    vetor.push_back(temp);
  }

  ll gmax = 0;
  deque<ll> janela;

  map<ll, ll> conjunto;
  conjunto[0] = 1;
  janela.push_back(0);
  for (ll i = 0; i < k -1; i++){
    janela.push_back(vetor[i]);
    map<ll, ll>::iterator it = conjunto.find(vetor[i]);
    if (it == conjunto.end())
      conjunto[vetor[i]] = 1;
    else
      it->second++;
  }

  for (ll i = k-1; i < n; i++){
    janela.push_back(vetor[i]);
    map<ll, ll>::iterator it = conjunto.find(vetor[i]);
    if (it == conjunto.end())
      conjunto[vetor[i]] = 1;
    else
      it->second++;

    (conjunto[janela[0]])--;
    janela.pop_front();

    it = conjunto.end();
    it--;
    if (gmax < it->second){
      gmax = it->second;
    }
  }

  cout << gmax << "\n";


}
