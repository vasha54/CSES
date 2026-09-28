/**
 * CSES - Counting Patterns
 * Temática: Autómata de Sufijos (Suffix Automaton), Conteo de ocurrencias
 *
 * Idea: Dada una cadena T y varios patrones P, para cada patrón se debe
 * contar el número de posiciones donde aparece como subcadena de T.
 * Se construye el autómata de sufijos de T. Cada estado del autómata
 * representa un conjunto de subcadenas que comparten el mismo endpos
 * (conjunto de posiciones finales de ocurrencias). El tamaño de ese
 * conjunto es el número de ocurrencias de cualquier subcadena en el estado.
 *
 * Para calcular estos tamaños:
 *   1. Al construir el autómata, los estados creados al añadir cada carácter
 *      (no clones) corresponden a prefijos de T y reciben cnt = 1.
 *   2. Los clones se crean con cnt = 0.
 *   3. Se ordenan los estados por longitud decreciente y se propaga:
 *        cnt[link[v]] += cnt[v].
 *      Así, cada estado obtiene el número total de ocurrencias de las
 *      subcadenas que representa.
 *
 * Para responder un patrón P:
 *   - Se recorre el autómata desde el estado inicial siguiendo las
 *     transiciones de los caracteres de P.
 *   - Si en algún momento no existe transición, la respuesta es 0.
 *   - Si se completa el recorrido, la respuesta es cnt[estado_final].
 *
 * Complejidad: O(|T| + Σ|P|) con arreglo de transiciones, u
 *              O(|T| log σ + Σ|P| log σ) con map, donde σ = 26.
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
int cnt[MAX_N * 2];       

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
    cnt[0] = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    cnt[cur] = 1;             
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
            cnt[clone] = 0;     
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void process_counts(int n) {
    vector<int> order(sz);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [](int a, int b) {
        return st[a].len > st[b].len;
    });
    for (int v : order) {
        if (st[v].link != -1) {
            cnt[st[v].link] += cnt[v];
        }
    }
}

int query_pattern(const string &p) {
    int v = 0;
    for (char c : p) {
        if (!st[v].next.count(c)) return 0;
        v = st[v].next[c];
    }
    return cnt[v];
}

signed main()
{
    PRESICION(2)
    READ_FILE
    //WRITE_FILE

    string text;
    cin >> text;

    sa_init();
    for (char c : text) {
        sa_extend(c);
    }
    process_counts(text.size());

    int k;
    cin >> k;
    while (k--) {
        string pat;
        cin >> pat;
        cout << query_pattern(pat) << '\n';
    }

    return 0;
}