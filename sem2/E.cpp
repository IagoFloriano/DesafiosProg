#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, V;
  cin >> N >> V;
  //    especialidade, H  , A  ,  C , indice
  vector<tuple<int, int, int, int, int>> candidatos;
  for ( int i = 0; i < N; i++){
    tuple<int, int, int, int, int> temp;
    string nome;
    int H, M, A, C;
    char lixo;
    cin >> nome >> H >> lixo >> M >> A >> C;
    if (nome == "idjassu" || nome == "galhofa" || nome == "aipenkuit")
      temp = make_tuple(1, H>=13, A, -C, i+1);
    else
      temp = make_tuple(0, H>=13, A, -C, i+1);
    candidatos.push_back(temp);
  }

  stable_sort(candidatos.begin(), candidatos.end());
  for (int i = N-1; i >= N-V; i--){
    tuple<int, int, int, int, int> pessoa = candidatos[i];
    //cout << get<0>(pessoa)  << get<1>(pessoa)  << get<2>(pessoa)  << get<3>(pessoa)  << get<4>(pessoa) << endl; 
    cout << get<4>(pessoa) << "\n"; 
  }


}
