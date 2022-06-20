#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string nome;
  bool deboas = true;
  set<string> meias;
  pair<set<string>::iterator, bool> it;

  for (int i = 0; i < n*2 && deboas; i++){
    cin >> nome;
    it = meias.insert(nome);
    if (!it.second) meias.erase(it.first);
    if (meias.size() >= k){
      deboas = false;
      break;
    }
  }

  cout << (deboas ? "3.14159" : "7.18808") << "\n";

}
