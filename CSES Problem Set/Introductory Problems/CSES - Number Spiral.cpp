/*
* CSES - Number Spiral.
* Tematica : Add -Hoc + Aritmetica Algebra
* Idea: Se tiene una grilla de infinitas filas y columnas en el cual se va colocando
* todos los numeros desde 1 hasta N de forma que el 1 se coloca en la celda superior
* izquierda y los siguientes se colocando cubriendo las celdas vecinas de forma que se
* forma la grilla de la siguiente:
*
* +---+---+---+---+---+
* | 1 | 2 | 9 | 10| 25|
* +---+---+---+---+---+
* | 4 | 3 | 8 | 11| 24|
* +---+---+---+---+---+
* | 5 | 6 | 7 | 12| 23|
* +---+---+---+---+---+
* | 16| 15| 14| 13| 22|
* +---+---+---+---+---+
* | 17| 18| 19| 20| 21|
* +---+---+---+---+---+
* Dado el valor de la fila(y) y la columna(x) de la grilla determinar que valor esta
* en esa celda. Si dividimos el problema en 5 casos podemos encontrar las formulas
* para cada caso que hallan el número en esa celdas. Los casos bases son:
* 1. x = y -> y²-(y-1)
* 2. y < x con x mod 2 = 0 -> (x-1)²+y
* 3. y < x con x mod 2 = 1-> x²-(y-1)
* 4. y > x con y mod 2 = 0-> y²-(x-1)
* 5. y > x con y mod 2 = 1-> (y-1)²+x
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

int n,x,y;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>n;
    while(n--){
        cin>>y>>x;
        if(x==y) cout<<y*y-(y-1)<<ENDL;
        else if(x>y && x%2==0) cout<<(x-1)*(x-1)+y<<ENDL;
        else if(x>y && x%2==1) cout<<x*x-(y-1)<<ENDL;
        else if(x<y && y%2==0) cout<<y*y-(x-1)<<ENDL;
        else if(x<y && y%2==1) cout<<(y-1)*(y-1)+x<<ENDL;
    }

    return 0;
}
