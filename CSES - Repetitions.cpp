/**
 * CSES - Repetitions
 * Temática: String + Programación Dinámica
 *
 * Idea: Dada una cadena encontrar la mayor secuencia consecutivas de una misma
 * letra. La idea es tener dos contadores uno total donde quede la respuesta final
 * y otro que cuente las letras, adicionalmente se debe llevar el caracter anterior
 * Si el caracter actual es igual anterior incremento el contador temporal sino
 * dicho contador pasa su valor a 1 por la letra actual es diferente a la anterior
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



int main() {
	OPTIMIZAR_IO
	PRESICION(0)
	string dna;
	int best=0,c=0;
	char last='@';

	cin>>dna;
	for(int i=0;i<dna.size();i++){

		if(last==dna[i])c++;
		else{
			c=1;
		}

		last=dna[i];
		best=max(best,c);
	}
	cout<<best<<ENDL;
	return 0;
}

