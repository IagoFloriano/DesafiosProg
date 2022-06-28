#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n;
  cin >> n;

  vector<bool> primos;
  primos.resize(n, true);
  primos[0] = primos[1] = false;

  for (ll i = 2; i*i < primos.size(); i++)
    if (primos[i])
      for (ll j = i*i; j < primos.size(); j+=i)
        primos[j] = false;

  ll count = 0;
  for (ll i = 2; i*2 <= primos.size(); i++){
    if (primos[i]){
      if (primos[n-i]) count++;
    }
  }

  cout << count << "\n";

}
