/*
* CSES - Flight Routes Check
* Tematica: Teoria de grafos: Componentes fuertemente conexa
*
* Idea: Dado grafo determinar si existe o no una sola componente fuertemente
* conexa
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

vector<int> adj[MAX_N], adj_rev[MAX_N];// G y G'
vector<bool> used1,used2;
int n,nedges,a,b; //cantidad de nodos y aristas

void dfs1(int v,int p=0) {
   used1[v] = true;
   for (int u : adj[v]) if ( u!=p && !used1[u]) dfs1(u,v);
}

void dfs2(int v,int p=0) {
   used2[v] = true;
   for (int u : adj_rev[v]) if( u!=p && !used2[u]) dfs2(u,v);
}

void solve() {
   used1.assign(MAX_N, false);
   used2.assign(MAX_N, false);
   dfs1(1);
   dfs2(1);
   bool singleSCC= true;
   for(int i=1;i<=n;i++)
   {
        if(!used1[i] || !used2[i]){
            singleSCC = false;
            cout<<"NO"<<ENDL;
            if(!used1[i]) cout<<"1 "<<i<<ENDL;
            else cout<<i<<" 1"<<ENDL;
            break;
        }
    }
    if(singleSCC) cout<<"YES"<<ENDL;
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>n>>nedges;
    for(int i=0;i<nedges;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    solve();
    return 0;
}
