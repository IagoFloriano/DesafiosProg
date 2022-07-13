#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n, h;
  cin >> n >> h;

  vector<pair<ll,ll>>p(n);
  for(auto& i:p){
    cin >> i.first;
    i.second = 0;
  }

  for(ll i = h; i < n; i++){
    cout << p[i].first << "\t";
  }
  cout << endl;

  // pra cada pessoa
  for(ll i = 0; i < n; i++){
    //checar pessoas antes
    for(ll j = i; j >=0; j--){
      if(p[j].first == p[i].first + 1){
        p[i].second += p[j].second + 1;
        break;
      }
      if(p[j].first > p[i].first){
        p[i].second++; // = p[j].second + 1;
      }
    }
    cout << p[i].second << "\t";
  }
  cout << endl;

  // pegar soma
  ll soma=0;
  for(ll i = h; i < n; i++){
    soma+=p[i].second;
  }

  cout << soma << "\n";
}
