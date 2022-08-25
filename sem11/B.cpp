#include <bits/stdc++.h>
#define NEUTRAL 123456789
#define FACTOR 1
#define OP(X, Y) min(X,Y)
using namespace std;
using ll = long long;
const int N = 1e5+15;
vector<ll> t (4*N); vector<ll> lazy (4*N); 

void push(int ti, int tl, int tm, int tr) {
  { int sz = (tm - tl + 1);
    t[ti*2] += lazy[ti] * FACTOR; }
  lazy[ti*2] += lazy[ti]; { int sz = (tr - (tm+1) + 1);
    t[ti*2+1] += lazy[ti] * FACTOR; }
  lazy[ti*2+1] += lazy[ti];
  lazy[ti] = 0;
}

void add_inclusive(int l, int r, int d,
    int ti=1, int tl=1, int tr=N) {
  if (l > r) { return; }
  if (l == tl && tr == r) {
    int sz = tr - tl + 1;
    t[ti] += d * FACTOR; lazy[ti] += d; return; }
  int tm = (tl + tr) / 2; push(ti, tl, tm, tr);
  add_inclusive(l, min(r, tm), d, ti*2, tl, tm);
  add_inclusive(max(l, tm+1), r, d, ti*2+1, tm+1, tr);
  t[ti] = OP(t[ti*2], t[ti*2+1]);
}

ll op_inclusive(int l, int r,
    int ti=1, int tl=1, int tr=N) {
  if (l > r) { return NEUTRAL; }
  if (l <= tl && tr <= r) { return t[ti]; }
  int tm = (tl + tr) / 2; push(ti, tl, tm, tr);
  return OP(op_inclusive(l, min(r, tm), ti*2, tl, tm),
      op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr));
}

void build(vector<int>& src,
    int ti=1, int tl=1, int tr=N) {
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
  int n, q; cin >> n >> q; vector<int> src (n+1);
  for (int i = 1; i <= n; i++) { cin >> src[i]; }
  build(src);
  int op; int a, b, d;
  while (q--){
    cin >> op;
    if (op == 1) {
      cin >> a >> b >> d; add_inclusive(a, b, d);
    } else if (op == 2) {
      cin >> a >> b; cout << op_inclusive(a, b) << "\n";
    }
  }
}
