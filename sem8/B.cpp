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

int main() {
  ll T;
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
    vector<pair<ll,ll>>fatores(0);
    for(ll i = 2; i*i <= n; i++){
      if(n % i == 0){
        ll count = 0;
        while (n % i == 0){
          count++;
          n = n/i;
        }
        fatores.push_back(make_pair(i,count));
      }
    }
    if(n>1) fatores.push_back(make_pair(n,1));
    for(ll i = fatores.size() - 1; i >= 0; i--){
      printf("%d %d\n",fatores[i].first,fatores[i].second); 
    }
  }

}
