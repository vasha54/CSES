/*
* CSES - Planets and Kingdoms
* Tematica: Teoria de grafos: Componentes fuertemente conexa
*
* Idea: Dado grafo hallar la cantidad de componentes fuertemente conexa y a cual pertence
* cada nodo
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
#define MOD 1000000007
#define EPS 1e-4
#define INF 0x3f3f3f3f3f3f3f3f
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
#define CELL_FREE '.'
#define CELL_WALL '#'
#define PRINT_LINE cout<<ENDL;
using namespace std;
using namespace __gnu_pbds;
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};

vector<vector<int>> adj, adj_rev;// G y G'
vector<bool> used;
vector<int> order, component;
int n,nedges,a,b; //cantidad de nodos y aristas

void dfs1(int v) {
   used[v] = true;
   for (auto u : adj[v]) if (!used[u]) dfs1(u);
   order.push_back(v);
}

void dfs2(int v) {
   used[v] = true; component.push_back(v);
   for (auto u : adj_rev[v]) if (!used[u]) dfs2(u);
}

void sccKosaraju() {
   used.assign(n, false);
   for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
   used.assign(n, false);
   reverse(order.begin(), order.end());

   vector<int> roots(n, 0); vector<int> root_nodes;
   vector<vector<int>> adj_scc(n);
   vector<int> component_ssc(n);
   for (auto v : order)
      if(!used[v]) {
         dfs2(v);
         int root = component.front();
         for (auto u : component)
            roots[u] = root;
         root_nodes.push_back(root);
         for(auto x: component){
            component_ssc[x]= root_nodes.size();
         }
         component.clear();
      }

    cout<<root_nodes.size()<<ENDL;
    for(auto k: component_ssc){
        cout<<k<<" ";
    }
    cout<<ENDL;
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>n>>nedges;
    adj.reserve(n);
    adj_rev.reserve(n);
    for(int i=0;i<nedges;i++){
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    sccKosaraju();
    return 0;
}
