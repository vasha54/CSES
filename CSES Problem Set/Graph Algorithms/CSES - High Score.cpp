/**
 * CSES - High Score
 * Temática: Grafos, Bellman-Ford, Detección de ciclos positivos
 *
 * Idea: Se busca la puntuación máxima desde el nodo 1 hasta el nodo n en un
 * grafo dirigido con pesos que pueden ser negativos. Si se puede obtener una
 * puntuación arbitrariamente grande (es decir, existe un ciclo de peso
 * positivo alcanzable desde 1 y que puede llegar a n), se imprime -1.
 *
 * Solución:
 * 1. Negamos todos los pesos para convertir el problema de camino máximo en
 *    camino mínimo.
 * 2. Ejecutamos Bellman-Ford desde el nodo 1 durante n-1 iteraciones para
 *    obtener las distancias mínimas (en el grafo negado).
 * 3. En la n-ésima iteración, si algún nodo mejora, significa que existe un
 *    ciclo negativo (positivo en el original). Marcamos todos esos nodos.
 * 4. Propagamos la marca a todos los nodos alcanzables desde ellos (BFS/DFS)
 *    y verificamos si alguno de esos nodos puede alcanzar el nodo n (BFS/DFS
 *    en el grafo original).
 * 5. Si existe un ciclo positivo que cumple ambas condiciones, imprimimos -1.
 *    En caso contrario, la respuesta es -dist[n] (negamos de vuelta).
 *
 * Complejidad: O(n * m) para Bellman-Ford + O(n + m) para BFS. Con n ≤ 2500
 * y m ≤ 5000, es más que suficiente.
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
#define MAX_N 10005
#define MAX_PRIMES 2000010
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2
#define OO 4000000000000000000

using namespace std;

using ll = long long;

const ll INF = 4e18;   

struct Edge {
    int u, v;
    ll w;
};


signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<int>> graph(n + 1), rev_graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        edges.push_back({a, b, -x});   
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (const auto& e : edges) {
            if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    vector<int> affected;
    for (const auto& e : edges) {
        if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
            affected.push_back(e.v);
        }
    }

    if (affected.empty()) {
        cout << -dist[n] << ENDL;
    }else{

        vector<bool> from_cycle(n + 1, false);
        queue<int> q;
        for (int v : affected) {
            if (!from_cycle[v]) {
                from_cycle[v] = true;
                q.push(v);
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (!from_cycle[v]) {
                    from_cycle[v] = true;
                    q.push(v);
                }
            }
        }

        vector<bool> to_n(n + 1, false);
        q.push(n);
        to_n[n] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : rev_graph[u]) {
                if (!to_n[v]) {
                    to_n[v] = true;
                    q.push(v);
                }
            }
        }

        bool node_affected = false;
        for (int i = 1; i <= n && !node_affected; ++i) {
            if (from_cycle[i] && to_n[i]) {
                node_affected = true;
            }
        }
        cout<<( node_affected ? -1 : -dist[n])<<ENDL;
    }

    return 0;
}