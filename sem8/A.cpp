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

ll crt(vll a, vll m, int t) {
  ll p = 1;
  for (ll& mi : m){ 
    p *= mi;
  }
  ll ans = 0;
  for (int i = 0; i < t; i++) {
    ll tempni = p/m[i];
    ll tempbi = a[i];
    ll tempxi = inv(tempni, m[i]);
    ans += tempni*tempbi*tempxi;
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  vll a(N), m(N);
  for(ll i = 0; i < N; i++)
    cin >> m[i] >> a[i];

  printf("%d\n",crt(a,m,N));
}
