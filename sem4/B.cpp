#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<ll> moedas = {1,5,10,25,50};

vector<vector<ll>> lookup;

ll formas(ll n, ll lcoin){
  ll quant = 0;
  if(lcoin < 0 || n < 0) return 0;
  if(lookup[lcoin][n] != 0) return lookup[lcoin][n];
  if(n == 0){
    lookup[lcoin][0] = 1;
    return 1;
  }
  quant += formas(n, lcoin-1);
  quant += formas(n - moedas[lcoin], lcoin);
  return quant;
}

int main() {
  ll valor;
  for(int i=0; i<5; i++){
    vector<ll> temp (3 * (ll)1e4);
    lookup.push_back(temp);
  }

  while (cin >> valor){
    cout << formas(valor,4) << "\n";
  }
}
