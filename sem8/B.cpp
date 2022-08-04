#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll fast_pow(ll a, ll b){
  if (b == 0) return 1;
  ll temp = fast_pow(a, b/2);
  ll rvalue = temp * temp;
  if (b % 2 == 1)
    rvalue = a * rvalue;
  return rvalue;
}

vector<bool> sieve(1e7+15,true);
void eratosthenes(ll n){
  for(ll i = 2; i*i <= n; i++)
    if(sieve[i])
      for(ll j = i*i; j <= n; j+=i)
        sieve[j] = false;
}

int main() {
  ll T;
  sieve[0] = sieve[1] = false;
  eratosthenes(1e7+15);
  cin >> T;
  while(T--){
    //calcular numero pra fatorizar
    ll k, n, p, e;
    cin >> k;
    n = 1;
    while(k--){
      cin >> p >> e;
      n *= fast_pow(p, e);
    }
    n--;

    //fatorizar
    for(ll i = n; i >= 2; i--){
      if(sieve[i] && n % i == 0){
        ll count = 0;
        while (n % i == 0){
          count++;
          n = n/i;
        }
        printf("%d %d\n", i, count);
        i = n+1;
      }
    }
  }

}
