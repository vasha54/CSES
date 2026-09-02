/**
 * CSES - Distance Queries
 * Temática: LCA
 * 
 * Idea: La distancia entre dos nodos en un árbol se puede obtener como
 * dist(a,b) = depth[a] + depth[b] - 2*depth[lca(a,b)].
 * Para calcular el LCA eficientemente usamos binary lifting con preprocesamiento
 * de tiempos de entrada/salida (Euler tour) para verificar ancestros en O(1).
 * Preprocesamiento: DFS desde la raíz (1) para calcular depth, tin, tout y la tabla up.
 * LCA: Si uno es ancestro del otro, se devuelve ese; si no, se levanta el nodo más profundo
 * con saltos de potencias de 2 hasta quedar justo debajo del LCA, y luego se retorna su padre.
 * Complejidad: O((n+q) log n) en tiempo, O(n log n) en memoria.
 */
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);

#ifdef LOCAL
    #define READ_FILE freopen("Input.txt","r",stdin);
    #define WRITE_FILE freopen("Output.txt","w",stdout);
#else
    #define READ_FILE 
    #define WRITE_FILE 
#endif
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 200010
#define MAXTREE  (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define midle (left+right)/2   // OJO: rigth en lugar de right, se mantiene el original

using namespace std;
using namespace __gnu_pbds;

vector<vector<int> > trees, up;
vector<int> depth, tin, tout;
int nnodes, nquerys, a, b, l, timer, LCA;

void dfs(int v, int p){
   tin[v] = ++timer; 
   up[v][0] = p;
   
   for (int i = 1; i <= l; ++i) 
        up[v][i] = up[up[v][i-1]][i-1];
   
   for (int u : trees[v]) {
      if (u != p){
        depth[u] = depth[v] + 1;
        dfs(u, v);
      } 
        
   }
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
   tin.resize(nnodes+1); 
   tout.resize(nnodes+1);
   timer = 0; 
   l = ceil(log2(nnodes+1));
   up.assign(nnodes+1, vector<int>(l + 1));
   depth[root] = 1;
   dfs(root, root);
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    cin>>nnodes>>nquerys;
    trees.resize(nnodes+1);
    depth.resize(nnodes+1);

    for(int i=1;i<nnodes;i++){
        cin>>a>>b;
        trees[a].push_back(b);
        trees[b].push_back(a);
    }

    preprocess(1);

    for(int i=1;i<=nquerys;i++){
        cin>>a>>b;
        LCA = lca(a,b);
        // cout<<"A:"<<a<<", B:"<<b<<", LCA:"<<LCA<<ENDL;
        // cout<<"d(A):"<<depth[a]<<", d(B):"<<depth[b]<<", d(LCA):"<<depth[LCA]<<ENDL;
        cout<<depth[a]+depth[b]-2*depth[LCA]<<ENDL;
    }

    
    return 0;
}