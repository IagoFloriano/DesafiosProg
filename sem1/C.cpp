#include <bits/stdc++.h>
using namespace std;

int main() {
  string c;
  int H, M;
  while(cin >> c >> H >> M){
    if ( H * 60 + M > 600)
      cout <<"Abel deve cancelar " << c << "\n";
    else
      cout <<"Abel deve cursar " << c << "\n";
  }

}
