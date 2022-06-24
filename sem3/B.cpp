#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll prime = 1000000007;

ll modfat(ll n, ll stop){
  if (n == stop) return 1;
  return ( (n % prime) * (modfat(n-1, stop) % prime) ) % prime;
}

int main() {
  ll n, c;
  cin >> n >> c;
  vector<pair <ll, ll>> cols;

  for (ll i = 0; i < n; i++){
    ll temp;
    cin >> temp;
    cols.push_back(make_pair(temp, 0));
  }

  for (ll i = 0; i < c; i++){
    int trash, col;
    cin >> trash >> col;
    cols[col-1].second++;
  }

  vector<ll> fats;
  for (pair<ll,ll> cur: cols){
    ll temp = modfat(cur.first, cur.second);
    fats.push_back(temp);
  }

  ll prod = 1;
  for (ll f: fats){
    prod = ( (prod % prime) * (f % prime) ) % prime;
  }
  cout << prod << "\n";


}
