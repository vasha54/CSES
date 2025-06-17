/*
* CSES - Sliding Window Sum
    Temática : Sliding Window variante deque
    
    Idea: Dada una lista de valores se quiere calcular la suma de cada sublista 
    de k elementos consecutivos, de izquierda a derecha. y con dichas sumas 
    obtener la operación xor entre dichos valores. Para solucionar el problemas 
    vamos aplicar la técnica de Ventana Deslizante (Sliding Window) con el uso
    de una deque donde vamos almacenar en orden los elementos y generando los
    subarreglos de k elementos y una variable P que llevara la suma de los elementos
    que estan dentro del deque. Cada vez que se procesa un valor de la lista 
    puede pasar lo siguiente:
         - La cantidad de elementos del deque es menor que k por tanto se suma 
        el valor a P y se adiciona al final del deque.
        - La cantidad de elementos en deque es igual k por tanto tengo un subarreglo
        de longitud k por tanto guardo el valor de P en la colección donde se van
        almacenar las sumas de los subarreglos. A P le resto el primer elemento del 
        deque el cual elimino del deque y se repite el proceso de sumar 
        el nuevo valor a P y adicionar al final del deque.
        
    Luego con colección de sumas de los subarreglos podemos aplicar un XOR con 
    todos los elementos
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
	int n,k,a,b,c,sums,xors,x;
	deque<int> windows;
	cin>>n>>k;
    cin>>x>>a>>b>>c;
    
    windows.push_back(x);
    sums = x;
    xors = 0;
    for (int i=0;i<n-1;i++){
        x = (a*x + b) % c;
        if (windows.size() == k){
            xors = xors ^ sums;
			sums -= windows.front();
			windows.pop_front();
		}
        sums+=x;    
		windows.push_back(x);
	}
    xors = xors ^ sums;
    cout<<xors<<ENDL;
	return 0;
}