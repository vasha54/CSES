/**
 * CSES - Gray Code
 * Temática: Teoria de Número : Sistema de Numeración
 *
 * Idea: Dado un N imprimir los primeros 2^N numeros de codigo gray en numeros
 * binarios utilizando N bits.
 */
#include <bits/stdc++.h>
#include <math.h>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_INPUT_FILE freopen("Input.txt","r",stdin);
#define MAX_N 1000010
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

int convertGray(int n){
    return n^(n>>1);
}

string convertBinary(int x,int n){
    string binary="";
    while(x>1){
        binary=(x%2==0 ? "0" :"1")+binary;
        x/=2;
    }
    binary=(x%2==0 ? "0" :"1")+binary;
    while(binary.size()<n)
        binary="0"+binary;
    return binary;
}

int main() {
	OPTIMIZAR_IO
	//PRESICION(0)
	//READ_INPUT_FILE
    int N,x;
    string y;
    cin>>N;
    for(int i=0;i<(1<<N);i++){
        x = convertGray(i);
        y = convertBinary(x,N);
        cout<<y<<ENDL;
    }

	return 0;
}
