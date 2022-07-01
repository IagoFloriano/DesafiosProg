#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  vector<ll> moedas = {1,5,10,25,50};
  ll valor;

  while (cin >> valor){
    ll formas = 1;
    for (ll i = 1; i < 5; i++){
      if (valor < moedas[i])
        break;
      
      formas += valor / moedas[i];
    }
    cout << formas << "\n";
  }
}
