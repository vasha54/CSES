/**
 * CSES - Sliding Window Median
 * Temática: Sliding Window
 * 
 * Idea: Mantenemos un árbol de estadísticos de orden (multiset con acceso por índice)
 *       que contiene los elementos de la ventana actual. Para cada nueva ventana
 *       insertamos el nuevo elemento, eliminamos el que sale (si existe) y consultamos
 *       la mediana como el elemento en la posición (k-1)/2 (mediana inferior).
 *       Como el árbol es de la librería PBDS de GNU, todas las operaciones
 *       (inserción, borrado, búsqueda por orden) son O(log k).
 */
#include <bits/stdc++.h>
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
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 110
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<int, int>,        // clave: (valor, id único)
    null_type,             // sin valor mapeado
    less<pair<int, int>>,  // comparador por valor y luego id
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

int mov_r [] ={ 0, 0, 1,-1};
int mov_c [] ={ 1,-1, 0, 0};


signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int n, k, median, val;
    cin >> n >> k;
    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];

    ordered_set window;

    for (int i = 0; i < n; i++) {
        
        window.insert({values[i],i});

        if (i >= k) {
            val = values[i - k];
            auto it = window.lower_bound({val, 0});
            if (it != window.end() && it->first == val) {
                window.erase(it);
            }
        }
        if (i >= k - 1) {
            median = window.find_by_order((k - 1) / 2)->first;
            cout << median << " ";
        }
    }
    cout << ENDL;

    return 0;
}