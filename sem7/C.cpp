#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  unsigned long long h, n, v, result;
  cin >> h >> n >> v;
  result = v/h;
  result = (unsigned long long)ceil(result/(double)n);
  if(n == 1)
    result = v/h;

  cout << result << "\n";
}
