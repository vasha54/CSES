/*
* CSES - Stick Lengths
* Tematica: Ordenamiento + Mediana
*
* Idea: Dada una colección de valores se quiere llevar todos los valores a un 
* mismo valor de tal forma que la suma de operaciones sea mínima llevar un valor
* a otro valor será igual a la diferencia entre valor actual y el valor nuevo.
* 
* Para encontrar a ese nuevo valor al cual llevaremos todos los valores tal que
* minimice el costo solo basta con encontrar la mediana de la colección de los
* valores  ese será el valor al que llevaremos el resto de los valores.
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
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 1000010
#define MAX_TREE (MAX_N << 2)
#define MOD  10000
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
#define mid (l+r)/2
 
const int ROW_SPARSE_TABLE = floor(log2(MAX_N) +1 );
 
using namespace std;
using namespace __gnu_pbds;
 
signed main()
{
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
	int nstick, median, cost;
	cin>>nstick;
	vector<int> sticks(nstick);
	for(int i=0;i<nstick;i++) cin>>sticks[i];
	sort(sticks.begin(),sticks.end());
	median = nstick/2;
	cost = 0;
	for(int i=0;i<nstick;i++)cost+=abs(sticks[i]-sticks[median]);
	cout<<cost<<ENDL;
    return 0;
}