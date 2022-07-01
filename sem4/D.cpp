#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll t;
  cin >> t;
  for(ll i=1; i<=t; i++){
    ll quant = 0;
    string corredor;
    cin >> corredor;
    
    for (ll j=1;j<corredor.length();j++){
      if (corredor[j-1] != '#'){
        quant++;
        j+=2;
      }
    }
    
    cout << "Caso " << i << ": " << quant << "\n";
  }

}
