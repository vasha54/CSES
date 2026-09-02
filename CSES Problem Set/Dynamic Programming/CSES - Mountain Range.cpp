/**
 * CSES - Mountain Range
 * Temática: Programación Dinámica + Árbol de Segmentos + Pila Monótona
 * 
 * Idea:  
 * Modelamos los saltos como un DAG. Desde una montaña 'j' se puede saltar a 'i' (más alta) si:
 *  - h[j] < h[i]
 *  - no existe k entre j e i con h[k] > h[i]
 * 
 * Para cada posición i calculamos:
 *  L[i] : índice del primer elemento estrictamente mayor a la izquierda (0 si no existe)
 *  R[i] : índice del primer elemento estrictamente mayor a la derecha (n+1 si no existe)
 * 
 * Entonces, los posibles saltos a i vienen de cualquier j en (L[i], i) o (i, R[i]) con h[j] < h[i].
 * Procesamos las montañas en orden creciente de altura. Para una altura fija, calculamos dp[i] =
 * 1 + máximo dp en esos intervalos (consultando el segment tree). Luego insertamos todos los dp
 * de esa altura en el árbol, para que estén disponibles para alturas mayores.
 * 
 * Complejidad: O(n log n)
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

int rt[MAXTREE];

void build(int idx, int left, int right){
    if(left == right){
        rt[idx] = 0;
    }
    else{
        build(idx*2, left, midle);
        build(idx*2+1, midle+1, right);
        rt[idx] = max(rt[idx*2], rt[idx*2+1]);
    }
}

void update(int idx, int pos, int value, int left, int right){
    if(left == right){
        rt[idx] = value;
    }
    else{
        if(pos <= midle) update(idx*2, pos, value, left, midle);
        else update(idx*2+1, pos, value, midle+1, right);
        rt[idx] = max(rt[idx*2], rt[idx*2+1]);
    }
}

int query(int idx, int l, int r, int left, int right){
    if(r < left || right < l) return 0;
    if(l <= left && right <= r) return rt[idx];
    int ql = 0, qr = 0;
    if(l <= midle) ql = query(idx*2, l, r, left, midle);
    if(midle < r)  qr = query(idx*2+1, l, r, midle+1, right);
    return max(ql, qr);
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int nmountains, height, answer = 0;
    cin >> nmountains;

    vector<int> heights(nmountains + 1);           
    vector<pii> mountains;              
    for(int i = 1; i <= nmountains; i++){
        cin >> height;
        heights[i] = height;
        mountains.push_back({height, i});
    }

    vector<int> left_mountains(nmountains + 1), right_mountains(nmountains + 1);
    vector<int> stackh;

    for(int i = 1; i <= nmountains; i++){
        while(!stackh.empty() && heights[stackh.back()] <= heights[i]){
            stackh.pop_back();
        }
        left_mountains[i] = stackh.empty() ? 0 : stackh.back();
        stackh.push_back(i);
    }

    stackh.clear();

    for(int i = nmountains; i >= 1; i--){
        while(!stackh.empty() && heights[stackh.back()] <= heights[i]){
            stackh.pop_back();
        }
        right_mountains[i] = stackh.empty() ? nmountains + 1 : stackh.back();
        stackh.push_back(i);
    }

    sort(mountains.begin(), mountains.end());

    build(1, 1, nmountains);

    int idx = 0;
    while(idx < nmountains){
        int cur_height = mountains[idx].first;
        vector<int> positions, dp_values;

        while(idx < nmountains && mountains[idx].first == cur_height){
            positions.push_back(mountains[idx].second);
            idx++;
        }

        for(int pos : positions){
            int best = 0;
            int l1 = left_mountains[pos] + 1;
            int r1 = pos - 1;
            if(l1 <= r1) best = max(best, query(1, l1, r1, 1, nmountains));

            int l2 = pos + 1;
            int r2 = right_mountains[pos] - 1;
            if(l2 <= r2) best = max(best, query(1, l2, r2, 1, nmountains));

            int dp = 1 + best;
            dp_values.push_back(dp);
            answer = max(answer, dp);
        }

        for(int j = 0; j < (int)positions.size(); j++){
            update(1, positions[j], dp_values[j], 1, nmountains);
        }
    }

    cout << answer << ENDL;
    return 0;
}