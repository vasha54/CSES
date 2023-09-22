/**
* CSES - Counting Tilings
* Temática: Progrmación Dinamica. Counting Tiling
*
* Idea: Ejercicio clasico que se puede resolver aplicando el algoritmo de
* counting tiling
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 85
#define EPS 1e-9
#define INF 1000000000
#define int long long
#define READ_FILE freopen("Input.txt","r",stdin);

using namespace std;

int dp[1003][1030], n,m;
const int MOD = 1e9+7;

void tiling(int x = 0, int y = 0, int mask = 0, int next_mask = 0) {
   if (x == n) return;
   if (y >= m) (dp[x+1][next_mask] += dp[x][mask])%=MOD;
   else{
      int my_mask = 1 << y;
      if (mask & my_mask) tiling (x, y+1, mask, next_mask);
      else{
         tiling(x, y+1, mask, next_mask | my_mask);
         if (y+1 < m && !(mask&my_mask) && ! (mask & (my_mask << 1)))
            tiling (x, y+2, mask, next_mask);
      }
   }
}

int countTilings(int n,int m){
   dp[0][0]= 1;
   for (int x=0; x<=n; ++x)
      for (int mask=0; mask<(1<<m); ++mask)
         tiling(x, 0, mask, 0);
   return dp[n][0];
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)

    #ifdef LOCAL
    READ_FILE
    #endif
    cin>>m>>n;
    cout<<countTilings(n,m);
    return 0;
}
