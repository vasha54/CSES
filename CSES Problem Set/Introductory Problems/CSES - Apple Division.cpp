/**
 * CSES - Apple Division
 * Temática: Combinatoria : Máscara de bits
 *
 * Idea: Dado un grupo de elementos que no superan los 20 elementos hallar la
 * forma de dividir el grupo en dos grupos tal que la diferencia entre las sumas
 * de los valores de cada grupo sea la minima. Como no superan los 20 elementos
 * podemos generar todas las posibles agrupaciones posibles con la máscara de bit
 * un grupo serian los bits activos y otro sería los bits no activos.
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

	int nelements;
	LL A,B,BEST=0;

	cin>>nelements;
	vector<LL> values(nelements);

	for(int i=0;i<nelements;i++){
		cin>>values[i];
		BEST+=values[i];
	}

	for(int i=0;i<(1<<nelements);i++){
		A=B=0;
		for(int j=0;j<nelements;j++){
			if(i & (1<<j))A+=values[j];
			else B+=values[j];
		}
		BEST=min(BEST,abs(A-B));
	}

	cout<<BEST<<ENDL;
	return 0;
}

