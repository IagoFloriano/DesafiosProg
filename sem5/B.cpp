#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define NEUTRAL 1

ll N;
vector<int> t;
ll OP(ll a, ll b){
  return a * b;
}

int op_inclusive(int l, int r, int ti=1, int tl=1, int tr=N) {
  if (l > r) { return NEUTRAL; }
  if (l == tl && r == tr) { return t[ti]; }
  int tm = (tl + tr) / 2;
  return OP(op_inclusive(l, min(r, tm), ti*2, tl, tm),
            op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr));
}

void set_value(int i, int v, int ti=1, int tl=1, int tr=N) {
  if (tl == tr) { t[ti] = v; return; }
  int tm = (tl + tr) / 2;
  if (i <= tm)
    set_value(i, v, ti*2, tl, tm);
  else
    set_value(i, v, ti*2+1, tm+1, tr);
  t[ti] = OP(t[ti*2], t[ti*2+1]);
}

void build(vector<int>& src, int ti=1, int tl=1, int tr=N) {
  if (tl == tr) {
  if (tl < src.size()) { t[ti] = src[tl]; }
    return;
  }
  int tm = (tl + tr) / 2;
  build(src, ti*2, tl, tm);
  build(src, ti*2+1, tm+1, tr);
  t[ti] = OP(t[ti*2], t[ti*2+1]);
}

int main() {
  ll K;
  cin >> N >> K;
  t = vector<int>(4*N);
  vector<int> in (N+1);

  for(ll i = 1; i <= N; i++){
    cin >> in[i];
    if(in[i]<0)in[i] = -1;
    if(in[i]>0)in[i] = +1;
  }
  build(in);

  for(ll count = 0; count < K; count++){
    char op;
    cin >> op;
    if (op == 'A'){
      ll i, y;
      cin >> i >> y;
      if(y<0)y = -1;
      if(y>0)y = +1;
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
