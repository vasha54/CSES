/*
* CSES - Subarray Sums I
* Tematica: Busqueda
*
* Idea: Se tiene una arreglo de valores y se quiere saber cuantos subarreglos
* existen tal que la suma de los valores del subarreglo sumen X.
* Para solucionar el problema iremos sumando los valores a estas sumas parciales almacenaremos
* en mapa (f) la suma (T) con la ocurrencias de esta en las sumas que generan los valores.
* cada que se suma un nuevo valor comprobamos la cantidad de ocurrencias que existe en
* f[T-X] y dicha cantidad de ocurrencias hasta ese momento se adiciona la la solución final
* La cuestion es que si hasta el valor i tengo una suma total de Ti y en el mapa de sumas
* parciales existe una clave igual Ti-X significa que existe que hasta el valor de la posición
* i existen f[Ti-X] subarreglos cuya suma es igual a X.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MAX_TREE (MAX_N << 2)
#define MID (left+right)/2
#define MOD 1000000007
#define EPS 1e-4
#define INF 0x3f3f3f3f3f3f3f3f
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
using namespace __gnu_pbds;
int mov_r [] = { 0,  0, -1,  1};
int mov_c [] = {-1,  1,  0,  0};
 
int N,X,sumsTotal,answer,v;
map<int,int> sumsPartial;
 
signed main()
{
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>N>>X;
    sumsTotal = 0;
    answer = 0;
    sumsPartial[0] = 1;
    for(int i=0;i<N;i++){
        cin>>v;
        sumsTotal+=v;
        answer+=sumsPartial[sumsTotal-X];
        sumsPartial[sumsTotal]++;
    }
    cout<<answer<<ENDL;
    return 0;
}