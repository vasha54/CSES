/*
* CSES - Hamming Distance
* Tematica: Busqueda exhaustiva + Operadores binarios
* Idea: La idea trivial sería comparar cada cadena con cada una de las
* otras para ver cual par tiene menor cantidad de cambios. Esta idea
* tiene un alto costo computacional porque debemos comparar cadenas posición
* posición pero podemos reducir esto si analizamos que las cadenas son representaciones
* de numeros en binario por tanto si convertimos las cadenas a numeros la pregunta
* de las posiciones diferentes se reduce a encontrar la cantidad de bits activo que
* produce el operador XOR entre dos numeros donde cada número representa una cadena.
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
    int nvalues,k;
    cin>>nvalues>>k;
    string binary;
    vector<int> values(nvalues,0);
    for(int i=0;i<nvalues;i++)
    {
        cin>>binary;
        for(int j=0;j<k;j++){
            values[i]+=(binary[j]-'0')*(1LL<<(k-(j+1)));
        }
    }
    for(int i=0;i<nvalues;i++){
        for(int j=i+1;j<nvalues;j++){
            k = min(k,(int)__builtin_popcount(values[i]^values[j]));
        }
    }
    cout<<k<<ENDL;
    return 0;
}
