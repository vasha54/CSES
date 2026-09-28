/**
 * CSES - Investigation
 * Temática: Grafos, Dijkstra
 *
 * Idea: Se deben responder cuatro preguntas sobre los caminos desde el nodo 1
 * hasta el nodo n en un grafo dirigido con pesos positivos:
 *   1. Precio mínimo.
 *   2. Número de caminos de precio mínimo (mód 1e9+7).
 *   3. Mínimo número de vuelos en un camino de precio mínimo.
 *   4. Máximo número de vuelos en un camino de precio mínimo.
 *
 * Solución: Se utiliza una versión extendida del algoritmo de Dijkstra.
 * Para cada nodo se mantienen cuatro arreglos:
 *   dist[u]     : distancia mínima desde 1 hasta u.
 *   count_min[u]: número de caminos de distancia mínima desde 1 hasta u.
 *   min_edge[u] : mínimo número de aristas en un camino mínimo de 1 a u.
 *   max_edge[u] : máximo número de aristas en un camino mínimo de 1 a u.
 *
 * Inicialización:
 *   dist[1] = 0, count_min[1] = 1, min_edge[1] = 0, max_edge[1] = 0.
 *   Para los demás nodos: dist = OO, count_min = 0, min_edge = OO, max_edge = 0.
 *
 * Durante la relajación de una arista (u, v, w):
 *   - Si dist[u] + w < dist[v]: se ha encontrado un camino más corto.
 *       dist[v]      = dist[u] + w
 *       count_min[v] = count_min[u]
 *       min_edge[v]  = min_edge[u] + 1
 *       max_edge[v]  = max_edge[u] + 1
 *   - Si dist[u] + w == dist[v]: se ha encontrado otro camino de igual
 *     distancia mínima.
 *       count_min[v] = (count_min[v] + count_min[u]) % MOD
 *       min_edge[v]  = min(min_edge[v], min_edge[u] + 1)
 *       max_edge[v]  = max(max_edge[v], max_edge[u] + 1)
 *
 * Detalle clave de eficiencia:
 *   Al extraer un nodo de la cola de prioridad, se verifica si su distancia
 *   coincide con la almacenada en dist[]. Si es mayor, la entrada es obsoleta
 *   y se descarta con `continue`. Esto evita procesar el mismo nodo varias
 *   veces y garantiza la complejidad O((n+m) log n).
 *
 * Al final, la respuesta para el nodo n es:
 *   dist[n], count_min[n], min_edge[n], max_edge[n].
 *
 * Complejidad: O((n + m) log n), adecuada para n ≤ 1e5 y m ≤ 2e5.
 */

#include <bits/stdc++.h>

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
#define int long long
#define REP(x) for(int i=0;i<x;i++)
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 100005
#define MAX_PRIMES 2000010
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2
#define OO 4000000000000000000

using namespace std;

struct Node{
    int dist;
    int count_min;
    int max_edge;
    int min_edge;
    vector<int> adj;
    vector<int> weight;
};
Node graf[MAX_N];
bool mark[MAX_N];
int nnodes,npath;


struct pq_entry{
    int node, dist;
    bool operator <(const pq_entry &a) const{
        if (dist != a.dist) return (dist > a.dist);
            return (node > a.node);
    }
};

inline void dijkstra(int source){
    priority_queue<pq_entry> pq;
    pq_entry P;
    for (int i=1;i<=nnodes;i++){
        
        if (i == source){
            graf[i].dist = 0;
            graf[i].count_min= 1;
            graf[i].max_edge = 0;
            graf[i].min_edge = 0;
            P.node = i;
            P.dist = 0;
            pq.push(P);
        }
        else{
            graf[i].dist = OO;
            graf[i].count_min=0;
            graf[i].max_edge = 0;
            graf[i].min_edge = OO;
        }
    }
    while (!pq.empty()){
        pq_entry curr = pq.top();
        pq.pop();
        int nod = curr.node;
        int dis = curr.dist;

        if (dis > graf[nod].dist) continue;

        for(int i=0;i<graf[nod].adj.size();i++){
                int nextNode = graf[nod].adj[i];
                if(dis + graf[nod].weight[i] < graf[nextNode].dist){
                    graf[nextNode].dist = dis + graf[nod].weight[i];
                    graf[nextNode].count_min = graf[nod].count_min;
                    graf[nextNode].min_edge = graf[nod].min_edge + 1;
                    graf[nextNode].max_edge = graf[nod].max_edge + 1;
                
                    P.node = nextNode;
                    P.dist = graf[nextNode].dist;
                    pq.push(P);
                }
                else if(dis + graf[nod].weight[i] == graf[nextNode].dist){
                    graf[nextNode].count_min = (graf[nextNode].count_min + graf[nod].count_min) % MOD;
                    graf[nextNode].min_edge = min(graf[nextNode].min_edge , graf[nod].min_edge + 1);
                    graf[nextNode].max_edge = max(graf[nextNode].max_edge , graf[nod].max_edge + 1);
                }
            
        }
        
    }
}



signed main() {
    OPTIMIZAR_IO
    //PRESICION(0)
    READ_FILE
    //WRITE_FILE
    cin>>nnodes>>npath;
    for(int i=0;i<npath;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graf[a].adj.push_back(b);
        graf[a].weight.push_back(c);
    }

    dijkstra(1);

    cout<<graf[nnodes].dist<<" "<<graf[nnodes].count_min<<" "<<graf[nnodes].min_edge<<" "<<graf[nnodes].max_edge<<ENDL;
    return 0;
}