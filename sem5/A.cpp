#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n, h;
  cin >> n >> h;

  vector<pair<ll,ll>>p(n);
  for(auto& i:p)
    cin >> i.first;

  for(ll i = h; i < n; i++){
    cout << p[i].first << "\t";
  }
  cout << endl;

}
