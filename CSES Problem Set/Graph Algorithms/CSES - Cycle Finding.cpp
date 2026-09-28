/**
 * CSES - Cycle Finding
 * Temática: Grafos, Bellman-Ford, Detección y reconstrucción de ciclos negativos
 *
 * Idea: Se debe encontrar un ciclo de peso negativo en un grafo dirigido y
 * devolver la secuencia de nodos que lo forman.
 *
 * Se utiliza el algoritmo de Bellman-Ford con un array de padres (parent[])
 * para reconstruir el camino. Inicializamos todas las distancias a 0 (lo que
 * equivale a añadir un super-nodo fuente conectado a todos los nodos con peso 0,
 * garantizando así que cualquier ciclo negativo sea detectado, incluso si no es
 * alcanzable desde un nodo específico).
 *
 * Ejecutamos n iteraciones de relajación. En la n-ésima iteración (o en
 * cualquier iteración n-1 + 1), si alguna arista todavía puede relajarse,
 * significa que existe un ciclo negativo. El nodo v de esa arista está
 * afectado por el ciclo. Para obtener un nodo que esté **dentro** del ciclo,
 * retrocedemos n pasos usando parent[] (pues cualquier camino de longitud n
 * contiene necesariamente un ciclo). Luego, desde ese nodo, seguimos los
 * punteros parent[] hasta volver al mismo nodo, construyendo así el ciclo.
 *
 * Complejidad: O(n * m) para las n iteraciones de Bellman-Ford, más O(n) para
 * la reconstrucción. Con n ≤ 2500 y m ≤ 5000, es muy eficiente.
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

const int INF = 4e18;   

struct Edge {
    int u, v;
    int weight;
};


signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    int n, m, a, b, c;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<int> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int cycle_node = -1;

    for (int i = 1; i <= n; ++i) {
        cycle_node = -1;
        for (const auto& e : edges) {
            if (dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
                parent[e.v] = e.u;
                if (i == n) cycle_node = e.v;
            }
        }
    }

    if (cycle_node == -1) {
        cout << "NO"<<ENDL;
    }else{
        for (int i = 0; i < n; ++i) {
            cycle_node = parent[cycle_node];
        }

        vector<int> cycle;
        int cur = cycle_node;
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != cycle_node && cur != -1);
        reverse(cycle.begin(), cycle.end());
        cycle.push_back(cycle[0]); 

        cout << "YES"<<ENDL;

        for (int i = 0; i < (int)cycle.size(); ++i) {
            if (i > 0) cout << ' ';
            cout << cycle[i];
        }
        cout << ENDL;
    }

    return 0;
}