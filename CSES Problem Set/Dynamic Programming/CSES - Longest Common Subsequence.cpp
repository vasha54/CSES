 /**
 * CSES - Longest Common Subsequence 
 * Temática: Programación Dinámica + LCS 
 * 
 * Idea: Idea clasica del LCS e imprimir la LCS 
 *
 */ 
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
 
#ifdef LOCAL
    #define READ_FILE freopen("Input.txt","r",stdin);
    #define WRITE_FILE freopen("Output.txt","w",stdout);
#else
    #define READ_FILE 
    #define WRITE_FILE 
#endif
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 1000010
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
 
using namespace std;
using namespace __gnu_pbds;


signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int n,m;
	cin>>n>>m;
	vector<int> N(n+1),M(m+1);
    for(int i=1;i<=n;i++) cin>>N[i];
	for(int i=1;i<=m;i++) cin>>M[i];
	vector<vector<int> > dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(N[i]==M[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n][m]<<ENDL;
	
	vector<int> lcs;

    while (dp[n][m] > 0) {
        if (N[n] == M[m]) {
            lcs.push_back(N[n]);
            n--;
            m--;
        } else if (dp[n - 1][m] == dp[n][m]) {
            n--;
        } else {
            m--;
        }
    }

	reverse(lcs.begin(), lcs.end());
    for (auto x : lcs) {
        cout << x << " ";
    }
    return 0;
}

