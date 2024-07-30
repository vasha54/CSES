/*
* CSES - Coin Combinations II
* Tematica: Programación Dinamica + Coin Change
* Idea: Dado un valor  y las denominaciones de monedas contar las formas
* diferentes que se pueden devolver el valor. Dos formas se consideran
* diferentes si al menos existe una denominación de moneda diferente
* Vamos aplicar el algoritmo coin change que permite calcular las formas. 
* Existe una guía de aprendizaje para este tema. Les recomiendo que se lea 
* primero la guía.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MOD 1000000007
#define EPS 1e-4
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE ' '
#define PRINT_LINE cout<<ENDL;
using namespace std;


signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    /*
    Declaración de la variables que almacena la cantidad de monedas, el valor a devolver y 
    las denominación de monedas
    */
    int ncoins, x, coin;
    // Leo la cantidad de denomminaciones de monedas y el valor a devolver
    cin>>ncoins>>x;
    /* Declaro un vector donde el posición i voy almacenar la cantidad de 
    forma de devolver el valor i usando la denominaciones de billetes
    Si despues de ejecutar ways[56] su valor es 19 y ways[23] es 0 significa
    que para el valor 56 existen 19 forma de devolver el valor 56 utilizando
    la denominaciones mientras para el valor 23 no existe forma.
    */
    vector<int> ways(x+1,0);
    /*De cuantas formas puedo devolver el valor 0 pues de unica forma 
    no de le doy nada y listo ahí tiene la UNICA FORMA para el valor 
    0*/
    ways[0]=1;
    // Comienzo a leer cada denominacion de monedas
    for(int i=1;i<=ncoins;i++)
    {
        //Leo la denonimación de la menoda digamos que en esta iteración el valor es 7
        cin>>coin;
        /*Recorro todos los valores de 7 a x porque son los posibles valores donde pudiera utilizar
        la moneda de valor 7. Ahora el analisis que se hace en cada iteración es la siguiente para cuando:
        Valor j    
          7      Si al valor 7 le quito 7 me queda 0 por tanto a la cantidad de devolver 7 (ways[j] ) le voy a sumar la 
                 cantidades de devolver 0 (ways[j-coin] )porque si al valor 0 le adiciono una moneda de valor 7 seria una nueva
                 forma de obtener el valor 7.

          8     Si al valor 8 le quito 7 me queda 1 por tanto a la cantidad de devolver 8 (ways[j] ) le voy a sumar la 
                 cantidades de devolver 1 (ways[j-coin] )porque si al valor 1 le adiciono una moneda de valor 7 seria una nueva
                 forma de obtener el valor 8.
          9     Si al valor 7 le quito 7 me queda 2 por tanto a la cantidad de devolver 9 (ways[j] ) le voy a sumar la 
                 cantidades de devolver 2 (ways[j-coin] )porque si al valor 2 le adiciono una moneda de valor 7 seria una nueva
                 forma de obtener el valor 9.
         ...    ...
         x-2   Si al valor x-2 le quito 7 me queda x-9 por tanto a la cantidad de devolver x-2 (ways[j] ) le voy a sumar la 
                 cantidades de devolver x-9 (ways[j-coin] )porque si al valor x-9 le adiciono una moneda de valor 7 seria una nueva
                 forma de obtener el valor x-2.
         x-1    Si al valor x-2 le quito 7 me queda x-8 por tanto a la cantidad de devolver x-1 (ways[j] ) le voy a sumar la 
                 cantidades de devolver x-8 (ways[j-coin] )porque si al valor x-8 le adiciono una moneda de valor 7 seria una nueva
                 forma de obtener el valor x-1.
          x     Si al valor x le quito 7 me queda x-7 por tanto a la cantidad de devolver x (ways[j] ) le voy a sumar la 
                 cantidades de devolver x-7 (ways[j-coin] )porque si al valor x-7 le adiciono una moneda de valor 7 seria una nueva
                 forma de obtener el valor x.
        Como el final hay que que modular porque se puede desbordar el tipo de dato vamos modulando las operaciones y calculos intermadios
        */
        for(int j=coin;j<=x;j++){
            ways[j]=(ways[j]+ways[j-coin])% MOD;
        }
    }
    //Imprimo la cantidad formas de devolver x ya modulada.
    cout<<ways[x]<<ENDL;
    return 0;
}
