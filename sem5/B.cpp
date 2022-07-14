#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define NEUTRAL 1

ll N;
vector<ll> t;
ll OP(ll a, ll b){
  return a * b;
}

ll op_inclusive(ll l, ll r) {
  r++;
  ll left = NEUTRAL, right = NEUTRAL;
  for (l += N, r += N; l < r; l /= 2, r /= 2) {
    if (l & 1) left = OP(left, t[l++]);
    if (r & 1) right = OP(right, t[--r]);
  }
  return OP(left, right);
}
void set_value(ll i, ll v) {
  t[i += N] = v;
  for (i /= 2; i > 0; i /= 2)
    t[i] = OP(t[i*2], t[i*2+1]);
}

int main() {
  ll K;
  cin >> N >> K;
  t = vector<ll>(10 + (2*N), 1);

  for(ll i = 1; i < N+1; i++){
    ll temp;
    cin >> temp;
    set_value(i,temp);
  }

  for(ll count = 0; count < K; count++){
    char op;
    cin >> op;
    if (op == 'A'){
      ll i, y;
      cin >> i >> y;
      set_value(i, y);
    }else{
      ll i, j;
      cin >> i >> j;
      ll temp = op_inclusive(i,j);
      if(temp == 0)
        cout << "0";
      else if(temp < 0)
        cout << "-";
      else
        cout << "+";
    }
  }
  cout << "\n";

}
