/**
 * CSES - Coin Piles
 * Temática: Aritmetica-Algebra : Sistema de Ecuaciones
 *
 * Idea: Se tiene dos pilas concantidades A y B de monedas sobre las pilas se
 * puede realizar dos operaiones:
 * 1. Se extrae 2 monedas de la pila uno y una moneda de la pila dos.
 * 2. Se extrae 1 moneda de la pila uno y dos monedas de la pila dos.
 *
 * Se quiere realizar un grupo de operaciones que permita dejar las pilas sin
 * moneda al mismo tiempo. Podemos modelar la situación con el siguiente sistema
 * de ecuaciones.
 *
 * Pila I  2x +  y = A
 * Pila II  x + 2y = B
 *
 * Donde x sería la cantida de operaciones de tipo 1, mientras y sería la cantidad
 * de operaciones de tipo 2. Una vez realizado el sistema de ecuaciones solo debemos
 * verificar que x, y pertenezcan al dominio de los naurales.
 */
#include <bits/stdc++.h>
#include <math.h>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_INPUT_FILE freopen("Input.txt","r",stdin);
#define MAX_N 1000010
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;



int main() {
	OPTIMIZAR_IO
	//PRESICION(0)
	//READ_INPUT_FILE
    int cases;
    LL A,B,y1,x1,y2,x2;
    cin>>cases;
    while(cases--){
        cin>>A>>B;
        y1=(2*B-A)/3;
        x1=B-2*y1;

        x2=(2*A-B)/3;
        y2=A-2*x2;

        bool s1 = ( (2*B-A)%3==0 && x1>=0 && y1>=0 );
        bool s2 = ( (2*A-B)%3==0 && x2>=0 && y2>=0 );

        cout<<( (s1 || s2) ? "YES": "NO" )<<ENDL;
    }
	return 0;
}
