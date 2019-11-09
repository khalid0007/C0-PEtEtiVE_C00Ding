#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void COMPUTE_PREFIX_FUNCTION(const string& P, vector<int>& pi)
{
    int k = 0;

    for(int q = 2; q <= P.length(); q++)
    {
        while(k > 0 && P[k] != P[q-1]) k = pi[k];

        if(P[k] == P[q-1]) k++;

        pi[q] = k;
    }
}

int KMP(const string& T, const string& P)
{
    int n = T.length(), m = P.length(), ans = 0, state = 0;

    vector<int> pi(m + 1);

    COMPUTE_PREFIX_FUNCTION(P, pi);

    for(int i = 0; i < n; i++)
    {
        while(state > 0 && P[state] != T[i]) state = pi[state];

        if(P[state] == T[i]) state++;

        if(state == m) {/* cout << "Pattern occurs with shift " << i - m + 1 << "\n";*/ ans++; state = pi[state];}
    }

    return ans;
}

int main()
{
    string a = "geeksforgeeks";
    string t = "e";

    cout << KMP(a, t);
}
