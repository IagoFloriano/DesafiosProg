#include <bits/stdc++.h>
using namespace std;

int main() {
  list<pair<int, char>> torres;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    pair<int, char> temp;
    cin >> temp.first >> temp.second;
    torres.push_back(temp);
  }
  bool possivel = true;

  for (list<pair<int, char>>::iterator t = torres.begin(); possivel && t != torres.end(); t++){
    if ((*t).first == 0) continue;
    for (list<pair<int, char>>::iterator t2 = next(t, 1); t2!= torres.end(); t2++){
      if (t == t2) continue;

      if ( (*t2).first > (*t).first || (*t).second == 'O'){
        possivel = false;
        break;
      }

      if ( (*t2).first == (*t).first){
        if ( (*t2).second == 'L') { possivel = false; break; }
        (*t2).first = (*t).first = 0;
        break;
      }

    }

  }


  cout << (possivel ? "S" : "N") << "\n";

}
