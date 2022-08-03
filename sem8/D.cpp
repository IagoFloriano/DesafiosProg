#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll H, M, S;
  cin >> H >> M >> S;
  ll quant = __gcd(H, __gcd(M,S));
  printf("%d\n", quant);
  ll h, m, s;
  h = m = s = 0;
  for(ll i = 0; i < quant; i++){
    printf("%d %d %d\n",h,m,s);
    h += H/quant;
    m += M/quant;
    s += S/quant;
  }

}
