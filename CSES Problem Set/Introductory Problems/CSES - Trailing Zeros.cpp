/**
* CSES - Trailing Zeros
* Tematica : Algebra - Aritmética
* Idea: Dado un valor N se quiere determinar en cuantos ceros termina el factorial
* de N. El factorial de un número N es la multiplicación de todos los números de
* 1 a N los ceros al final serán aportados por los dos y cincos que podamos unir
* en forma de tuplas. Una forma de determinar lo anterior es calcular la siguiente
* expresión floor(N/5^k). Donde k pertenece a los naturales y su valor no supera
* un valor tal que siempre que se cumpla que 5^k <= N. Nos vamos a mover por todas
* las potencias de 5 y veremos cuantas veces divide esa potencia a N en partes
* entera y esa será la cantidad de ceros que aporta esa potencia a la solución
* esto es posible por existará un 2^k que será menor 5^k con los cual haré tuplas
* de 2 y 5 lo que aporta los ceros al final.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 85
#define EPS 1e-9
#define INF 1000000000
#define READ_FILE freopen("Input.txt","r",stdin);

using namespace std;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE

    long long zeros=0,n;
    cin>>n;
    for(long long i=5;i<=n;i*=5){
        zeros+=(n/i);
    }

    cout<<zeros<<ENDL;

    return 0;
}
