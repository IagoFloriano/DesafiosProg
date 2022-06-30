#include <bits/stdc++.h>
using namespace std;
using  ll=long long;

int main() {
  ll n;
  vector<ll> geo;
  cin >> n;
  for(ll i = 0; i < n; i++){
    ll temp;
    cin >> temp;
    geo.push_back(temp);
  }

  pair<ll, ll> raz1, raz2;
  sort(geo.begin(), geo.end());
  raz1 = make_pair(geo[1]/geo[0], 1);
  raz2 = make_pair(0, 0);
  ll i;
  for(i = 1; i < n-1; i++){
    ll raz = geo[i+1]/geo[i];
    if(raz == raz1.first) raz1.second++;
    else{
      raz2.second++;
      raz2.first = raz;
    }
    if (raz1.second * raz2.second > 1) break;
  }

  if (raz2.second == 0){
    if ( geo[0] % raz1.first == 0) cout << geo[0]/raz1.first << "\n";
    if(raz1.first < 0 || raz1.first > 1) cout << geo.back() * raz1.first << "\n";
    return 0;
  }
  ll raz;
  raz = raz1.second > raz2.second ? raz1.first : raz2.first;

  // achar numero q n segue razao
  if (geo[i-1]/geo[i-2] != raz) cout << (ll)(geo[i-2] * raz);
  else if (geo[i]/geo[i-1] != raz) cout << (ll)(geo[i-1] * raz);
  else if (geo[i+1]/geo[i] != raz) cout << (ll)(geo[i] * raz);

  cout << "\n";
}
