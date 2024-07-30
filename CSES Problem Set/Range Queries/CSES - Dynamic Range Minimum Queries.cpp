/*
* CSES - Dynamic Range Minimum Queries
* Tematica: Estructuras de Datos + Range Tree
* Idea: Idea clasica para utilizar un Range Tree. Una colección de datos
* sobre la cual se realiza dos operaciones una actualización de valor sobre la posición
* y otra consulta del minimo valor en un rango [a,b]
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 200010
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
#define MOD 1000000007
#define EPS 1e-4
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE ' '
#define PRINT_LINE cout<<ENDL;
using namespace std;

int nvalues,nqueries,querie,x,y;

int niz[MAX_N];
int RT[MAX_TREE];

void InitTree(int idx, int left, int right){
   if(left == right){
     RT[idx] = niz[left];return;
   }
   InitTree(2*idx, left, MID);
   InitTree(2*idx+1, MID+1, right);
   RT[idx] = min(RT[2*idx], RT[2*idx+1]);
}

void Update(int idx, int x, int val, int left, int right){
   if(left == right){
     RT[idx] = val;return;
   }
   if (x <= MID) Update(2*idx, x, val, left, MID);
   else Update(2*idx+1, x, val, MID+1, right);
   RT[idx] = min(RT[2*idx], RT[2*idx+1]);
}

int Query(int idx, int l, int r, int left, int right){
   if (l <= left && right <= r) return RT[idx];
   int ret = LONG_MAX;
   if (l <= MID) ret = min(ret, Query(2*idx, l, r, left, MID));
   if (r > MID) ret = min(ret, Query(2*idx+1, l, r, MID+1, right));
   return ret;
}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>nvalues>>nqueries;
    for(int i=1;i<=nvalues;i++) cin>>niz[i];
    InitTree(1, 1, nvalues);

    for(int i=0;i<nqueries;i++){
        cin>>querie>>x>>y;
        switch(querie)
        {
            case 1: Update(1, x, y, 1, nvalues); break;
            case 2: cout<<Query(1,x,y,1,nvalues)<<ENDL; break;
        }
    }
    return 0;
}
