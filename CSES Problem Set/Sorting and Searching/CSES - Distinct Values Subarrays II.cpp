/**
 * CSES - Distinct Values Subarrays II
 * Temática: Sliding Window / Two Pointers
 *
 * Idea: Dado un arreglo de N enteros y un entero K, contar el número de
 * subarreglos contiguos que contienen como máximo K elementos distintos.
 *
 * Se utiliza una ventana deslizante [l, r] (dos punteros). Para cada extremo
 * derecho r, se mantiene el menor l tal que el subarreglo [l, r] tenga a lo
 * sumo K valores distintos. Esto se logra con un mapa (o hash) de frecuencias
 * y una variable que cuenta los distintos.
 *
 * Al expandir r, se incrementa la frecuencia de a[r]; si es 1 (nuevo), se
 * aumenta el contador de distintos. Mientras distintos > K, se encoge la
 * ventana desde la izquierda: se decrementa la frecuencia de a[l], y si llega
 * a 0 se reduce el contador de distintos; luego l++.
 *
 * En cada paso, la cantidad de subarreglos que terminan en r y cumplen la
 * condición es (r - l + 1). La respuesta total es la suma de estos valores.
 *
 * Complejidad: O(N log N) con std::map, o O(N) esperado con
 * std::unordered_map. Suficiente para N ≤ 2·10⁵.
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


signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int n, k;
    cin >> n >> k;
    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];

    map<int, int> freq;          
    int distinct = 0;            
    int answer = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        freq[values[r]]++;
        if (freq[values[r]] == 1) distinct++; 

        while (distinct > k) {
            freq[values[l]]--;
            if (freq[values[l]] == 0) distinct--;
            l++;
        }

        answer += (r - l + 1);
    }

    cout << answer << ENDL;
    return 0;
    
    return 0;
}