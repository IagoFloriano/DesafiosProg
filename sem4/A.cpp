#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll t;
  cin >> t;

  while(t--){
    ll p, h, f, d, c;
    cin >> p >> h >> f >> d >> c;
    ll lucro = 0;
    if (d > c){ // fazer com H
      ll n = min(p/2, h);
      p -= n *2;
      lucro = n*d;
      lucro += c*(min(p/2, f));
    } else { // fazer com F
      ll n = min(p/2, f);
      p -= n *2;
      lucro = n*c;
      lucro += d*(min(p/2, h));
    }
    cout << lucro << "\n";
  }
}
