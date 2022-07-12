#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  //r = -b +- sqrt(b² - 4ac)
  ll totest = (b * b) - (4 * a * c);
  double lixo;
  double resultado;
  resultado = sqrt(totest);
  if(modf(resultado, &lixo) == 0)
    cout << "Y";
  else
    cout << "N";
  cout << "\n";

}
