#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>A, B;
  int n;
  while (cin >> n){
    int temp;
    for(int i = 0; i < n; i++){
      cin >> temp;
      A.push_back(temp);
    }

    for(int i = 0; i < n/2; i++){
      cin >> temp;
      B.push_back(temp);
    }

    long long int erros = 0;
    for ( int i = 0; i < n/2; i++){
        erros+=abs((A[i] + A[n-i-1]) - B[i]);
    }
    cout << erros << "\n";
    A.erase(A.begin(), A.end());
    B.erase(B.begin(), B.end());
  }

}
