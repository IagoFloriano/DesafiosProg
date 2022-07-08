#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<ll> quadrados;
vector<ll> csomas;
ll n, k, c;

ll minlapis(vector<ll>& pos, ll curr, ll currsum){
  if(curr >= pos.size()) return currsum;
  ll best = LLONG_MAX;
  ll i = curr == 0 ? 0: pos[curr-1]+c;
  for(; i < n-c+1; i++){
    if( (pos.size()-curr)*c > csomas.size()-i+1){
      break;
    }
    pos[curr] = i;
    ll temp = minlapis(pos, curr+1, currsum + csomas[i]);
    best = min(temp,best);
  }
  return best;
}

int main() {
  cin >> n >> k >> c;
  vector<ll> poslapis(k, -c);
  ll total=0;

  for(ll i = 0; i < c; i++){
    ll temp;
    cin >> temp;
    total+=temp;
    quadrados.push_back(temp);
  }

  csomas.push_back(total);

  for(ll i = c; i < n; i++){
    ll temp;
    cin >> temp;
    total+=temp;
    quadrados.push_back(temp);
    csomas.push_back(csomas[i-c] -quadrados[i-c] + temp);
  }

  total -= minlapis(poslapis, 0, 0);
  cout << total << endl;
}
