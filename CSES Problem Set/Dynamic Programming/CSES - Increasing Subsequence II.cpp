/**
 * CSES - Increasing Subsequence II
 * Temática: Estructura de Datos: Fenwick Tree + Compresión de coordenadas
 *
 * Idea: Para contar todas las subsecuencias estrictamente crecientes de un arreglo,
 * se utiliza programación dinámica con la recurrencia dp[i] = 1 + Σ dp[j]
 * para todo j < i con a[j] < a[i]. La suma sobre valores menores sugiere
 * mantener una estructura que acumule, para cada posible valor, la cantidad
 * de subsecuencias que terminan con ese valor. Como los valores originales
 * pueden ser grandes (hasta 1e9), primero se aplica compresión de coordenadas
 * para mapearlos al rango [1, m], donde m es el número de valores únicos.
 * Luego, un árbol Fenwick (BIT) permite consultar la suma de dp de todos los
 * valores menores que el actual en O(log m), y actualizar la posición del
 * valor actual sumándole su dp. Esto reduce la complejidad total a O(n log n),
 * suficiente para n = 2·10^5. La respuesta final es la suma de todos los dp,
 * tomando siempre módulo 1e9+7.
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
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 20
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] = (bit[idx] + delta) % MOD;
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res = (res + bit[idx]) % MOD;
        return res;
    }
};

int comp(const vector<int>& vals, int x) {
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
}

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();
    Fenwick ft(m);
    int total_subsequence = 0;

    for (int x : a) {
        int pos = comp(vals, x);
        int count_subsequence = ft.query(pos - 1);   
        int dp = (1 + count_subsequence) % MOD;
        total_subsequence = (total_subsequence + dp) % MOD;
        ft.update(pos, dp);                
    }

    cout << total_subsequence << ENDL;

    return 0;
}