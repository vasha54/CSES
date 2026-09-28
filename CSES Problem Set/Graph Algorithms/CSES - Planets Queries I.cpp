/**
 * CSES - Planets Queries I
 * Temática: Grafos funcionales, Binary Lifting
 *
 * Idea: Cada planeta tiene un único teleportador que lleva a otro planeta
 * (posiblemente a sí mismo). Esto define un grafo funcional donde cada nodo
 * tiene exactamente una arista saliente. Para cada consulta (x, k) se debe
 * determinar a qué planeta se llega partiendo de x y atravesando exactamente
 * k teleportadores.
 *
 * Como k puede ser hasta 10^9, no se puede simular paso a paso. Se utiliza
 * la técnica de Binary Lifting (salto binario):
 *
 * 1. Precalcular una tabla up[i][j] = planeta al que se llega partiendo de i
 *    después de 2^j saltos.
 *      up[i][0] = t_i (el teleportador directo de i)
 *      up[i][j] = up[ up[i][j-1] ][j-1]
 *
 * 2. Para responder una consulta (x, k), se descompone k en sus bits. Por
 *    cada bit j que esté encendido en k, se actualiza x = up[x][j]. Al
 *    terminar, x es el planeta destino.
 *
 * Complejidad:
 *   - Precalculo: O(n log K) donde log K = 30.
 *   - Cada consulta: O(log K) = O(30).
 *   - Total: O((n + q) log K), adecuado para n, q ≤ 2·10^5.
 *
 * El máximo exponente es 30 porque 2^30 > 10^9.
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
#define MAX_N 200005
#define MAXD 31
#define MAX_PRIMES 2000010
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2
#define OO 4000000000000000000

using namespace std;

int up[MAX_N][MAXD];



signed main() {
    OPTIMIZAR_IO
    //PRESICION(0)
    READ_FILE
    //WRITE_FILE
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> up[i][0];
    }

    for (int j = 1; j < MAXD; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }

    while (q--) {
        int x;
        long long k;
        cin >> x >> k;
        for (int j = 0; j < MAXD; ++j) {
            if (k & (1LL << j)) {
                x = up[x][j];
            }
        }

        cout << x << ENDL;
    }
    return 0;
}