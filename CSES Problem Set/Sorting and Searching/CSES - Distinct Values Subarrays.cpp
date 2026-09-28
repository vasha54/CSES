/**
 * CSES - Distinct Values Subarrays
 * Temática: Two pointer + Sliding window
 *
 * Idea: Dado un arreglo de N enteros, contar todos los subarreglos contiguos 
 * donde todos los elementos son distintos. Se utiliza una ventana deslizante 
 * implícita con el puntero izquierdo (ptr_left). El arreglo se procesa de 
 * izquierda a derecha manteniendo un mapa last_pos que registra la última 
 * posición de cada valor.
 *
 * Para cada posición i (1‑indexada):
 *   1. Si values[i] ya apareció, se actualiza ptr_left al máximo entre su 
 *      valor actual y la última posición de ese valor: 
 *      ptr_left = max(ptr_left, last_pos[values[i]]).
 *   2. Ahora todos los subarreglos que terminan en i y empiezan en cualquier 
 *      índice entre ptr_left+1 e i son válidos. La cantidad es i - ptr_left.
 *   3. Se acumula al total (nsubarrays).
 *   4. Se guarda last_pos[values[i]] = i.
 *
 * La suma final de (i - ptr_left) para cada i da el número total de 
 * subarreglos con elementos distintos.
 *
 * Complejidad: O(N log N) con std::map, o O(N) esperado con unordered_map.
 * Es correcta para N ≤ 2·10⁵
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

    int nvalues, nsubarrays=0, ptr_left=0;
    cin>>nvalues;
    vector<int> values(nvalues+1);
    map<int,int> last_pos;

    for(int i=1;i<=nvalues;i++) cin>>values[i];

    for(int i=1;i<=nvalues;i++){
        if(last_pos.find(values[i])!=last_pos.end())
            ptr_left = max(ptr_left,last_pos[values[i]]);
        nsubarrays+=(i-ptr_left);
        last_pos[values[i]] = i;
    }

    cout<<nsubarrays<<ENDL;    
    
    return 0;
}