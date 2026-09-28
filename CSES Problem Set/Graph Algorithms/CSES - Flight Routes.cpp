/**
 * CSES - Flight Routes
 * Temática: Grafos, Dijkstra modificado, K caminos más cortos
 *
 * Idea: Se deben encontrar las K rutas más baratas desde la ciudad 1 hasta la
 * ciudad n en un grafo dirigido con pesos positivos. Una ruta puede visitar
 * la misma ciudad varias veces. Si hay varias rutas con el mismo precio, cada
 * una cuenta por separado.
 *
 * Se utiliza una variante del algoritmo de Dijkstra donde, en lugar de
 * mantener una única distancia mínima por nodo, se mantienen hasta K
 * distancias mínimas. Para ello:
 *   1. Se usa una cola de prioridad global que almacena pares (distancia, nodo).
 *   2. Para cada nodo se mantiene un contenedor (por ejemplo, un multiset o un
 *      vector ordenado) con sus K mejores distancias encontradas hasta ahora.
 *   3. Al extraer un estado (d, u) de la cola, si d no está en el contenedor
 *      de u (ya fue reemplazado por una mejor), se ignora.
 *   4. Para cada arista (u, v, w), se calcula nd = d + w. Si el contenedor de v
 *      tiene menos de K elementos, se inserta nd. Si ya tiene K y nd es menor
 *      que la mayor distancia almacenada, se elimina esa mayor y se inserta nd.
 *      En ambos casos se encola (nd, v).
 *   5. Al final, el contenedor del nodo n contendrá las K distancias más
 *      pequeñas, que se imprimen en orden ascendente.
 *
 * Complejidad: O(m * k * log(n * k)) en el peor caso, adecuada para
 * n ≤ 1e5, m ≤ 2e5 y k ≤ 10.
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

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    int n, m, k, a, b, c;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vector<multiset<int>> best(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    best[1].insert(0);
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        auto it = best[u].find(d);
        if (it == best[u].end()) continue;

        for (auto [v, w] : graph[u]) {
            int nd = d + w;

            if ((int)best[v].size() < k) {
                best[v].insert(nd);
                pq.push({nd, v});
            } else if (nd < *best[v].rbegin()) {
                auto it_max = prev(best[v].end());
                best[v].erase(it_max);
                best[v].insert(nd);
                pq.push({nd, v});
            }
        }
    }

    for (int d : best[n]) {
        cout << d << ' ';
    }
    cout << ENDL;

    return 0;
}