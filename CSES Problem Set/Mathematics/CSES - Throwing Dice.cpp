/**
* CSES - Throwing Dice
* Tematica : Aritmetica y Algebra: Recurrencia linear + exponenciacion matricial
* Idea: Dado un N decir la cantidad de formas que se puede generar con sumas que
* den N con lazmientos de un dado.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 1000010
#define EPS 1e-9
#define INF 1LL<<60
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
            int t = ((A[i][k] % MOD) * (B[k][j] % MOD ))% MOD;
            C[i][j]= (t + C[i][j]) % MOD  ;
          }
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

    Matrix X,V;

    for(int i =0;i<6;i++) X.push_back(Array(6,0));

    for(int i=0;i<X.size()-1;i++)X[i][i+1]=1;

    for(int i=0;i<X[5].size();i++) X[5][i] =1;

    V.push_back(Array(1,1));
    V.push_back(Array(1,1));
    V.push_back(Array(1,2));
    V.push_back(Array(1,4));
    V.push_back(Array(1,8));
    V.push_back(Array(1,16));

    X = pow(X,n);

    V = mul(X,V);

    cout<<V[0][0]<<ENDL;

    return 0;
}
