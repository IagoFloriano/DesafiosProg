#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string rna;
  cin >> N;
  cin >> rna;
  int first = -1;
  int last = -1;
  int countf = 0;
  int countl = 0;

  for(int i = 0; i < N; i++){
    if (countf < 7)
      if (rna[i] == 'A'){
        first = i;
        countf++;
      }
      else
        countf = 0;

    if (countl < 7 )
      if(rna[N-1-i] == 'A'){
        last = N-1-i;
        countl++;
      }
      else
        countl = 0;

  }

  first -=6;
  last +=6;
  cout << (countl + countf != 14 ? 0 : last-first+1) << "\n";
}
