#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n, soma, temp;
  cin >> n;
  soma = 0;
  for (ll i=0; i<n;i++){
    cin >> temp;
    if(temp > 10)
      soma += temp-10;
  }
  cout << soma << "\n";

}
