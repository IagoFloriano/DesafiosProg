#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll N, M;
  cin >> N;

  vector<ll>A(N+1);
  A[0] = -1;
  cin >> A[1];
  for(ll i = 2; i <= N; i++){
    ll temp;
    cin >> temp;
    A[i] = A[i-1] + temp;
  }

  cin >> M;
  vector<ll>Q(M);
  for(auto& i: Q)
    cin >> i;

//  for(auto i: A)
//    cout << i << "\t";
//  cout << endl;

  for(ll meia: Q){
    //cout << "-----Procurando meia: " << meia << endl;
    for(ll begin = 0, end = N-1;;){
      ll meio = begin + (end-begin) / 2;
      //cout << "comparando com " << A[meio] << " e " << A[meio-1] << endl;
      if(A[meio] >= meia && A[meio-1] < meia){
        cout << meio << "\n";
        break;
      }

      if(A[meio] < meia)
        begin = meio+1;
      else
        end = meio-1;
    }
  }

}
