// Question Link: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/angry-neighbours/description/
// Solution Method: Matrix exponetiation

/*
    let F[n] = a*F[n-1] + b*F[n-2] + c*F[n-3]

    then we can represent following into:

    | F[n]  |   | a b c |   | F[n-1]|
    | F[n-1]| = | 1 0 0 | x | F[n-2]|
    | F[n-2]|   | 0 1 0 |   | F[n-3]|


            | a b c |
    Let M = | 1 0 0 |
            | 0 1 0 |


    we can easily write

    F[n] =[ pow(M, n-2)][0, :] * [f[2] f[1] f[0]] 

*/

#include<bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = (long long)(1e9 + 7);

void multiply(int a[4][4], int b[4][4]) {
    
    int mul[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                mul[i][j] = (mul[i][j] + a[i][k]*b[k][j])%MOD;
                
                
    // Update the values into a
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) a[i][j] = mul[i][j];
}


int power(int n){
    
    int M[3][3] = {{1, 1, 0}, {1, 0, 0}, {0, 1, 0}};
    int F[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    
    while(n) {
        if(n&1) multiply(F, M);
        
        multiply(M, M);
        
        n >>= 1;
    }
    
    return (F[0][0]*3 + F[0][1]*2)%MOD;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int t; cin >> t;
    
    while(t--){
        int n; cin >> n;
        
        if(n == 0) cout << 1 << "\n";
        else if(n == 1) cout << 2 << "\n";
        else cout << power(n-2) << "\n";
    }
    
    return 0;
}