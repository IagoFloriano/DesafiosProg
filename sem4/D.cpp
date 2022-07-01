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
    
    //cout << corredor << endl;
    for (ll j=1;j<=corredor.length();){
      if (corredor[j-1] != '#'){
        quant++;
        corredor[j-1] = '#';
        if(j+1<corredor.length())corredor[j+1] = '#';
        if(j<corredor.length())corredor[j] = '#';
      }
      j++;
      //cout << corredor << endl;
    }
    
    cout << "Caso " << i << ": " << quant << "\n";
  }

}
