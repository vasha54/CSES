/*
* CSES - Maximum Subarray Sum
* Tematica: Busqueda y Ordenamiento
* Idea: Dada una colección de valores buscar el subarreglo que produce la mayor
* suma. Algoritmo clasico para solucionar este problema.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1010
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

struct Cell{
    int r,c;
    Cell(int x=0,int y=0){
        r = x;
        c = y;
    }
};

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int nvalues, answer, sum_partial;
    cin>>nvalues;
    vector<int> values(nvalues+10,0);
    for(int i=1;i<=nvalues;i++) cin>>values[i];
    answer = values[1];
    sum_partial = values[1];
    for(int i=2;i<=nvalues;i++){
        sum_partial = max(sum_partial+values[i],values[i]);
        answer = max(answer,sum_partial);
    }
    cout<<answer<<ENDL;
    return 0;
}
