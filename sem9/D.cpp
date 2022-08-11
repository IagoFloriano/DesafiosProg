#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void imprime_set(set<int>a){
  for(set<int>::iterator it = a.begin(); it != a.end(); it++)
    printf("\t%d",*it);
  printf("\n");
}

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<set<int>> empresas(n);
  vector<int> in(n);
  for(int i = 0; i < n; i++){
    int c;
    cin >> c;
    while(c--){
      int temp;
      cin >> temp;
      empresas[i].insert(temp);
    }
  }

  // for(int i= 0; i < n; i++){
  //   printf("%d:",i);
  //   imprime_set(empresas[i]);
  // }

  for(int i = 0; i < n; i++){
    if(in[i] != 0) continue;

    for(int j = 0; j < n; j++){
      if(i==j) continue;
      if(empresas[j].size() < empresas[i].size()) continue;

      bool contem = true;
      for(set<int>::iterator it = empresas[i].begin(); it != empresas[i].end() && contem; it++)
        if(empresas[j].find(*it) == empresas[j].end()) contem = false;

      if(contem) in[j]++;
    }
  }

  for(int i = 0; i < n; i++)
    if(in[i] == 0) printf("%d\n",i);

}
