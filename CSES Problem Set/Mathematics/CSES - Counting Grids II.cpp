/**
* CSES - Counting Grids II
* Tematica : Teoria de grafos: Minimo diastacia entre dos nodos+ exponenciacion matricial
* Idea: Dado un grafo dirigido determinar la minimo camino entre dos nodos con un
* camino de exactamente k aristas
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
 
int n,m,k,a,b,c;
 
Matrix weigth (int V) {
   Matrix A (V, Array (V,INF));
   return A;
}
 
Matrix mul ( Matrix & A,  Matrix & B) {
   Matrix C (A.size (), Array (B [0]. size (),INF));
   for (int i = 0; i<C.size(); ++i)
      for (int j=0; j<C[i].size (); ++j)
         for (int k=0; k<A[i].size(); ++k){
            C[i][j]= min(C[i][j],A[i][k]+B[k][j]);
         }
   return C;
}
 
Matrix pow (Matrix & A, int e){
   Matrix ret (A.size(),Array(A[0].size(),INF));
   int f = 0;
   while(e){
      if(e&1){
       if(f)ret=mul(ret,A);
       else ret=A,f=1;
      }
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
 
    cin>>n>>m>>k;
 
    Matrix adj = weigth(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        a--;b--;
        adj[a][b]= min(adj[a][b],c);
    }
 
    adj = pow(adj,k);
    cout<<(adj[0][n-1]==INF ? -1 : adj[0][n-1])<<ENDL;
 
 
    return 0;
}
