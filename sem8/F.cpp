#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> N;

int rec(int n){
  if(N[n] != -1) return N[n];
  return rec(n-2) % rec(n-1);
}

int main() {
  ll T;
  cin >> T;
  while(T--){
    ll n, d;
    cin >> n >> d;
    N = vector<int>(,-1);
  }

}
