#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int N, I, M, P;
vector<int> C, V;
vector<vector<int>>dp; //dp[i][j] menor custo de vodka para i anos com destilador idade j

int main() {
  cin >> N >> I >> M >> P;
  C = vector<int> (M);
  V = vector<int> (M+1);
  dp = vector<vector<int>>(N+1,vector<int>(M+1,INF));

  for(int i=0; i < M; i++)
    cin >> C[i];
  for(int i=1; i <= M; i++)
    cin >> V[i];

  for(int i=0; i<=M; i++)
    dp[0][i] = 0;

  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
    }
  }

  cout << dp[N][I] << endl;

}
