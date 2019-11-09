#include<bits/stdc++.h>

using namespace std;

const int prime = (int)1e6 + 3;
const char base_char = 'a';

int power(int a, int b, int m)
{
    int answer=1;
    while (b) {
        if (b&1) answer=(answer*a)%m;
        b >>= 1;
        a=(a*a)%m;
    }
    
    return answer;
}

// T = Text; P = pattern; d = Radix-d base; q = Prime
int RobinKarp(const string& T, const string& P, int d = 26, int q = prime)
{
    int n = T.length(), m = P.length, h = power(d, m - 1, q), p = 0, t = 0, count;

    // Preprocessing
    for(int i = 0; i < m; i++)
    {
        p = (d*p + (int)(P[i] - base_char));
        t = (d*t + (int)(T[i] - base_char));
    }

    //matching
    for(int s = 0; s <= n - m; s++)
    {
        if(p == t)
        {
            int i = 0;
            for(i; i < m; i++) if(p[i] != p[s + i]) break;

            if(i == m) count++;
        }

        if(s < n - m) t = (((t - h*(t[s] - base_char))*d) - (t[s+m] - base_char))%q;
    }

    return count;
}

int main()
{
    return 0;
}