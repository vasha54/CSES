/**
* CSES - Building Teams
* Tematica : Teoria de grafos: Grafo Bipartido
* Idea: Dado un grupo de personas y la relación de amistades que existen entre dichas personas
* se desea saber si se pueden conformar dos grupos con la condicíon de que las personas que conformen
* el mismo grupo no exista un par que sean amigos. Si modelamos el problema como un grafo donde las personas
* sean los nodos del grafo y va exisitir una arista entre dos nodos si esas personas son amigas la solución
* al problema ver si con el grafo que se construye dicho grafo es bipartido.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 2000010
#define EPS 1e-9
#define INF 1LL<<60
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define int long long
#define uint unsigned int

using namespace std ;

void is_bipartite(vector<vector<int>> adj, int nnodes){
    vector<int> side(nnodes, -1);
    bool bipartite = true;
    queue<int> q;
    for (int st = 0; st < nnodes; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    }
                    else {
                        bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    if(bipartite){
        for(int st = 0; st < nnodes; ++st){
            if(st)cout<<" ";
            cout<<side[st]+1;
        }
        cout<<ENDL;
    }
    else{
        cout<<"IMPOSSIBLE"<<ENDL;
    }
}


signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int npersons, nrelations,a,b;
    cin>>npersons>>nrelations;
    vector<vector<int>> ady(npersons);
    for(int i=0;i<nrelations;i++)
    {
        cin>>a>>b;
        a--;b--;
        ady[a].push_back(b);
        ady[b].push_back(a);
    }
    is_bipartite(ady,npersons);
    return 0;
}
