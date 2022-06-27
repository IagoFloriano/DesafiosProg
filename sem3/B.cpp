#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll prime = 1000000007LL;

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
  for (pair<int, int> pipi: cols)
    cout << pipi.first << " ";
  cout << endl;

  for (ll i = 0; i < c; i++){
    int trash, col;
    cin >> trash >> col;
    cols[col-1].second++;
  }
  for (pair<int, int> pipi: cols)
    cout << pipi.first - pipi.second << " ";
  cout << endl;

  vector<ll> fats;
  for (pair<ll,ll> cur: cols){
    ll temp1 = modfat(cur.first, 0);
    ll temp2 = modfat(cur.second, 0);
    fats.push_back(temp1/temp2);
  }
  for (auto f: fats)
    cout << f << " ";
  cout << endl;

  ll prod = 1;
  for (ll f: fats){
    prod = ( (prod % prime) * (f % prime) ) % prime;
  }
  cout << prod << "\n";


}
