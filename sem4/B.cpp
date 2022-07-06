#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  ll valor;
  vector<ll> moedas = {1,5,10,25,50};
  vector<ll> formas = {1,2,4,13,50};

  while (cin >> valor){
    ll quant = 0;
    ll lcoin = 4;
    while(valor > 0){
      if (valor < moedas[lcoin]){
        lcoin--;
      }
      else {
        quant += formas[lcoin];
        valor -= moedas[lcoin];
      }
      cout << "Valor: " << valor << "\tQuant: " << quant << endl;
    }
    cout << quant << "\n";
  }
}
