#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned ll;

int main() {
  ll a, b, n;
  cin >> a >> b >> n;

  vector<ll> primos;
  for (ll i=0; i < n; i++){
    ll temp;
    cin >> temp;
    primos.push_back(temp);
  }

  bitset<16>curset (1);
  ll soma = 0;
  for (curset = 0b1; curset != 0b1 << n ; curset = curset.to_ulong() + 1){
    ll curprime = 1;
    for (int i = 0; i < n; i++)
      if (curset[i] == 1)
        curprime *= primos[i];
    ll sign = (2 * (curset.count() % 2)) -1;
    ll amount =(b/curprime) - ((a-1)/curprime);
    //cout << "multiplos de " << curprime << " entre " << a << " e " << b << ": " << amount << endl;
    soma += sign*(amount);
  }

  cout << (b-a+1) - soma << "\n";

}
