/**
 * CSES - Tree Distance II
 * Temática: Programación Dinámica + Re-enraizamiento en Árboles
 * 
 * Idea: El problema pide, para cada nodo de un árbol, la suma de las distancias
 * a todos los demás nodos.
 * 
 * Técnica: rerooting DP.
 * 
 * 1. Enraizamos el árbol en un nodo arbitrario (aquí el 1).
 *    Hacemos una primera pasada DFS en postorden (dfs_posorden).
 *    Para cada nodo v calculamos:
 *    - sub_size[v] = tamaño del subárbol de v.
 *    - La función devuelve la suma de distancias desde v a todos los nodos
 *      dentro de su subárbol.
 * 
 *    Cálculo:
 *    Inicializamos sub_size[v] = 1 y distance_sum = 0.
 *    Para cada hijo u:
 *       distance_sum += dfs_posorden(u, v);   // suma interna del hijo
 *       sub_size[v] += sub_size[u];
 *    Al salir del bucle, añadimos sub_size[v] - 1 a distance_sum.
 *    Este término da cuenta del incremento de una unidad por cada nodo
 *    en el subárbol al conectar v con sus hijos. Para una hoja, sub_size=1,
 *    suma = 0, consistente.
 *    La respuesta para la raíz es directamente ese valor.
 * 
 * 2. Segunda pasada DFS en preorden (dfs_preorden) para propagar
 *    la respuesta a los demás nodos mediante re-enraizamiento.
 *    Si conocemos answer[parent], podemos obtener answer[child] así:
 *       answer[child] = answer[parent] - sub_size[child] + (n - sub_size[child])
 *    Explicación:
 *    Al mover la raíz de parent a child, los nodos en el subárbol de child
 *    se acercan una unidad → restamos sub_size[child].
 *    Los nodos fuera de ese subárbol (n - sub_size[child]) se alejan una unidad
 *    → sumamos n - sub_size[child].
 * 
 * Complejidad: O(n) en tiempo y O(n) en memoria.
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

vector<vector<int>> trees;
vector<int> sub_size;
vector<int> answer;

int nnodes, a, b;

int dfs_posorden(int v, int parent){
    sub_size[v] = 1;
    int distance_sum = 0;
    for (int u : trees[v]) {
      if (u == parent) continue;
      distance_sum += dfs_posorden(u, v);
      sub_size[v] += sub_size[u];
    }
    distance_sum += sub_size[v] - 1;
    return distance_sum;
}

void dfs_preorden(int v, int parent){
    for (int u : trees[v]) {
       if (u == parent) continue; 
       answer[u] = answer[v] - sub_size[u] + (nnodes - sub_size[u]);
       dfs_preorden(u, v);
    }
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    cin>>nnodes;
    trees.resize(nnodes+1);
    sub_size.resize(nnodes+1);
    answer.resize(nnodes+1);

    for(int i=1;i<nnodes;i++){
        cin>>a>>b;
        trees[a].push_back(b);
        trees[b].push_back(a);
    }

    answer[1] = dfs_posorden(1,1);
    dfs_preorden(1,1);

    for (int i = 1; i <= nnodes; ++i) {
        cout << answer[i] << ' ';
    }
    cout << ENDL;
    
    return 0;
}
