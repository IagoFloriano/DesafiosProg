#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string nome;
  bool deboas = true;
  list<string> meias;
  list<string>::iterator it;

  for (int i = 0; i < n*2 && deboas; i++){
    cin >> nome;
    it = find(meias.begin(), meias.end(), nome);
    if (*it == nome)
      meias.erase(it);
    else
      meias.push_back(nome);
    if (meias.size() >= k){
      deboas = false;
      break;
    }
  }

  cout << (deboas ? "3.14159" : "7.18808") << "\n";

}
