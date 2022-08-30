#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(X) X.begin(), X.end()
#define s(X) X.c_str()

int main () {
  ll N;
  cin >> N;
  string hay, ne;
  map<string, ll> count;

  while (N--) {
    cin >> hay;
    regex r ("([A-Za-z])([A-Za-z0-9])*@(([A-Za-z0-9])*.)?ufpr.br");
    ll amount = distance(sregex_iterator(all(hay), r), sregex_iterator());
    if(amount == 1){
      map<string, ll>::iterator found;
      found = count.find(hay);
      if(found != count.end()){
        printf("%d\n", found->second + 1);
      }else{
        printf("1\n");
        count[hay] = 0;
      }
      count[hay]++;
    }
  }
}
