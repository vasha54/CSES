 /**
 * CSES - Road Construction 
 * Temática: Estructura de Datos + DSU 
 * 
 * Idea: Dada un grupo de ciudades que se van conectando por un grupo
 * de carreteras se quiere saber para cada vez que se añade una nueva
 * carretera la cantidad de grupos de cicudades que están conectadas
 * entre sí y cual grupo tiene mayor cantidad de ciudades.
 *
 * Con simular el proceso con la estructura DSU donde llevemos ambas
 * informaciones actualizasa cada vez que se unan dos componentes
 * distintas.
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
#define MAX_N 100010
#define MOD  1000000007
 
using namespace std;
using namespace __gnu_pbds;

struct DSU{
    vector<int> parent,sizes;
    int ncomponents;
    int maxSize;

    DSU(int n):parent(n+10),sizes(n+10){
        for(int i=0;i<n;i++) sizes[parent[i]=i]=1;
        maxSize = 1;
        ncomponents = n;
    }
    
    int root(int x){
        if(x == parent[x]) return x;
        else{
            parent[x] = root(parent[x]);
            return parent[x];
        }
    }

    void join(int a, int b){
        int x = root(a); 
        int y = root(b);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x,y);
        parent[y] = x;
        sizes[x] += sizes[y];
        ncomponents--;
        maxSize = max(maxSize,sizes[x]);
    }
};

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int ncitys, nroads, x1, x2;
    cin>>ncitys>>nroads;
   
    DSU dsu = DSU(ncitys);
    for(int i=1;i<=nroads;i++){
        cin>>x1>>x2;
        dsu.join(x1,x2);
        cout<<dsu.ncomponents<<" "<<dsu.maxSize<<ENDL;
    }

    return 0;
}

