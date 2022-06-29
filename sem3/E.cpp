#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll max_dup(multiset<ll>& conjunto){
  ll max = 0;
  for(multiset<ll>::iterator it = conjunto.begin(); it != conjunto.end(); it = conjunto.upper_bound(*it)){
    ll temp = conjunto.count(*it);
    if (temp > max) max = temp;
  }
  return max;
}

int main() {
  ll n, k;
  cin >> n >> k;
  deque<pair<ll, multiset<ll>::iterator>> vetor;
  multiset<ll> max;
  multiset<ll>::iterator it;
  ll gmax = 0;
  it = max.insert(0);
  vetor.push_back(make_pair(0, it));

  for (ll i = 0; i < k-1; i++){
    ll temp;
    cin >> temp;
    it = max.insert(temp);
    vetor.push_back(make_pair(temp, it));
  }

  for (ll i = k-1; i < n; i++){
    ll temp;
    cin >> temp;
    it = max.insert(temp);
    vetor.push_back(make_pair(temp, it));
    max.erase(vetor[0].second);
    vetor.pop_front();
    temp = max_dup(max);
    if (temp > gmax) gmax = temp;
  }

  cout << gmax << "\n";
}
