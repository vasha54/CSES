/**
* CSES - Static Range Sum Queries
* Tematica : Programación Dinámica : Suma de Prefijo
* Idea: Clasico suma de prefijo.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 200020
#define EPS 1e-9
#define INF 1000000000
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long

using namespace std;


int n,q,a,b,dp[MAX_N];


signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE

    cin>>n>>q;
    fill(dp,dp+MAX_N,0);

    for(int i=1;i<=n;i++){
        cin>>dp[i];
        dp[i]+=dp[i-1];
    }

    for(int i=0;i<q;i++){
        cin>>a>>b;
        cout<<dp[b]-dp[a-1]<<ENDL;
    }

    return 0;
}
