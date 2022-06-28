#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll prime = 1000000007LL;

vector<ll> lookup;

ll modfat(ll n){
  if (n == 0 || n == 1) return 1;
  if (lookup[n] != 0) return lookup[n];
  lookup[n] = ( (n % prime) * (modfat(n-1) % prime) ) % prime;
  return lookup[n];
}

ll fast_pow(ll a, ll b){
  if (b == 0) return 1;
  ll temp = fast_pow(a, b/2);
  ll rvalue = ( (temp % prime) * ( temp % prime) ) % prime;
  if (b % 2 == 1)
    rvalue = ( (a % prime) * ( rvalue % prime) ) % prime;
  return rvalue;
}

int main() {
  ll n, c;
  cin >> n >> c;
  vector<pair <ll, ll>> cols;
  ll biggest =0;

  for (ll i = 0; i < n; i++){
    ll temp;
    cin >> temp;
    if (temp > biggest) biggest = temp;
    cols.push_back(make_pair(temp, 0));
  }

  lookup.resize(biggest + 1, 0);

  for (ll i = 0; i < c; i++){
    int trash, col;
    cin >> trash >> col;
    cols[col-1].second++;
  }

  vector<ll> fats;
  for (pair<ll,ll> cur: cols){
    ll temp = modfat(cur.first);
    ll temp2 = modfat(cur.first - n + cur.second);
    temp2 = fast_pow(temp2, prime-2);
    ll temp3 = ( (temp % prime) * (temp2 % prime) ) % prime;
    fats.push_back(temp3);
  }

  ll prod = 1;
  for (ll f: fats){
    prod = ( (prod % prime) * (f % prime) ) % prime;
  }
  cout << prod << "\n";


}
