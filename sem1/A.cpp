#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string x, y;
  for (int i=0; i < n; i++){
    cin >> x >> y;
    if ( ( atoi(&(x[x.length()-1])) + atoi(&(y[y.length()-1])) ) % 2 == 0)
      cout << "PARCEIROS\n";
    else
      cout << "NAO PARCEIROS\n";
  }
}
