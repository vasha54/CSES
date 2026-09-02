/**
 * CSES - Distinct Substrings
 * Temática: Autómata de Sufijos (Suffix Automaton), Conteo de subcadenas
 *
 * Idea: Dada una cadena T, contar cuántas subcadenas distintas aparecen en
 * ella. El autómata de sufijos de T es un DAG que representa todas las
 * subcadenas: cada camino desde el estado inicial corresponde a una
 * subcadena distinta. Por tanto, el número de subcadenas distintas es igual
 * al número de caminos desde el estado inicial.
 *
 * Se puede calcular sin DP recursiva: cada estado v (excepto la raíz)
 * representa subcadenas de longitudes [minlen(v), len(v)]. Como
 * minlen(v) = len(link(v)) + 1, el número de subcadenas nuevas en v es:
 *        len(v) - len(link(v))
 * La suma sobre todos los estados v != 0 es el número total de subcadenas
 * distintas.
 *
 * Complejidad: O(n) con arreglo de transiciones, u O(n log σ) con map.
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

long long count_distinct_substrings() {
    long long ans = 0;
    for (int i = 1; i < sz; ++i) {
        ans += st[i].len - st[st[i].link].len;
    }
    return ans;
}

signed main()
{
    PRESICION(2)
    READ_FILE
    //WRITE_FILE

    string s;
    cin >> s;

    sa_init();
    for (char c : s) {
        sa_extend(c);
    }

    cout << count_distinct_substrings() << ENDL;

    return 0;
}