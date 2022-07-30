#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<int>bares (n);
  for(auto& i: bares)
    cin >> i;
  ll melhor = 0;
  ll atual = 0;

  ll i = 0;
  ll j = 1;

  atual = bares[i];
  if(atual > melhor && atual <= m)
    melhor = atual;

  while(i < n && j <= n){
    //cout << i << "," << j << " : " << atual << endl;

    if(atual < m){
      if( j >= n) break;
      atual += bares[j++];
    }
    else if(atual > m)
      atual -= bares[i++];
    else break;

    if(atual > melhor && atual <= m)
      melhor = atual;
  }

  cout << melhor << "\n";

}
