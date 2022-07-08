#include <bits/stdc++.h>
using namespace std;
using ll=int;

vector<vector<ll>> dp;
vector<ll> quadrados;
ll n, k, c;

int main() {
  cin >> n >> k >> c;
  quadrados = vector<ll>(n+1);
  dp = vector<vector<ll>>(k+1,vector<ll>(n+1,-1000000000));

  dp[0][0] = 0;

  for(ll i = 1; i <=n; i++){
    cin >> quadrados[i];
    dp[0][i] = dp[0][i-1]+quadrados[i];
  }

  for(ll i = 1; i <= k; i++){
    for(ll j = i*c; j <= n; j++){
      dp[i][j] = max( dp[i-1][j-c], dp[i][j-1]+quadrados[j] );
    }
  }


  cout << dp[k][n] << "\n";

}
