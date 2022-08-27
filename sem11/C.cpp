#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5+15;
vector<ll> t (4*N);
vector<bool> mark (4*N);

void add_inclusive(ll l, ll r, ll d, ll ti=1, ll tl=1, ll tr=N) {
  if (l > r)
    return;
  if (l == tl && r == tr){
    t[ti] += d;
    return; 
  }
  ll temp = (tl + tr) / 2;
  add_inclusive(l, min(r, temp), d, ti*2, tl, temp);
  add_inclusive(max(l, temp+1), r, d, ti*2+1, temp+1, tr);
}

void build(vector<ll>& src, ll ti=1, ll tl=1, ll tr=N) {
  if (tl == tr) {
    if (tl < src.size())
      t[ti] = src[tl];
    return;
  }
  ll temp = (tl+tr)/2;
  build(src, ti*2, tl, temp);
  build(src, ti*2+1, temp+1, tr);
  t[ti] = 0;
}

void push(ll ti) {
  if (mark[ti]) {
    t[ti*2] = t[ti*2+1] = t[ti];
    mark[ti*2] = mark[ti*2+1] = true;
    mark[ti] = false;
  }
}

void set_inclusive(ll l, ll r, ll v, ll ti=1, ll tl=1, ll tr=N) {
  if (l > r)
    return;
  if (l == tl && tr == r) {
    t[ti] = v;
    mark[ti] = true;
    return;
  }
  push(ti);
  ll temp = (tl + tr) / 2;
  set_inclusive(l, min(r, temp), v, ti*2, tl, temp);
  set_inclusive(max(l, temp+1), r, v, ti*2+1, temp+1, tr);
}

ll get(ll i, ll ti=1, ll tl=1, ll tr=N) {
  if (tl == tr)
    return t[ti];
  push(ti);
  ll temp = (tl + tr) / 2;
  if (i <= temp)
    return get(i, ti*2, tl, temp);
  else
    return get(i, ti*2+1, temp+1, tr);
}

ll query(ll l, ll r, ll n) {
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> src (n+1);
  for (ll i = 1; i <= n; i++) {
    ll temp;
    cin >> temp;
    src[i] = temp;
  }

  printf("Vetor antes:");
  for(int i = 1; i <= n; i++)
    printf("\t%d",src[i]);
  printf("\n");

  build(src);

  printf("Vetor depois:");
  for(int i = 1; i <= n; i++)
    printf("\t%d",t[i]);
  printf("\n");

  ll op, a, b, x;
  while (q--){
    cin >> op >> a >> b;
    if(op == 1){
      cin >> x;
      add_inclusive(a, b, x);
    } else if(op == 2){
      cin >> x;
      set_inclusive(a, b, x);
    } else if(op == 3){
      printf("%d\n", query(a, b, n));
    }
  }
}

