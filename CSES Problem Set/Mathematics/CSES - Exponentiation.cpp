/**
* CSES - Exponentiation
* Tematica : Aritmetica Algebra : Exponenciación binaria
* Idea: Clasica exponenciación binaria modulada.
*/
 
#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 200020
#define EPS 1e-9
#define INF 1000000000
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long
 
using namespace std;
 
int cases,base,exponent;
 
int binpow (int a, int n){
   int res = 1;
   while (n){
      if(n&1) res= (res* a)% MOD;
      a= (a*a) % MOD;
      n>>=1;
   }
   return res;
}
 
signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
 
    cin>>cases;
    while(cases--){
        cin>>base>>exponent;
        cout<<binpow(base,exponent)<<ENDL;
    }
 
    return 0;
}
