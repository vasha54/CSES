/**
 * CSES - Company Queries I.
 * 
 * Temática: Estructura de Datos + Sparse Table
 * 
 * Idea: Dado una estructura de jerarquía de una empresa en forma de árbol se 
 * quiere conocer para un trabajor x quien es su jefe k-ensimo superior siendo
 * su jefe inmediato k=1 y el jefe de este k=2 y asi sucesivamente hasta llegar hasta
 * el jefe principal de la empresa.
 * 
 * La idea es construir una matriz donde en [i,j] donde vamos almacer el i-nesimo jefe
 * inmediato del trabajador j. La cantidad de filas de la matriz es log2(N)+1 donde N es la 
 * cantidad de trabajadores.
 */ 
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 200010
#define MAX_TREE (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 

const int ROW_SPARSE_TABLE = floor(log2(MAX_N) +1 );
 
using namespace std;
using namespace __gnu_pbds;

int nworkers, nqueries, x, k;
int st[ROW_SPARSE_TABLE][MAX_N];

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
	cin>>nworkers>>nqueries;
	for(int i=2;i<=nworkers;i++){
		cin>>st[0][i];
		}
	for(int r=1;r<ROW_SPARSE_TABLE;r++){
		for(int c=1;c<=nworkers;c++){
			st[r][c] = st[r-1][ st[r-1][c] ];
			}
		}
	for(int q=1; q<=nqueries; q++){
		cin>>x>>k;
		for(int i = 0; i < ROW_SPARSE_TABLE; i++)
            if(k&(1<<i)) x = st[i][x];
		cout<<( x ? x : -1 )<<ENDL;
		}
    return 0;
}

