/**
 * CSES - Counting Towers
 * Temática: Programación Dinámica + Recurrencia
 * 
 * Idea:
 * El problema te pide calcular el número de torres diferentes que se 
 * pueden construir con un ancho fijo de 2 y una altura n. Para ello, 
 * dispones de un suministro ilimitado de bloques con dimensiones enteras 
 * (ancho y alto). Las torres que sean simétricas o rotadas se consideran 
 * diferentes si visualmente no son idénticas. 
 * 
 * Calcular el número de torres de ancho 2 y altura n con bloques de
 * dimensiones enteras. Se modela con dos estados según la última fila:
 * 
 *  - separated[i] : la última fila tiene dos bloques independientes de 1x1.
 *  - joined[i]    : la última fila tiene un solo bloque de 2x1.
 * 
 * Casos base:
 *  separated[1] = 1, joined[1] = 1
 * 
 * Transiciones:
 *  separated[i] = 4 * separated[i-1] + joined[i-1]
 *  joined[i]    =   separated[i-1] + 2 * joined[i-1]
 * 
 * La respuesta para altura n es (separated[n] + joined[n]) mod 1e9+7.
 * Se precumple hasta la máxima altura (1e6) para responder consultas en O(1).
 */
#include <bits/stdc++.h>
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
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 1000001
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;
using namespace __gnu_pbds;

int dp[MAX_N][2]; // dp[i][0] = separated[i], dp[i][1] = joined[i]

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    // Pre-cálculo DP
    dp[1][0] = 1; // separated[1]
    dp[1][1] = 1; // joined[1]

    for(int i=2; i<MAX_N; i++){
        dp[i][0] = (4 * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + 2 * dp[i-1][1]) % MOD;
    }

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << ENDL;
    }
    return 0;
}