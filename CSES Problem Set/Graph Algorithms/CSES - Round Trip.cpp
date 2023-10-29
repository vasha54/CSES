/**
* CSES - Round Trip
* Tematica : Teoria de Grafos : Detención de ciclos en grafo no dirigido
* Idea: Dado un grafo no dirigido detectar si existe o no ciclo.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 200010
#define EPS 1e-9
#define INF 1000000000
#define READ_FILE freopen("Input.txt","r",stdin);
#define int long long

using namespace std;


int n,m,u,v;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) { //pasando el vertice y su vertice padre
   visited[v] = true;
   for (int u : adj[v]) {
      if (u == par) continue; // arista al vertice padre
      if (visited[u]) {
         cycle_end = v; cycle_start = u;
         return true;
      }
      parent[u] = v;
      if (dfs(u, parent[u])) return true;
   }
   return false;
}

void findCycle() {
   visited.assign(n, false);
   parent.assign(n, -1);
   cycle_start = -1;

   for (int v = 0; v < n; v++) {
      if (!visited[v] && dfs(v, parent[v])) break;
   }

   if (cycle_start == -1) { cout << "IMPOSSIBLE" << ENDL;}
   else {
      vector<int> cycle;
      cycle.push_back(cycle_start);
      for (int v = cycle_end; v != cycle_start; v = parent[v]) cycle.push_back(v);
      cycle.push_back(cycle_start);

      cout << cycle.size()<<ENDL;
      for (int v : cycle) cout << v << " ";
      cout << ENDL;
   }
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE

    cin>>n>>m;
    n+=5;
    adj.resize(n);

    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findCycle();

    return 0;
}
