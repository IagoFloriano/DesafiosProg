#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> bit;
ll N;

void add(int i, int delta) {
  for (; i <= N; i += i & (-i))
    bit[i] += delta;
}

int get(int i) {
  int ans = 0;
  for (; i > 0; i -= i & (-i))
    ans += bit[i];
  return ans;
}

int main() {
  ll Q;
  string fita;
  cin >> N >> fita >> Q;
  bit = vector<int>(N+1,0);
  for(ll i = 1; i <= N; i++){
    add(i, fita[i-1] - '0');
  }

  for(ll i = 0; i < Q; i++){
    ll op;
    cin >> op;
    if(op==3){
      ll P;
      int D;
      cin >> P >> D;
      add(P, D-(get(P) - get(P-1)));
    }else{
      ll A1, A2, B1, B2, d, temp;
      cin >> A1 >> A2 >> B1 >> B2 >> d;
      ll A, B;
      A = get(A2) - get(A1-1);
      B = get(B2) - get(B1-1);
      if (op == 2)
        temp = (A * B) % 9;
      else
        temp = (A + B) % 9;
      cout << (temp == d ? "YES" : "NO") << "\n";
    }
  }

}
