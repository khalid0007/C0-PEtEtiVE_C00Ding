//بسم الله الرحمن الرحيم
// أنا نفسي لا أستطيع فعل أي شيء ، كل ما أفعله هو إن شاء الله
// author: khalid007
#pragma GCC optimize("03")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


// Defined statements for ease of coding
// Uncommet this when required\
#define LONG_CONDITION_FOR_CP
#ifdef LONG_CONDITION_FOR_CP
    #define int             int_least64_t
#endif
// Uncomment for multiple test_case\
#define MULTIPLE_TESTCASE
#ifdef MULTIPLE_TESTCASE
    #define ForAllTestCase  int TEST_CASE; cin >> TEST_CASE; while(TEST_CASE--)
#else
    #define ForAllTestCase  int TEST_CASE = 1; while(TEST_CASE--)
#endif
#define rpt(n)              for(int i = 0; i < n; i++)
#define lp(i, s, e)         for(int i = s; i < e; i++)
#define memset(a, v, n)     for(int i = 0; i < n; i++) a[i] = v
#define MOD                 1000000007
#define rlp(i, s, e)        for(int i = s; i >= e; i--)
#define pb                  emplace_back
#define dbg(x)              cout << #x << " = " << x << "\n";
#define Print(c, x, y)      if(c) cout << x << "\n"; else cout << y << "\n"
#define All(v)              v.begin(), v.end()
#define OUT(_T, c)          ostream_iterator<_T>(cout, c)

using namespace std;
// using namespace __gnu_pbds;

namespace khalid007{
    int mpow(int a, int b, int m = MOD){int answer = 1; while (b) {if (b&1) answer=(answer*a)%m; b >>= 1; a=(a*a)%m;} return answer;}
    int pow(int a, int b){int answer = 1; while (b) {if (b&1) answer=(answer*a); b >>= 1; a=(a*a);} return answer;}
}

// Edit solve() for only
void solve() {
  
}

signed main() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); ForAllTestCase solve();}
