#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> min;

  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    min.push_back(temp);
  }

  sort(min.begin(), min.end());

  cout << n/2 << " " << min[n/2] - min[(n/2)-1] << "\n";

}
