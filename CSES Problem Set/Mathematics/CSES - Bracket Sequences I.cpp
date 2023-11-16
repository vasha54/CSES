/**
* CSES - Bracket Sequences I
* Tematica : Combinatoria : Numeros de Catalanes + Inverso Multiplicativo
* Idea: Clasica aplicacion de los numeros de catalanes. Contar el número de
* expresiones que contienen n pares de paréntesis correctamente colocados
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 1000010
#define EPS 1e-9
#define INF 1000000000
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define int long long
#define uint unsigned int

using namespace std ;

int catalan[MAX_N];

int inverseMul(int i, int m) {
    return i <= 1 ? i : m - (int)(m/i) * inverseMul(m % i, m) % m;
}

int catalanDPV2(int n){
   catalan[0] = 1;
   for (int i = 0; i <= n; i++)
      catalan[i+1] = (catalan[i] % MOD  * (4*i+2) % MOD * inverseMul(i+2,MOD))% MOD ;
   return catalan[n] % MOD;
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE

    int N;
    cin>>N;
    cout<< ( N&1 ? 0 : catalanDPV2(N/2) )<<ENDL;

    return 0;
}
