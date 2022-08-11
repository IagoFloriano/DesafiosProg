#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> empresas(n, vector<int>(m));
  vector<int> in(n);
  for(int i = 0; i < n; i++){
    int c;
    cin >> c;
    while(c--){
      int temp;
      cin >> temp;
      empresas[i][temp-1] = 1;
    }
  }

  for(int i = 0; i < n; i++){
    if(in[i] != 0) continue;

    for(int j = 0; j < n; j++){
      if(i==j) continue;

      bool contido = true;
      for(int n = 0; n < m && contido; n++){
        if(empresas[i][n] == 1 && empresas[j][n] == 0) contido = false;
      }

      if(contido) in[j]++;
    }
  }

  for(int i = 0; i < n; i++)
    if(in[i] == 0) printf("%d\n",i);

}
