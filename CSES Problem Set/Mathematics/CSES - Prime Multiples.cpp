/*
* CSES - Prime Multiples
* Tematica: Principio de inclusion-exclusion + Mascaras de bits;
*
* Idea: Dado un valor N y k numeros primos diferentes buscar la cantidad de numeros
* de 1 a N que al  menos son multiplos de al menos uno de los k primos. Como k es <=20
* podemos generar una mascara de bits para aplicar el principio de inclusión exclusion
* Para cada posibles máscara debemos llevar la cantidad de primos que participan en ella
* y la multiplicación de todos ellos para entonces:
* - Si la cantidad de primos es impar en la máscara a la solución final hay que sumarle
* n/mul donde mul es la multiplicación de todos los primos presentes en la máscara.
* - Si la cantidad de primos es impar en la máscara a la solución final hay que sustraerle
* n/mul donde mul es la multiplicación de todos los primos presentes en la máscara.
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
    int n, k, answer=0,mul;
    cin>>n>>k;
    answer = n;
    vector<int> primes(k);
    for(int i=0;i<k;i++) cin>>primes[i];

    double RHS = log(n) + EPS;
    for(int mask=0;mask<(1<<k);mask++)
    {
        bool odd = (__builtin_popcount(mask)&1);
        mul = 1;
        double LHS = 0.0;
        for(int j =0;j<k;j++)
        {
            if(mask & (1<<j))
            {
                LHS += log(primes[j]);
                mul*=primes[j];
            }
        }
        if(LHS < RHS)
            answer += (odd ? 1 : -1) * (n/mul);
    }

    cout<<answer<<ENDL;
    return 0;
}
