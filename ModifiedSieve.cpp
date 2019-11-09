#include<bits/stdc++.h>
#define VariableName(x) #x

using namespace std;


#define MAX_SIZE  (long long)1e6 + 1

vector<bool> IsPrime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);

void Modified_sieve(long long n)
{
    IsPrime[0] = IsPrime[1] = false;

    for(long long i = 2; i < n; i++) 
    {
        if(IsPrime[i]) {prime.push_back(i); SPF[i] = i;}

        for(int j = 0; j < prime.size() && prime[j]*i < n && prime[j] <= SPF[i]; j++)
        {
            IsPrime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j]; 
        }
    }
}

int main()
{
    Modified_sieve(100);

    cout << prime << "\n";
}
