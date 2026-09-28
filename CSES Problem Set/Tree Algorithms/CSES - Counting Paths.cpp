/**
 * CSES - Counting Paths
 * Temática: LCA + Programación Dinámica
 *
 * Idea: Dado un árbol con N nodos y Q consultas, cada consulta representa un 
 * camino entre dos nodos (a, b). Se necesita calcular para cada nodo cuántos 
 * de esos caminos pasan por él.
 *
 * Se utiliza una técnica de diferencias sobre nodos combinada con LCA.
 * Cada camino a↔b se descompone en dos segmentos ascendentes:
 *   a → LCA(a,b)   y   b → LCA(a,b).
 * Para cada camino marcamos:
 *   - Un "inicio" en a y en b (paths_starting[a]++ y paths_starting[b]++).
 *   - Un "fin" en LCA(a,b) (paths_ending[lca]++).
 *
 * Luego, un DFS acumula los caminos desde las hojas hacia la raíz:
 *   current_paths = paths_starting[node] + suma de los valores devueltos por
 *   los hijos.
 *
 * Al llegar a un nodo restamos una vez paths_ending[node] para registrar
 * la respuesta (los caminos que efectivamente pasan por ese nodo, ya que los
 * que terminan allí no deben propagarse más arriba). Después restamos una
 * segunda vez paths_ending[node] para que el padre no reciba esos caminos,
 * pues más arriba del LCA el camino ya no existe.
 *
 * Esta doble resta corrige el conteo doble que ocurre en el LCA (donde
 * confluyen los dos inicios). La respuesta final para cada nodo queda
 * almacenada en paths_node.
 *
 * Preprocesamos LCA con tabla de ancestros (up) y profundidades (depth)
 * en O(N log N), y el DFS de acumulación en O(N). La complejidad total
 * es O((N+Q) log N), suficiente para N, Q ≤ 2·10⁵
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
#define MAX_N 200000
#define MAXTREE  (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define midle (left+right)/2   

using namespace std;
using namespace __gnu_pbds;

int depth[MAX_N], paths_starting[MAX_N], paths_ending[MAX_N], paths_node[MAX_N];
int up[MAX_N][20];
vector<int> trees[MAX_N];

void dfs(int node, int parent) {
    up[node][0] = parent;
    for (int child : trees[node]) {
        if (child == parent) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    int depth_difference = depth[a] - depth[b];
    for (int j = 19; j >= 0; --j) {
        if ((1 << j) & depth_difference) a = up[a][j];
    }
    if (a == b) return a;
    else {
        for (int j = 19; j >= 0; --j) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }
}

int dfs_paths(int node, int parent) {
    int current_paths = paths_starting[node];
    for (int child : trees[node]) {
        if (child == parent) continue;
        current_paths += dfs_paths(child, node);
    }
    
    current_paths -= paths_ending[node];
    paths_node[node] = current_paths;
    current_paths -= paths_ending[node];
    return current_paths;
}


signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int nnodes, nquerys;
    cin>>nnodes>>nquerys;

    for (int i = 0; i < nnodes - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        trees[a].push_back(b);
        trees[b].push_back(a);
    }

    dfs(0, 0);

    for (int j = 0; (1 << j) <= nnodes; ++j) {
        for (int i = 0; i < nnodes; ++i) {
            up[i][j + 1] = up[up[i][j]][j];
        }
    }

    for (int i = 0; i < nquerys; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int c = lca(a, b);
        paths_starting[a]++;
        paths_starting[b]++;
        paths_ending[c]++;
    }

    dfs_paths(0, 0);

    for (int i = 0; i < nnodes; ++i) cout << paths_node[i] << ' ';
    cout << ENDL;

    return 0;
}