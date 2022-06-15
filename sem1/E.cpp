#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, V;
  cin >> N >> V;
  int count = 1;
  int i = 2;
  while(count <= V){
    if(i > N)
      break;
    cout << i << "\n";
    count++;
    i+=2;
  }
  i = 1;
  while(count <= V){
    if(i > N)
      break;
    cout << i << "\n";
    count++;
    i+=2;
  }

}
