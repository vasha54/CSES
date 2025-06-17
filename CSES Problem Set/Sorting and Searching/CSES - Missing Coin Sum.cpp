/*
* CSES - Missing Coin Sum
* Tematica: Ordenamiento + Greedy
*
* Idea: Necesitamos encontrar el número positivo más pequeño que no se puede 
* formar utilizando cualquier subconjunto de las monedas dadas. El enfoque va ser 
* un greedy que implica ordenar las monedas y luego verificar iterativamente si 
* el siguiente número más pequeño que no se puede formar puede ser extendido por 
* la siguiente moneda en la lista ordenada.
* 
* Las monedas se ordenan para procesarlas en orden ascendente. Esto es esencial 
* porque nos permite verificar sistemáticamente la contribución de cada moneda 
* para formar sumas consecutivas comenzando desde 1.
* 
* Comenzamos con answers establecido en 1, ya que este es el número positivo más 
* pequeño que podemos formar.
* 
* Para cada moneda, si el valor de la moneda es menor o igual a answers, 
* significa que podemos formar todas las sumas desde 1 hasta answers + 
* valor_moneda - 1 al incluir la moneda en los subconjuntos. Por lo tanto, 
* actualizamos answers sumando el valor de la moneda. Si el valor de una moneda 
* excede answers, significa que hay un hueco en answers, que no se puede formar 
* con ninguna combinación de las monedas procesadas hasta ahora, y devolvemos 
* answers inmediatamente.
* 
* Este enfoque goloso es correcto porque aprovecha la propiedad de que las sumas 
* consecutivas se pueden extender de manera incremental cuando las monedas están 
* ordenadas. La detección del primer hueco en las sumas posibles nos da directamente 
* el menor número que no se puede formar, asegurando eficiencia y precisión.
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
	int N, answers = 1;
	cin>>N;
	vector<int> values(N); 
	
	for(int i=0;i<N;i++) cin>>values[i];
	
	sort(values.begin(),values.end());
	
	for(int i=0;i<N && values[i]<=answers;i++) answers+=values[i];
	
	cout<<answers<<ENDL;
	return 0;
}