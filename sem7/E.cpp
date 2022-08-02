#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll T;
  cin >> T;
  while(T--){
    ll Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;

    if(Ax == Bx)
      cout << abs(Ay - By) + 1;
    else if(By == Ay)
      cout << abs(Ax - Bx) + 1;
    else
      cout << __gcd(abs(Ay - By), abs(Ax - Bx)) + 1;
    cout << "\n";
  }

}
