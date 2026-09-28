/**
 * CSES - Finding Patterns
 * Temática: Autómata de Sufijos (Suffix Automaton), Búsqueda de subcadenas
 *
 * Idea: Dada una cadena T y varios patrones P, determinar para cada patrón
 * si aparece como subcadena de T. Se construye un autómata de sufijos de T
 * en tiempo O(|T|). Luego, para cada patrón, se recorre el autómata desde
 * el estado inicial siguiendo las transiciones de sus caracteres. Si en
 * algún momento no existe transición, el patrón no es subcadena; si se
 * consumen todos los caracteres, sí lo es.
 *
 * El autómata se implementa con la estructura clásica:
 *   st[i].len         : longitud de la subcadena más larga del estado i.
 *   st[i].link        : enlace de sufijo.
 *   st[i].next        : transiciones (map<char, int>).
 *
 * La extensión se hace en línea con la función sa_extend(c).
 * Complejidad total: O(|T| + Σ|P|) si se usa arreglo para transiciones,
 * u O(|T| log k + Σ|P| log k) con map, donde k es el tamaño del alfabeto.
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

bool is_substring(const string &s) {
    int v = 0;  
    for (char c : s) {
        if (!st[v].next.count(c)) {
            return false;
        }
        v = st[v].next[c];
    }
    return true;
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

    int k;
    cin >> k;
    while (k--) {
        string pattern;
        cin >> pattern;
        cout << (is_substring(pattern) ? "YES" : "NO") << '\n';
    }
    
    return 0; 
}