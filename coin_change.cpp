#include<bits/stdc++.h>

using namespace std;

#define int long long

count(const vector<int>& coins, int n, int m){

    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    
    // Zero means it can be changed
    dp[0] = 1;

    for(int i = 0; i < m; i++)
        for(int j = coins[i]; j <= n; j++)
            dp[j] += dp[j-coins[i]];


    return dp[n];
}

signed main(){

    // m = number of basic coins
    int m; cin >> m;

    vector<int> coins;
    coins.reserve(m);

    for(int i = 0; i < m; i++) cin >> coins[i];

    // n = number to changed into
    int n; cin >> n;

    cout << count(coins, n, m) << "\n";

    return 0; 
}