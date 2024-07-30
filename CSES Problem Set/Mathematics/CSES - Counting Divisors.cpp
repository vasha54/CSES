/*
* CSES - Counting Divisors
* Tematica: Teoría de Numeros + Criba
* Idea: Dada una serie de numeros calcular para cada uno la cantidad de de
* divisores de cada como el maximo valor puede ser 10⁶ vamos a precalcular
* todos los los números en el rango de 1 a 10⁶ con el uso de una criba.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1000010
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
char mov_s [] =  {'L','R','U','D'};



signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    vector<int> divisors(MAX_N,1);
    for(int i=2;i<MAX_N;i++){
        for(int j=i;j<MAX_N;j+=i)
            divisors[j]++;
    }

    int cases,x;
    cin>>cases;
    while(cases--){
        cin>>x;
        cout<<divisors[x]<<ENDL;
    }
    return 0;
}
