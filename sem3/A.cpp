#include <bits/stdc++.h>
using namespace std;

vector<int> order;
vector<pair<int, int>> restricoes;

void printorder(){
  for (int i = 0; i < order.size(); i++){
    cout << order[i] << (i == order.size()-1 ? "\n" : " ");
  }
}

bool possivel(int i){
  if (find(order.begin(), order.end(), i) != order.end()) return false;

  for (pair<int, int> r : restricoes){
    if (r.second == i && (find(order.begin(), order.end(), r.first) == order.end()))
      return false;
  }
  return true;
}

void gen(int n, int max) {
  if (n==max) { printorder(); return;}

  for (int i = 0; i < max; i++){
    if (possivel(i+1)){
      order[n] = i+1;
      gen(n+1, max);
      order[n] = 0;
    }
  }
}

int main() {
  int n, c;
  cin >> n >> c;
  order.resize(n);
  for (int i = 0; i < n; i++)
    order[i] = 0;

  for (int i = 0; i < c; i++){
    int a, b;
    cin >> a >> b;
    restricoes.push_back(make_pair(a, b));
  }

  gen(0, n);

}
