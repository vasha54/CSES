/**
 * CSES - Company Queries II.
 * 
 * Temática: Teoría de grafo + Ancestro común más bajo (LCA)
 * 
 * Idea: Dada la estructura de jerarquia de empleados/jefes de una empresa 
 * sabiendo que el jefe principal es 1. Se tiene una serie de preguntas de la
 * forma (A,B) para determinar el jefe más inmediato a los trabajadores A y B 
 * en el árbol de jerarquía de la  empresa. Para resolver el problema basta con 
 * construir el árbol y buscar entre los trabajadores A y B en el ancestro común
 * más bajo (LCA). 
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

int n, l, q, a, b;
vector<vector<int>> adj (MAX_N);

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p){
   tin[v] = ++timer; up[v][0] = p;
   for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i-1]][i-1];
   for (int u : adj[v]) { if (u != p) dfs(u, v); }
   tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
   return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) { 
   if (is_ancestor(u, v)) return u; 
   if (is_ancestor(v, u)) return v;
   for (int i = l; i >= 0; --i) {
      if (!is_ancestor(up[u][i], v)) u = up[u][i];
   }
   return up[u][0];
}

void preprocess(int root) {
   tin.resize(n+10); tout.resize(n+10);
   timer = 0; l = ceil(log2(n+10));
   up.assign(n+10, vector<int>(l + 1));
   dfs(root, root);
}

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    cin>>n>>q;
	for(int i=2;i<=n;i++){
		cin>>a;
		adj[a].push_back(i);
		}
	preprocess(1);
	REP_INDEX_1(q){
		cin>>a>>b;
		cout<<lca(a,b)<<ENDL;
		}
    return 0;
}

