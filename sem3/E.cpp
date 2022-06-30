#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n, k;
  cin >> n >> k;
  ll max = 0;

  deque<ll> vetor;
  
  for (ll i = 0; i < n; i++){
    ll temp;
    cin >> temp;
    vetor.push_back(temp);
  }

  map<ll, ll> contagem;

  for (ll i = 0; i < k; i++){
    ll tempi = vetor[i];
    
    if(contagem.count(tempi)){
      contagem[tempi]++;
    } else
      contagem[tempi] = 1;

    if (contagem[tempi] > max)
      max = contagem[tempi];
  }

  for (ll i = k; i < n; i++){
    ll tempi = vetor[i];
    
    if(contagem.count(tempi)){
      contagem[tempi]++;
    } else
      contagem[tempi] = 1;

    ll tempr = vetor[i-k];
    contagem[tempr]--;

    if (contagem[tempi] > max)
      max = contagem[tempi];
  }
  cout << max << "\n";
}
