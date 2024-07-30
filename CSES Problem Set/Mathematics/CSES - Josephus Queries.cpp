/*
* CSES - Josephus Queries
* Tematica: Matemática + Recursividad
* Se tiene un grupo de niños en forma de circulo enumerados de 1 a n, donde el
* niño n esta al lado del niño 1 . Se comienza a contar a partir del niño 1 y
* cada 2 níno se saca al niño del círculo dada N niños y K operaciones cual
* el es el niño seleccionado en la K operacion.
*
* La idea es utilizar una función recursiva, digamos findKthChild(), para resolver el problema.
* Caso base: si solo queda un chico, ese chico es el que se eliminará.
* Caso recursivo: si el número redondeado K es menor o igual a la mitad del número total de chicos,
* entonces calcula qué chico se eliminará en esa ronda.
* Si K es más de la mitad del número total de chicos, llama a la función recursivamente
* con la mitad del número total de chicos y ajusta K en consecuencia.
*
*
* Pasos para resolver este problema:
* Caso base:
*    Si solo hay un niño (N == 1), devuelve 1, ya que ese chico es el que se eliminará.
* Si K es menor o igual que la mitad del número total de chicos:
*   Si duplicar K supera el número total de chicos,
*    devuelve el resto de 2 * K dividido por el número total de chicos (N).
*    de lo contrario, devuelve 2 * K.
* Si K es mayor que la mitad del número total de chicos:
*   Calcula de forma recursiva el K chico que se eliminará para la mitad del número total de hijos y almacénalo en temp.
*   Si el número total de hijos es impar, devuelve 2 * temp + 1.
*   De lo contrario, devuelve 2 * temp – 1.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 200010
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
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
#define CELL_FREE '.'
#define CELL_WALL '#'
#define PRINT_LINE cout<<ENDL;
using namespace std;
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};

int findKthChild(int N, int K){
    if (N == 1) return 1;
    if (K <= (N + 1) / 2)
    {
        if (2 * K > N) return (2 * K) % N;
        else return 2 * K;
    }
    int temp = findKthChild( N / 2, K - (N + 1) / 2);
    if (N % 2 == 1)
        return 2 * temp + 1;
    return 2 * temp - 1;
}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int cases,k,n;
    cin>>cases;
    while(cases--){
        cin>>n>>k;
        cout<<findKthChild(n,k)<<ENDL;
    }
    return 0;
}
