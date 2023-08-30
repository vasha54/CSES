/**
 * CSES - Creating Strings
 * Temática: Combinatoria : Generar todas la permutaciones y permutacion con
 * repetición
 *
 * Idea: Dada una cadena generar todas las posibles permutaciones y calcular dichas
 * cantidad , pueden existir cadenas repetidas. Como la longitud es pequeña se
 * puede aplicar fuerza bruta.
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 85
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

int fact [] ={1,1,2,6,24,120,720,5040,40320},numerador,denominator;

int counting[ALPHABET_SIZE];

string p;

int main() {
	OPTIMIZAR_IO
	PRESICION(0)

	cin>>p;
	fill(counting,counting+ALPHABET_SIZE,0);
	sort(p.begin(),p.end());

	numerador=fact[p.length()];

	for(int i=0;i<p.size();i++){
		counting[p[i]-'a']++;
	}

	denominator=1;
	for(int i=0;i<ALPHABET_SIZE;i++)
		denominator*=fact[counting[i]];

	cout<<numerador/denominator<<ENDL;

	do{
		cout<<p<<ENDL;
	}while(next_permutation(p.begin(),p.end()));

	return 0;
}

