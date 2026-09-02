/**
 * CSES - Substring Distribution
 * Temática: Autómata de Sufijos (Suffix Automaton), Conteo por longitudes
 *
 * Idea: Dada una cadena T de longitud n, se debe imprimir para cada longitud
 * L desde 1 hasta n cuántas subcadenas distintas de exactamente longitud L
 * aparecen en T.
 *
 * Se construye el autómata de sufijos de T. Cada estado v representa un
 * conjunto de subcadenas que tienen longitudes en el intervalo:
 *     [minlen(v), len(v)]
 * donde minlen(v) = len(link(v)) + 1.
 *
 * Todas las subcadenas representadas por v son distintas entre sí y además
 * aportan exactamente una subcadena distinta por cada longitud en ese
 * intervalo. Por lo tanto, para cada estado v != raíz:
 *     para longitudes L en [minlen(v), len(v)] hay una subcadena distinta.
 *
 * Para obtener la cantidad por longitud de manera eficiente, usamos un
 * arreglo de diferencias diff[1..n+1]:
 *     diff[minlen(v)] += 1
 *     diff[len(v)+1]  -= 1
 * Luego hacemos una suma prefijo para obtener ans[L].
 *
 * Complejidad: O(n) si se usa arreglo de transiciones (alfabeto fijo),
 * o O(n log σ) con map, donde σ = 26. Suficiente para n ≤ 10^5.
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
#define MAX_N 100100
#define SHIT 500
#define MAXTREE  (MAX_N << 2)
#define MOD 97654321
#define MAXLETTERS 52 // 26 mayúsculas + 26 minúsculas
#define OFFSET 200
#define INF 1e18
#define INF_NEG -1e18
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define tiii tuple<int,int,int>
#define midle (left+right)/2   

using namespace std;
using namespace __gnu_pbds;


int mov_r[] = { 0, 0, 1,-1};
int mov_c[] = { 1,-1, 0, 0};

struct state {
    int len, link;
    map<char, int> next; 
};

state st[MAX_N * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

signed main()
{
    PRESICION(2)
    READ_FILE
    //WRITE_FILE

    string text;
    cin >> text;
    int n = text.size();

    sa_init();
    for (char c : text) {
        sa_extend(c);
    }

    vector<int> diff(n + 2, 0);

    for (int v = 1; v < sz; v++) {
        int min_len = st[st[v].link].len + 1;
        int max_len = st[v].len;
        diff[min_len]++;
        diff[max_len + 1]--;
    }

    vector<int> ans(n + 1, 0);
    int running = 0;
    for (int len = 1; len <= n; len++) {
        running += diff[len];
        ans[len] = running;
    }

    for (int len = 1; len <= n; len++) {
        if (len > 1) cout << ' ';
        cout << ans[len];
    }
    cout << ENDL;

    return 0;
}