/**
* CSES - Exponentiation II
* Tematica : Aritmetica Algebra : Exponenciación binaria
* Idea: Clasica exponenciación binaria modulada con la adaptación que se debe
* calular a^{b^c}.
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
#define uint unsigned int

using namespace std;

int cases;
int ba,exponent1,exponent2;

int binpow (int a, int n, int m){
   uint res = 1;
   a= a % m;
   while (n){
      if(n&1) res= (res* a)% m;
      a= (a*a) % m;
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
        cin>>ba>>exponent1>>exponent2;
        cout<<binpow(ba,binpow(exponent1,exponent2,MOD-1),MOD)<<ENDL;
    }

    return 0;
}
