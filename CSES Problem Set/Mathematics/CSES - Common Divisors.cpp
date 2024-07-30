/*
* CSES - Common Divisors
* Tematica: Cantidad de divisores + Criba + Fuerza bruta
*
* Idea: Básicamente, tenemos que encontrar el divisor más grande que divida al menos 2 números
* que estén en el arreglo inicial. Como todos los valores están en el rango de 1 a 10^6 podemos
* usar una idea de counting sort para contar los números presentes en el rango. Luego buscaremos
* cuya cantidad de multiplos utilizando el counting sean mayor de 2 . Como debemos buscar el mayor
* posible empezaremos por el mayor posible aplicando una criba.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1e6+10
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


signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int n,answer;
    cin>>n;
    vector<int> x(n);
    vector<int> divisors(MAX_N,0);

    for(int i=0;i<n;i++){
        cin>>x[i];
        divisors[x[i]]++;
    }

    for(int i=1e6;i>=1;i--)
    {
        answer=0;
        for(int j=i;j<=1e6;j+=i){
            answer+=divisors[j];
        }
        if(answer>=2){
            cout<<i<<ENDL;
            break;
        }
    }

    return 0;
}
