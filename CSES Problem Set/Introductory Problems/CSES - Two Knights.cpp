/**
* CSES - Two Knights
* Tematica : Algebra - Aritmética
* Idea: Una forma de abordar este problema requiere que encontremos el número
* total de formas de colocar dos caballeros en el tablero y restar el número de
* formas distintas de colocar dos caballeros para que se ataquen entre sí.
*
* En primer lugar debemos averiguar cuántas formas hay de colocar dos caballos
* en el tablero. Dado que el primer caballo se puede colocar en cualquier lugar
* del tablero (k^2 posiciones) y el segundo caballo en cualquier otro lugar
* (k^2 - 1 posiciones), entonces podemos formular la siguiente expresión.
* Dividimos por dos ya que los caballeros son indistinguibles y queremos eliminar
* casos duplicados en los que se intercambian las posiciones de los caballeros.
*
* Ahora, todo lo que tenemos que averiguar es cuántas de estas posiciones ponen
* a ambos caballeros bajo ataque. Como sabemos hay ocho configuraciones de ataque
* diferentes que puede realizar un caballero.
*
* Como el tablero es un cuadrado, podemos deducir que hay el mismo número de
* posiciones de ataque para cada una de las ocho configuraciones. Entonces la
* última pregunta que queda es cuantas maneras hay de colocar cada una de las
* configuraciones en un tablero k×k y dado que un ataque ocupa un bloque de
* dimensiones 2×3 (y viceversa) entonces tenemos (k-1) ×(k-2) formas de colocar
* el bloque de 2×3 en el tablero. Para obtener el número total de posiciones de
* ataque distintas, multiplicamos este valor por ocho y lo dividimos por 2 para
* eliminar los duplicados.
*
* El último paso es restar la cantidad total de posiciones de ataque del número
* total de formas de colocar 2 caballeros en el tablero y obtendremos nuestra
* respuesta. La siguiente expresión representa la respuesta:
*  k²(k²-1)/2 - 4(k-2)(k-1)
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
#define int long long

using namespace std;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    int n;
    cin>>n;
    cout<<0<<ENDL;
    for(int i=2;i<=n;i++)
        cout<<(i*i)*(i*i-1)/2-4*(i-2)*(i-1)<<ENDL;
    return 0;
}
