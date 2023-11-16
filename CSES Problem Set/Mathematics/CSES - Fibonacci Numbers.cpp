/**
* CSES - Fibonacci Numbers
* Tematica : Aritmetica - Algebra : Fibonacci+ exponenciacion matricial
* Idea: Calcular el enesimo termino de la sucesion de Fibbonaci modulada
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
 
typedef int number;
typedef vector <number> Array;
typedef vector <Array > Matrix;
 
int n;
 
Matrix identity (int n) {
   Matrix A (n, Array (n,0));
   for (int i=0; i<n; ++i) A[i][i]=1;
   return A;
}
 
 
Matrix mul ( Matrix & A,  Matrix & B) {
   Matrix C (A.size (), Array (B [0]. size ()));
   for (int i = 0; i<C.size(); ++i)
      for (int j=0; j<C[i].size (); ++j)
         for (int k=0; k<A[i].size(); ++k){
            number p =  ((A[i][k] % MOD) *  (B[k][j] % MOD))%MOD;
            C[i][j]= (p + C[i][j]) % MOD;
         };
   return C;
}
 
Matrix pow (Matrix & A, int e){
   Matrix ret = identity(A.size());
   while(e){
      if(e&1) ret=mul(ret,A);
         e>>=1;
      A=mul(A,A);
   }
   return ret;
}
 
 
 
signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
 
    cin>>n;
 
    Array rV1,rV2;
    Array rX1,rX2;
    Matrix V,X,F;
 
    rV1.push_back(0);
    rV2.push_back(1);
 
    rX1.push_back(0);
    rX1.push_back(1);
    rX2.push_back(1);
    rX2.push_back(1);
 
    V.push_back(rV1);
    V.push_back(rV2);
 
    X.push_back(rX1);
    X.push_back(rX2);
 
    X = pow(X,n);
    F = mul(X,V);
 
    cout<<F[0][0]<<ENDL;
 
 
    return 0;
}
