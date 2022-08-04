#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll T;
  cin >> T;
  while(T--){
    ll n, d, temp, intero;
    cin >> n >> d;
    intero = n/d;
    n -= intero*d;
    temp = d;
    d = n;
    n = temp;
    printf("[%d", intero);
    char c = ';';
    while(d != 0){
      intero = n/d;
      n -= intero*d;
      temp = d;
      d = n;
      n = temp;
      printf("%c%d",c,intero);
      c = ',';
    }
    printf("]\n");
  }

}
