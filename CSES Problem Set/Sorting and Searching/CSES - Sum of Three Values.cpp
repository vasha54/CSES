/**
 * CSES - Sum of Three Values
 * Temática: Busqueda + Ordenamiento +  Two punteros
 * 
 * Idea: Dada una colección de valores buscar si existe tres valores de la colección sumen un valor 
 * dado. Ordenamos los valores  aplicamos la idea de los dos punteros siempre fijando un tercer 
 * puntero 
 */ 
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 5*10000010
 
using namespace std;
using namespace __gnu_pbds;

vector<pair<int,int>> values;
int n,x,a,b,e;
bool exist_three;

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    cin>>n>>x;
    REP(n)
    {
        cin>>a;
        values.push_back(make_pair(a,i));
    }
    sort(values.begin(),values.end());
    exist_three = false;
    for(int i=0;i<n && !exist_three; i++)
    {
        a = x - values[i].first;
        b = i+1;
        e = n-1;
        while(b<e && !exist_three)
        {
            if(a == values[b].first + values[e].first)
            {
                cout<<values[i].second<<" "<<values[b].second<<" "<<values[e].second<<ENDL;
                exist_three = true;
            }
            else if(a < values[b].first + values[e].first)
            {
                e--;
            }
            else
            {
                b++;
            }
        }
    }
    if(!exist_three) puts("IMPOSSIBLE");    
    return 0;
}
