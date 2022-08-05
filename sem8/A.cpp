#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vll=vector<long long>;

ll extgcd /* O(lg min(a, b)) */ (ll a, ll b, ll& x, ll& y) {
  if (b == 0){
    x = 1;
    y = 0;
    return a;
  }
  ll g = extgcd(b, a%b, x, y);
  tie(x, y) = make_tuple(y, x - (a/b)*y);
  return g;
}

ll inv(ll a, ll m) {
  ll x, y;
  extgcd(a, m, x, y);
  return ((x % m) + m) % m;
}

ll crt(map<ll,ll>am, int t) {
  ll p = 1;
  for (map<ll,ll>::iterator it = am.begin(); it != am.end(); it++) {
    p *= it->first;
  }
  ll ans = 0;
  
  for (map<ll,ll>::iterator it = am.begin(); it != am.end(); it++) {
    ll tempni = (p/it->first) % p;
    ll tempbi = (it->second) % p;
    ll tempxi = inv(tempni, it->first) % p;
    ans = (ans + (tempni*tempbi*tempxi) % p) % p;
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  map<ll,ll>am;
  map<ll,ll>::iterator it;
  for(ll i = 0; i < N; i++){
    ll a,m;
    cin >> a >> m;
    it = am.find(a);
    if(it != am.end() && it->second != m){
      printf("-1\n");
      exit(0);
    }
    am[a] = m;
  }

  printf("%d\n",crt(am,N));
}
